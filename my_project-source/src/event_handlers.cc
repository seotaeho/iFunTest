// PLEASE ADD YOUR EVENT HANDLER DECLARATIONS HERE.

#include "event_handlers.h"

#include <funapi.h>
#include <glog/logging.h>

#include "my_project_loggers.h"
#include "my_project_messages.pb.h"


namespace my_project {

////////////////////////////////////////////////////////////////////////////////
// Session open/close handlers
////////////////////////////////////////////////////////////////////////////////

void OnSessionOpened(const Ptr<Session> &session) {
  logger::SessionOpened(to_string(session->id()), WallClock::Now());
}


void OnSessionClosed(const Ptr<Session> &session, SessionCloseReason reason) {
  logger::SessionClosed(to_string(session->id()), WallClock::Now());

  if (reason == kClosedForServerDid) {
    // Server has called session->Close().
  } else if (reason == kClosedForIdle) {
    // The session has been idle for long time.
  } else if (reason == kClosedForUnknownSessionId) {
    // The session was invalid.
  }
}



////////////////////////////////////////////////////////////////////////////////
// Client message handlers.
//
// (Just for your reference. Please replace with your own.)
////////////////////////////////////////////////////////////////////////////////

void OnAccountLogin(const Ptr<Session> &session, const Json &message) {
  // Thank to a JSON schema we specified registering a handler,
  // we are guaranteed that the passsed "message" is in the following form.
  //
  //   {"facebook_uid":"xxx", "facebook_access_token":"xxx"}
  //
  // So no more validation is necessary.
  string fb_uid = message["facebook_uid"].GetString();
  string fb_access_token = message["facebook_access_token"].GetString();

  // Below shows how to initiate Facebook authentication.
  AuthenticationKey fb_auth_key = MakeFacebookAuthenticationKey(fb_access_token);

  AccountAuthenticationRequest request("Facebook", fb_uid, fb_auth_key);
  AccountAuthenticationResponse response;
  if (not AuthenticateSync(request, &response)) {
    // system error
    LOG(ERROR) << "authentication system error";
    return;
  }

  if (response.success) {
    // login success
    LOG(INFO) << "login success";

    // You can have the Engine manage logged-in accounts through "AccountManager".
    AccountManager::CheckAndSetLoggedIn(fb_uid, session);

    // We also leave a player activity log.
    // This log can be used when you need to do customer services.
    // To customize an activity log, please refer to the reference manual.
    logger::PlayerLoggedIn(to_string(session->id()), fb_uid, WallClock::Now());

  } else {
    // login failure
    LOG(INFO) << "login failure";

  }
}


void OnEchoMessage(const Ptr<Session> &session, const Json &message) {
  // Since we have not specified a JSON schema for "echo" below,
  // the passed "message" may have malformed data.
  // We should manually validate it before use.
  //
  // Assuming "echo" is in the form below:
  //
  //   {"message":"xxx"}

  static const char *kMessage = "message";

  if (not message.HasAttribute(kMessage)) {
    LOG(ERROR) << "Invalid message";
    return;
  }

  if (not message[kMessage].IsString()) {
    LOG(ERROR) << "Invalid message";
    return;
  }

  // OK. The message looks good.
  string message_from_client = message["message"].GetString();

  // We sends the content back to the client.
  Json response;
  response[kMessage] = message_from_client;
  session->SendMessage("echo", response);

  LOG(INFO) << "message: " << message_from_client;
}


void OnPbufEchoMessage(const Ptr<Session> &session, const Ptr<FunMessage> &message) {
  // This is a Google protocol buffer example.
  // Engine invokes the handler only when the "message" is legitimate.
  // So, we do not have to check "required" fields.
  // But it's your responsibility to make sure required "optional" fields exist.


  // Every client-server protobuf message must extend "FunMessage".
  // Please see my_project_messages.proto.
  //
  // In this example,
  //   message PbufEchoMessage {
  //     required string msg = 1;
  //   }
  //
  //   extend FunMessage {
  //     potional PbufEchoMessage pbuf_echo = 16;
  //   }
  if (not message->HasExtension(pbuf_echo)) {
    LOG(ERROR) << "Invalid message";
    return;
  }
  const PbufEchoMessage &pbuf_message = message->GetExtension(pbuf_echo);
  const string &msg = pbuf_message.msg();
  LOG(INFO) << "pbuf message: " << msg;

  // Constructs a response message.
  Ptr<FunMessage> response(new FunMessage);
  PbufEchoMessage *echo_response = response->MutableExtension(pbuf_echo);
  echo_response->set_msg(msg);

  // Wires the message.
  session->SendMessage("pbuf_echo", response);
}



////////////////////////////////////////////////////////////////////////////////
// Timer handler.
//
// (Just for your reference. Please replace with your own.)
////////////////////////////////////////////////////////////////////////////////

void OnTick(const Timer::Id &timer_id, const WallClock::Value &clock) {
  // PLACE HERE YOUR TICK HANDLER CODE.
}


	void OnHello(const Ptr<Session> &session, const Json &message) {
		
		string character_name = message["character_name"].GetString();
		string music_id = message["music_id"].GetString();		
		string music_title = message["music_title"].GetString();		
		LOG(INFO) << "chracter name : " << character_name;

		  // 전달받은 character_name 으로 캐릭터를 생성합니다.
		Ptr<Character> ch = Character::Create(character_name);

		Json response;

		if (ch) {
		  // 캐릭터가 생성되었습니다.
		  // 기본 캐릭터의 설정을 입력하고, 덤으로 초보자용 칼 하나를 인벤토리에 추가합니다.
			response["result"] = true;
			ch->SetLevel(1);
			ch->SetHp(100);
			ch->SetMp(100);
			ch->SetExp(0);
						
			Ptr<Music2> music = Music2::Create(music_id);
			if (music)
			{
				music->SetMusicTitle(music_title);
			}
			else
			{
				response["result"] = false;
				response["reason"] = music_id + " cannot insert";
			}
			
			Ptr<Album> album = Album::Create(music_id);
			if (album)
			{
				album->SetAlbumTitle(music_title);
			}
			else
			{
				response["result"] = false;
				response["reason"] = music_id + " cannot insert";
			}
			
		}
		else {
		  // 같은 이름의 캐릭터가 있어서 생성되지 않았습니다.
			response["result"] = false;
			response["reason"] = character_name + " already exists";
		}
		


		session->SendMessage("create_character", response);
		/*
		Ptr<Music> ch = Music::Create(1);
		if (ch)
		{
			response["result"] = true;
			ch->SetMusictitle("aa");
		}
		else
		{
			response["result"] = false;
		}	*/		
	}

////////////////////////////////////////////////////////////////////////////////
// Extend the function below with your handlers.
////////////////////////////////////////////////////////////////////////////////

void RegisterEventHandlers() {
  /*
   * Registers handlers for session close/open events.
   */
  {
    HandlerRegistry::Install2(OnSessionOpened, OnSessionClosed);
  }


  /*
   * Registers handlers for messages from the client.
   *
   * Handlers below are just for you reference.
   * Feel free to delete them and replace with your own.
   */
  {
    // 1. Registering a JSON message named "login" with its JSON schema.
    //    With json schema, Engine validates input messages in JSON.
    //    before entering a handler.
    //    You can specify a JSON schema like below, or you can also use
    //    auxiliary files in src/json_protocols directory.
    JsonSchema login_msg(JsonSchema::kObject,
        JsonSchema("facebook_uid", JsonSchema::kString, true),
        JsonSchema("facebook_access_token", JsonSchema::kString, true));

    HandlerRegistry::Register("login", OnAccountLogin, login_msg);

    // 2. Another JSON message example.
    //    In this time, we skipped a JSON schema.
    //    So no validation will be performed.
	  HandlerRegistry::Register("hello", OnHello);


    // 3. Registering a Google Protobuf message handler.
    //    Protobuf itself provides a validation using the "required" keyword.
    HandlerRegistry::Register2("pbuf_echo", OnPbufEchoMessage);


    /////////////////////////////////////////////
    // PLACE YOUR CLIENT MESSAGE HANDLER HERE. //
    /////////////////////////////////////////////

  }


  /*
   * Registers a timer.
   *
   * Below demonstrates a repeating timer. One-shot timer is also available.
   * Please see the Timer class.
   */
  {
    Timer::ExpireRepeatedly(boost::posix_time::seconds(1), my_project::OnTick);
  }
}

}  // namespace my_project
