// Copyright (C) 2013-2015 iFunFactory Inc. All Rights Reserved.
//
// This work is confidential and proprietary to iFunFactory Inc. and
// must not be used, disclosed, copied, or distributed without the prior
// consent of iFunFactory Inc.

// THIS FILE WAS AUTOMATICALLY GENERATED. DO NOT EDIT.


#include "../my_project_object.h"

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/assign.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/unordered_map.hpp>
#include <funapi.h>
#include <glog/logging.h>

#include <ctime>
#include <functional>
#include <map>


namespace my_project {

using fun::ApiService;
using fun::string;


template<typename ObjectType, typename AttributeType>
bool CompareAttribute(const Ptr<ObjectType> &object, const AttributeType &value, const function<AttributeType(const Ptr<ObjectType> &)> &attribute_getter, MatchCondition cond) {
  if (not object) {
    return false;
  }

  if (cond == kEqual) {
    return value == attribute_getter(object);
  } else if (cond == kLess) {
    return value > attribute_getter(object);
  } else if (cond == kGreater) {
    return value < attribute_getter(object);
  }
  BOOST_ASSERT(false);
  return false;
}


template<typename ObjectType, typename AttributeType>
bool CompareAttribute2(const Ptr<ObjectType> &object, const function<bool(const AttributeType &)> &match, const function<AttributeType(const Ptr<ObjectType> &)> &attribute_getter) {
  if (not object) {
    return false;
  }
  return match(attribute_getter(object));
}


template <>
bool ArrayRef<bool>::GetAt(size_t index) const {
  return owner_->GetArrayElementBoolean(attribute_name_, index);
}


template <>
int64_t ArrayRef<int64_t>::GetAt(size_t index) const {
  return owner_->GetArrayElementInteger(attribute_name_, index);
}


template <>
double ArrayRef<double>::GetAt(size_t index) const {
  return owner_->GetArrayElementDouble(attribute_name_, index);
}


template <>
string ArrayRef<string>::GetAt(size_t index) const {
  return owner_->GetArrayElementString(attribute_name_, index);
}


template <>
Object::Id ArrayRef<Object::Id>::GetAt(size_t index) const {
  return owner_->GetArrayElementObject(attribute_name_, index);
}


template <>
Ptr<Album> ArrayRef<Ptr<Album> >::GetAt(size_t index) const {
  const Object::Id &object_id = owner_->GetArrayElementObject(attribute_name_, index);
  if (object_id == Object::kNullId) {
    return Album::kNullPtr;
  }
  return Album::Fetch(object_id);
}


template <>
Ptr<Pet> ArrayRef<Ptr<Pet> >::GetAt(size_t index) const {
  const Object::Id &object_id = owner_->GetArrayElementObject(attribute_name_, index);
  if (object_id == Object::kNullId) {
    return Pet::kNullPtr;
  }
  return Pet::Fetch(object_id);
}


template <>
Ptr<Character> ArrayRef<Ptr<Character> >::GetAt(size_t index) const {
  const Object::Id &object_id = owner_->GetArrayElementObject(attribute_name_, index);
  if (object_id == Object::kNullId) {
    return Character::kNullPtr;
  }
  return Character::Fetch(object_id);
}


template <>
Ptr<User> ArrayRef<Ptr<User> >::GetAt(size_t index) const {
  const Object::Id &object_id = owner_->GetArrayElementObject(attribute_name_, index);
  if (object_id == Object::kNullId) {
    return User::kNullPtr;
  }
  return User::Fetch(object_id);
}


template <>
Ptr<Music2> ArrayRef<Ptr<Music2> >::GetAt(size_t index) const {
  const Object::Id &object_id = owner_->GetArrayElementObject(attribute_name_, index);
  if (object_id == Object::kNullId) {
    return Music2::kNullPtr;
  }
  return Music2::Fetch(object_id);
}


template <>
void ArrayRef<bool>::SetAt(size_t index, const bool &value) {
  owner_->SetArrayElementBoolean(attribute_name_, index, value);
}


template <>
void ArrayRef<int64_t>::SetAt(size_t index, const int64_t &value) {
  owner_->SetArrayElementInteger(attribute_name_, index, value);
}


template <>
void ArrayRef<double>::SetAt(size_t index, const double &value) {
  owner_->SetArrayElementDouble(attribute_name_, index, value);
}


template <>
void ArrayRef<string>::SetAt(size_t index, const string &value) {
  owner_->SetArrayElementString(attribute_name_, index, value);
}


template <>
void ArrayRef<Object::Id>::SetAt(size_t index, const Object::Id &value) {
  owner_->SetArrayElementObject(attribute_name_, index, value);
}


template <>
void ArrayRef<Ptr<Album> >::SetAt(size_t index, const Ptr<Album> &value) {
  if (value) {
    owner_->SetArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->SetArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
void ArrayRef<Ptr<Pet> >::SetAt(size_t index, const Ptr<Pet> &value) {
  if (value) {
    owner_->SetArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->SetArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
void ArrayRef<Ptr<Character> >::SetAt(size_t index, const Ptr<Character> &value) {
  if (value) {
    owner_->SetArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->SetArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
void ArrayRef<Ptr<User> >::SetAt(size_t index, const Ptr<User> &value) {
  if (value) {
    owner_->SetArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->SetArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
void ArrayRef<Ptr<Music2> >::SetAt(size_t index, const Ptr<Music2> &value) {
  if (value) {
    owner_->SetArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->SetArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
void ArrayRef<bool>::InsertAt(size_t index, const bool &value) {
  owner_->InsertArrayElementBoolean(attribute_name_, index, value);
}


template <>
void ArrayRef<int64_t>::InsertAt(size_t index, const int64_t &value) {
  owner_->InsertArrayElementInteger(attribute_name_, index, value);
}


template <>
void ArrayRef<double>::InsertAt(size_t index, const double &value) {
  owner_->InsertArrayElementDouble(attribute_name_, index, value);
}


template <>
void ArrayRef<string>::InsertAt(size_t index, const string &value) {
  owner_->InsertArrayElementString(attribute_name_, index, value);
}


template <>
void ArrayRef<Object::Id>::InsertAt(size_t index, const Object::Id &value) {
  owner_->InsertArrayElementObject(attribute_name_, index, value);
}


template <>
void ArrayRef<Ptr<Album> >::InsertAt(size_t index, const Ptr<Album> &value) {
  if (value) {
    owner_->InsertArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->InsertArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
void ArrayRef<Ptr<Pet> >::InsertAt(size_t index, const Ptr<Pet> &value) {
  if (value) {
    owner_->InsertArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->InsertArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
void ArrayRef<Ptr<Character> >::InsertAt(size_t index, const Ptr<Character> &value) {
  if (value) {
    owner_->InsertArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->InsertArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
void ArrayRef<Ptr<User> >::InsertAt(size_t index, const Ptr<User> &value) {
  if (value) {
    owner_->InsertArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->InsertArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
void ArrayRef<Ptr<Music2> >::InsertAt(size_t index, const Ptr<Music2> &value) {
  if (value) {
    owner_->InsertArrayElementObject(attribute_name_, index, value->Id());
  } else {
    owner_->InsertArrayElementObject(attribute_name_, index, Object::kNullId);
  }
}


template <>
bool ArrayRef<bool>::Front() const {
  return GetAt(0);
}


template <>
int64_t ArrayRef<int64_t>::Front() const {
  return GetAt(0);
}


template <>
double ArrayRef<double>::Front() const {
  return GetAt(0);
}


template <>
string ArrayRef<string>::Front() const {
  return GetAt(0);
}


template <>
Object::Id ArrayRef<Object::Id>::Front() const {
  return GetAt(0);
}


template <>
Ptr<Album> ArrayRef<Ptr<Album> >::Front() const {
  return GetAt(0);
}


template <>
Ptr<Pet> ArrayRef<Ptr<Pet> >::Front() const {
  return GetAt(0);
}


template <>
Ptr<Character> ArrayRef<Ptr<Character> >::Front() const {
  return GetAt(0);
}


template <>
Ptr<User> ArrayRef<Ptr<User> >::Front() const {
  return GetAt(0);
}


template <>
Ptr<Music2> ArrayRef<Ptr<Music2> >::Front() const {
  return GetAt(0);
}


template <>
bool ArrayRef<bool>::Back() const {
  return GetAt(Size() - 1);
}


template <>
int64_t ArrayRef<int64_t>::Back() const {
  return GetAt(Size() - 1);
}


template <>
double ArrayRef<double>::Back() const {
  return GetAt(Size() - 1);
}


template <>
string ArrayRef<string>::Back() const {
  return GetAt(Size() - 1);
}


template <>
Object::Id ArrayRef<Object::Id>::Back() const {
  return GetAt(Size() - 1);
}


template <>
Ptr<Album> ArrayRef<Ptr<Album> >::Back() const {
  return GetAt(Size() - 1);
}


template <>
Ptr<Pet> ArrayRef<Ptr<Pet> >::Back() const {
  return GetAt(Size() - 1);
}


template <>
Ptr<Character> ArrayRef<Ptr<Character> >::Back() const {
  return GetAt(Size() - 1);
}


template <>
Ptr<User> ArrayRef<Ptr<User> >::Back() const {
  return GetAt(Size() - 1);
}


template <>
Ptr<Music2> ArrayRef<Ptr<Music2> >::Back() const {
  return GetAt(Size() - 1);
}


template <>
void ArrayRef<bool>::PushFront(const bool &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<int64_t>::PushFront(const int64_t &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<double>::PushFront(const double &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<string>::PushFront(const string &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<Object::Id>::PushFront(const Object::Id &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<Ptr<Album> >::PushFront(const Ptr<Album> &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<Ptr<Pet> >::PushFront(const Ptr<Pet> &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<Ptr<Character> >::PushFront(const Ptr<Character> &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<Ptr<User> >::PushFront(const Ptr<User> &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<Ptr<Music2> >::PushFront(const Ptr<Music2> &value) {
  InsertAt(0, value);
}


template <>
void ArrayRef<bool>::PushBack(const bool &value) {
  InsertAt(Size(), value);
}


template <>
void ArrayRef<int64_t>::PushBack(const int64_t &value) {
  InsertAt(Size(), value);
}


template <>
void ArrayRef<double>::PushBack(const double &value) {
  InsertAt(Size(), value);
}


template <>
void ArrayRef<string>::PushBack(const string &value) {
  InsertAt(Size(), value);
}


template <>
void ArrayRef<Object::Id>::PushBack(const Object::Id &value) {
  InsertAt(Size(), value);
}


template <>
void ArrayRef<Ptr<Album> >::PushBack(const Ptr<Album> &value) {
  InsertAt(Size(), value);
}


template <>
void ArrayRef<Ptr<Pet> >::PushBack(const Ptr<Pet> &value) {
  InsertAt(Size(), value);
}


template <>
void ArrayRef<Ptr<Character> >::PushBack(const Ptr<Character> &value) {
  InsertAt(Size(), value);
}


template <>
void ArrayRef<Ptr<User> >::PushBack(const Ptr<User> &value) {
  InsertAt(Size(), value);
}


template <>
void ArrayRef<Ptr<Music2> >::PushBack(const Ptr<Music2> &value) {
  InsertAt(Size(), value);
}


struct Album::OpaqueData {
  OpaqueData() {
  }

  string album_title;
};


struct Pet::OpaqueData {
  OpaqueData() {
    pet_life = 0;
    pet_code = 0;
  }

  int64_t pet_life;
  int64_t pet_code;
};


struct Character::OpaqueData {
  OpaqueData() {
    exp = 0;
    level = 0;
    hp = 0;
    mp = 0;
    durability = 0;
  }

  int64_t exp;
  int64_t level;
  int64_t hp;
  int64_t mp;
  int64_t durability;
};


struct User::OpaqueData {
  OpaqueData() {
  }

  Ptr<Character::OpaqueData> my_character;
};


struct Music2::OpaqueData {
  OpaqueData() {
  }

  string music_title;
};


DEFINE_CLASS_PTR(Album);


function<bool(const Ptr<Album> &)> Album::MatchByObjectId(const Object::Id &object_id) {
  function<Object::Id(const Ptr<Album> &)> obj_id_getter = bind(&Album::Id, _1);
  return bind(&CompareAttribute<Album, Object::Id>, _1, object_id, obj_id_getter, kEqual);
}


function<bool(const Ptr<Album> &)> Album::MatchByAlbumID(const string &albumid, MatchCondition cond) {
  function<string(const Ptr<Album> &)> attribute_getter = bind(&Album::GetAlbumID, _1);
  return bind(&CompareAttribute<Album, string>, _1, albumid, attribute_getter, cond);
}


function<bool(const Ptr<Album> &)> Album::MatchByAlbumTitle(const string &album_title, MatchCondition cond) {
  function<string(const Ptr<Album> &)> attribute_getter = bind(&Album::GetAlbumTitle, _1);
  return bind(&CompareAttribute<Album, string>, _1, album_title, attribute_getter, cond);
};


void Album::RegisterAlbumIDTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Album", "AlbumID", condition, action);
}


void Album::RegisterAlbumTitleTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Album", "AlbumTitle", condition, action);
}


Ptr<Album::OpaqueData> Album::CreateOpaqueDataFromJson(const Json &json) {
  if (not json.IsObject()) {
    LOG(ERROR) << "not object type";
    return Ptr<OpaqueData>();
  }

  Ptr<OpaqueData> data(new OpaqueData);

  if (json.HasAttribute("AlbumTitle")) {
    if (not json["AlbumTitle"].IsString()) {
      LOG(ERROR) << "wrong 'AlbumTitle' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->album_title = json["AlbumTitle"].GetString();
  }
  return data;
}


Ptr<Album> Album::Create(const string &albumid) {
  AttributeValueMap key_params;
  key_params["AlbumID"].reset(new AttributeValue(albumid));

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Album"));
  BOOST_ASSERT(model);

  // try to fetch by same key values.
  if (FetchByAlbumID(albumid, kReadLock)) {
    // key value is duplicated.
    return kNullPtr;
  }

  Ptr<Object> obj = Object::Create(model, key_params);
  if (not obj) {
    // key value is duplicated.
    return kNullPtr;
  }

  return Ptr<Album>(new Album(obj));
}


Ptr<Album> Album::Fetch(
    const Object::Id &id,
    LockType lock_type) {
  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Album"));
  BOOST_ASSERT(model);

  Ptr<Object> obj = Object::Fetch(model, id, lock_type);
  if (not obj)
    return kNullPtr;

  return Ptr<Album>(new Album(obj));
}


void Album::Fetch(
    const std::vector<Object::Id> &ids,
    std::vector<std::pair<Object::Id, Ptr<Album> > > *result,
    LockType lock_type) {
  BOOST_ASSERT(result);
  BOOST_ASSERT(result->empty());

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Album"));
  BOOST_ASSERT(model);

  std::vector<std::pair<Object::Id, Ptr<Object> > > objs;
  objs.reserve(ids.size());
  Object::Fetch(model, ids, lock_type, &objs);
  BOOST_ASSERT(objs.size() == ids.size());

  result->reserve(ids.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    Ptr<Album> wrapped_obj;
    if (objs[i].second)
      wrapped_obj.reset(new Album(objs[i].second));
    result->push_back(std::make_pair(objs[i].first, wrapped_obj));
  }

  BOOST_ASSERT(result->size() == ids.size());
}


Ptr<Album> Album::FetchByAlbumID(const string &value, LockType lock_type) {
  Ptr<AttributeValue> key_value(new AttributeValue(value));
  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Album"));
  BOOST_ASSERT(model);

  Ptr<Object> obj = Object::Fetch(model, "AlbumID",  key_value, lock_type);
  if (not obj)
    return kNullPtr;

  return Ptr<Album>(new Album(obj));
}


void Album::FetchByAlbumID(
    const std::vector<string> &values,
    std::vector<std::pair<string, Ptr<Album> > > *result,
    LockType lock_type) {
  BOOST_ASSERT(result);
  BOOST_ASSERT(result->empty());

  std::vector<Ptr<AttributeValue> > key_values;
  key_values.reserve(values.size());
  for (size_t i = 0; i < values.size(); ++i) {
    key_values.push_back(Ptr<AttributeValue>(new AttributeValue(values[i])));
  }

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Album"));
  BOOST_ASSERT(model);

  std::vector<std::pair<Ptr<AttributeValue>, Ptr<Object> > > objs;
  Object::Fetch(model, "AlbumID", key_values, lock_type, &objs);
  BOOST_ASSERT(objs.size() == key_values.size());

  result->reserve(values.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    Ptr<Album> wrapped_obj;
    if (objs[i].second)
      wrapped_obj.reset(new Album(objs[i].second));
    BOOST_ASSERT(AttributeValue(values[i]) == *objs[i].first);
    result->push_back(std::make_pair(values[i], wrapped_obj));
  }

  BOOST_ASSERT(result->size() == values.size());
}


bool Album::IsNull() const {
  return ObjectProxy::IsNull();
}


bool Album::IsFresh() const {
  return ObjectProxy::IsFresh();
}


bool Album::Refresh() {
  return ObjectProxy::Refresh();
}


const Object::Id &Album::Id() const {
  BOOST_ASSERT(object());
  return object()->id();
}


void Album::Delete() {
  object()->Delete();
  BOOST_ASSERT(IsNull());
}


bool Album::PopulateFrom(const Ptr<OpaqueData> &opaque_data) {
  SetAlbumTitle(opaque_data->album_title);
  return true;
}


string Album::GetAlbumID() const {
  BOOST_ASSERT(object());
  return object()->GetString("AlbumID");
}


void Album::SetAlbumID(const string &value) {
  BOOST_ASSERT(object());object()->SetString("AlbumID", value);}


string Album::GetAlbumTitle() const {
  BOOST_ASSERT(object());
  return object()->GetString("AlbumTitle");
}


void Album::SetAlbumTitle(const string &value) {
  BOOST_ASSERT(object());object()->SetString("AlbumTitle", value);}


Album::Album(const Ptr<Object> &object)
    : ObjectProxy(object) {
}


DEFINE_CLASS_PTR(Pet);


function<bool(const Ptr<Pet> &)> Pet::MatchByObjectId(const Object::Id &object_id) {
  function<Object::Id(const Ptr<Pet> &)> obj_id_getter = bind(&Pet::Id, _1);
  return bind(&CompareAttribute<Pet, Object::Id>, _1, object_id, obj_id_getter, kEqual);
}


function<bool(const Ptr<Pet> &)> Pet::MatchByPetLife(const int64_t &pet_life, MatchCondition cond) {
  function<int64_t(const Ptr<Pet> &)> attribute_getter = bind(&Pet::GetPetLife, _1);
  return bind(&CompareAttribute<Pet, int64_t>, _1, pet_life, attribute_getter, cond);
}


function<bool(const Ptr<Pet> &)> Pet::MatchByPetCode(const int64_t &pet_code, MatchCondition cond) {
  function<int64_t(const Ptr<Pet> &)> attribute_getter = bind(&Pet::GetPetCode, _1);
  return bind(&CompareAttribute<Pet, int64_t>, _1, pet_code, attribute_getter, cond);
};


void Pet::RegisterPetLifeTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Pet", "PetLife", condition, action);
}


void Pet::RegisterPetCodeTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Pet", "PetCode", condition, action);
}


Ptr<Pet::OpaqueData> Pet::CreateOpaqueDataFromJson(const Json &json) {
  if (not json.IsObject()) {
    LOG(ERROR) << "not object type";
    return Ptr<OpaqueData>();
  }

  Ptr<OpaqueData> data(new OpaqueData);

  if (json.HasAttribute("PetLife")) {
    if (not json["PetLife"].IsInteger()) {
      LOG(ERROR) << "wrong 'PetLife' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->pet_life = json["PetLife"].GetInteger();
  }
  if (json.HasAttribute("PetCode")) {
    if (not json["PetCode"].IsInteger()) {
      LOG(ERROR) << "wrong 'PetCode' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->pet_code = json["PetCode"].GetInteger();
  }
  return data;
}


Ptr<Pet> Pet::Create() {
  AttributeValueMap key_params;

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Pet"));
  BOOST_ASSERT(model);

  // try to fetch by same key values.

  Ptr<Object> obj = Object::Create(model, key_params);
  if (not obj) {
    // key value is duplicated.
    return kNullPtr;
  }

  return Ptr<Pet>(new Pet(obj));
}


Ptr<Pet> Pet::Fetch(
    const Object::Id &id,
    LockType lock_type) {
  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Pet"));
  BOOST_ASSERT(model);

  Ptr<Object> obj = Object::Fetch(model, id, lock_type);
  if (not obj)
    return kNullPtr;

  return Ptr<Pet>(new Pet(obj));
}


void Pet::Fetch(
    const std::vector<Object::Id> &ids,
    std::vector<std::pair<Object::Id, Ptr<Pet> > > *result,
    LockType lock_type) {
  BOOST_ASSERT(result);
  BOOST_ASSERT(result->empty());

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Pet"));
  BOOST_ASSERT(model);

  std::vector<std::pair<Object::Id, Ptr<Object> > > objs;
  objs.reserve(ids.size());
  Object::Fetch(model, ids, lock_type, &objs);
  BOOST_ASSERT(objs.size() == ids.size());

  result->reserve(ids.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    Ptr<Pet> wrapped_obj;
    if (objs[i].second)
      wrapped_obj.reset(new Pet(objs[i].second));
    result->push_back(std::make_pair(objs[i].first, wrapped_obj));
  }

  BOOST_ASSERT(result->size() == ids.size());
}


bool Pet::IsNull() const {
  return ObjectProxy::IsNull();
}


bool Pet::IsFresh() const {
  return ObjectProxy::IsFresh();
}


bool Pet::Refresh() {
  return ObjectProxy::Refresh();
}


const Object::Id &Pet::Id() const {
  BOOST_ASSERT(object());
  return object()->id();
}


void Pet::Delete() {
  object()->Delete();
  BOOST_ASSERT(IsNull());
}


bool Pet::PopulateFrom(const Ptr<OpaqueData> &opaque_data) {
  SetPetLife(opaque_data->pet_life);
  SetPetCode(opaque_data->pet_code);
  return true;
}


int64_t Pet::GetPetLife() const {
  BOOST_ASSERT(object());
  return object()->GetInteger("PetLife");
}


void Pet::SetPetLife(const int64_t &value) {
  BOOST_ASSERT(object());object()->SetInteger("PetLife", value);}


int64_t Pet::GetPetCode() const {
  BOOST_ASSERT(object());
  return object()->GetInteger("PetCode");
}


void Pet::SetPetCode(const int64_t &value) {
  BOOST_ASSERT(object());object()->SetInteger("PetCode", value);}


Pet::Pet(const Ptr<Object> &object)
    : ObjectProxy(object) {
}


DEFINE_CLASS_PTR(Character);


function<bool(const Ptr<Character> &)> Character::MatchByObjectId(const Object::Id &object_id) {
  function<Object::Id(const Ptr<Character> &)> obj_id_getter = bind(&Character::Id, _1);
  return bind(&CompareAttribute<Character, Object::Id>, _1, object_id, obj_id_getter, kEqual);
}


function<bool(const Ptr<Character> &)> Character::MatchByName(const string &name, MatchCondition cond) {
  function<string(const Ptr<Character> &)> attribute_getter = bind(&Character::GetName, _1);
  return bind(&CompareAttribute<Character, string>, _1, name, attribute_getter, cond);
}


function<bool(const Ptr<Character> &)> Character::MatchByExp(const int64_t &exp, MatchCondition cond) {
  function<int64_t(const Ptr<Character> &)> attribute_getter = bind(&Character::GetExp, _1);
  return bind(&CompareAttribute<Character, int64_t>, _1, exp, attribute_getter, cond);
}


function<bool(const Ptr<Character> &)> Character::MatchByLevel(const int64_t &level, MatchCondition cond) {
  function<int64_t(const Ptr<Character> &)> attribute_getter = bind(&Character::GetLevel, _1);
  return bind(&CompareAttribute<Character, int64_t>, _1, level, attribute_getter, cond);
}


function<bool(const Ptr<Character> &)> Character::MatchByHp(const int64_t &hp, MatchCondition cond) {
  function<int64_t(const Ptr<Character> &)> attribute_getter = bind(&Character::GetHp, _1);
  return bind(&CompareAttribute<Character, int64_t>, _1, hp, attribute_getter, cond);
}


function<bool(const Ptr<Character> &)> Character::MatchByMp(const int64_t &mp, MatchCondition cond) {
  function<int64_t(const Ptr<Character> &)> attribute_getter = bind(&Character::GetMp, _1);
  return bind(&CompareAttribute<Character, int64_t>, _1, mp, attribute_getter, cond);
}


function<bool(const Ptr<Character> &)> Character::MatchBydurability(const int64_t &durability, MatchCondition cond) {
  function<int64_t(const Ptr<Character> &)> attribute_getter = bind(&Character::Getdurability, _1);
  return bind(&CompareAttribute<Character, int64_t>, _1, durability, attribute_getter, cond);
};


void Character::RegisterNameTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Character", "Name", condition, action);
}


void Character::RegisterExpTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Character", "Exp", condition, action);
}


void Character::RegisterLevelTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Character", "Level", condition, action);
}


void Character::RegisterHpTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Character", "Hp", condition, action);
}


void Character::RegisterMpTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Character", "Mp", condition, action);
}


void Character::RegisterdurabilityTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Character", "durability", condition, action);
}


Ptr<Character::OpaqueData> Character::CreateOpaqueDataFromJson(const Json &json) {
  if (not json.IsObject()) {
    LOG(ERROR) << "not object type";
    return Ptr<OpaqueData>();
  }

  Ptr<OpaqueData> data(new OpaqueData);

  if (json.HasAttribute("Exp")) {
    if (not json["Exp"].IsInteger()) {
      LOG(ERROR) << "wrong 'Exp' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->exp = json["Exp"].GetInteger();
  }
  if (json.HasAttribute("Level")) {
    if (not json["Level"].IsInteger()) {
      LOG(ERROR) << "wrong 'Level' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->level = json["Level"].GetInteger();
  }
  if (json.HasAttribute("Hp")) {
    if (not json["Hp"].IsInteger()) {
      LOG(ERROR) << "wrong 'Hp' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->hp = json["Hp"].GetInteger();
  }
  if (json.HasAttribute("Mp")) {
    if (not json["Mp"].IsInteger()) {
      LOG(ERROR) << "wrong 'Mp' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->mp = json["Mp"].GetInteger();
  }
  if (json.HasAttribute("durability")) {
    if (not json["durability"].IsInteger()) {
      LOG(ERROR) << "wrong 'durability' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->durability = json["durability"].GetInteger();
  }
  return data;
}


Ptr<Character> Character::Create(const string &name) {
  AttributeValueMap key_params;
  key_params["Name"].reset(new AttributeValue(name));

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Character"));
  BOOST_ASSERT(model);

  // try to fetch by same key values.
  if (FetchByName(name, kReadLock)) {
    // key value is duplicated.
    return kNullPtr;
  }

  Ptr<Object> obj = Object::Create(model, key_params);
  if (not obj) {
    // key value is duplicated.
    return kNullPtr;
  }

  return Ptr<Character>(new Character(obj));
}


Ptr<Character> Character::Fetch(
    const Object::Id &id,
    LockType lock_type) {
  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Character"));
  BOOST_ASSERT(model);

  Ptr<Object> obj = Object::Fetch(model, id, lock_type);
  if (not obj)
    return kNullPtr;

  return Ptr<Character>(new Character(obj));
}


void Character::Fetch(
    const std::vector<Object::Id> &ids,
    std::vector<std::pair<Object::Id, Ptr<Character> > > *result,
    LockType lock_type) {
  BOOST_ASSERT(result);
  BOOST_ASSERT(result->empty());

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Character"));
  BOOST_ASSERT(model);

  std::vector<std::pair<Object::Id, Ptr<Object> > > objs;
  objs.reserve(ids.size());
  Object::Fetch(model, ids, lock_type, &objs);
  BOOST_ASSERT(objs.size() == ids.size());

  result->reserve(ids.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    Ptr<Character> wrapped_obj;
    if (objs[i].second)
      wrapped_obj.reset(new Character(objs[i].second));
    result->push_back(std::make_pair(objs[i].first, wrapped_obj));
  }

  BOOST_ASSERT(result->size() == ids.size());
}


Ptr<Character> Character::FetchByName(const string &value, LockType lock_type) {
  Ptr<AttributeValue> key_value(new AttributeValue(value));
  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Character"));
  BOOST_ASSERT(model);

  Ptr<Object> obj = Object::Fetch(model, "Name",  key_value, lock_type);
  if (not obj)
    return kNullPtr;

  return Ptr<Character>(new Character(obj));
}


void Character::FetchByName(
    const std::vector<string> &values,
    std::vector<std::pair<string, Ptr<Character> > > *result,
    LockType lock_type) {
  BOOST_ASSERT(result);
  BOOST_ASSERT(result->empty());

  std::vector<Ptr<AttributeValue> > key_values;
  key_values.reserve(values.size());
  for (size_t i = 0; i < values.size(); ++i) {
    key_values.push_back(Ptr<AttributeValue>(new AttributeValue(values[i])));
  }

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Character"));
  BOOST_ASSERT(model);

  std::vector<std::pair<Ptr<AttributeValue>, Ptr<Object> > > objs;
  Object::Fetch(model, "Name", key_values, lock_type, &objs);
  BOOST_ASSERT(objs.size() == key_values.size());

  result->reserve(values.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    Ptr<Character> wrapped_obj;
    if (objs[i].second)
      wrapped_obj.reset(new Character(objs[i].second));
    BOOST_ASSERT(AttributeValue(values[i]) == *objs[i].first);
    result->push_back(std::make_pair(values[i], wrapped_obj));
  }

  BOOST_ASSERT(result->size() == values.size());
}


bool Character::IsNull() const {
  return ObjectProxy::IsNull();
}


bool Character::IsFresh() const {
  return ObjectProxy::IsFresh();
}


bool Character::Refresh() {
  return ObjectProxy::Refresh();
}


const Object::Id &Character::Id() const {
  BOOST_ASSERT(object());
  return object()->id();
}


void Character::Delete() {
  object()->Delete();
  BOOST_ASSERT(IsNull());
}


bool Character::PopulateFrom(const Ptr<OpaqueData> &opaque_data) {
  SetExp(opaque_data->exp);
  SetLevel(opaque_data->level);
  SetHp(opaque_data->hp);
  SetMp(opaque_data->mp);
  Setdurability(opaque_data->durability);
  return true;
}


string Character::GetName() const {
  BOOST_ASSERT(object());
  return object()->GetString("Name");
}


void Character::SetName(const string &value) {
  BOOST_ASSERT(object());object()->SetString("Name", value);}


int64_t Character::GetExp() const {
  BOOST_ASSERT(object());
  return object()->GetInteger("Exp");
}


void Character::SetExp(const int64_t &value) {
  BOOST_ASSERT(object());object()->SetInteger("Exp", value);}


int64_t Character::GetLevel() const {
  BOOST_ASSERT(object());
  return object()->GetInteger("Level");
}


void Character::SetLevel(const int64_t &value) {
  BOOST_ASSERT(object());object()->SetInteger("Level", value);}


int64_t Character::GetHp() const {
  BOOST_ASSERT(object());
  return object()->GetInteger("Hp");
}


void Character::SetHp(const int64_t &value) {
  BOOST_ASSERT(object());object()->SetInteger("Hp", value);}


int64_t Character::GetMp() const {
  BOOST_ASSERT(object());
  return object()->GetInteger("Mp");
}


void Character::SetMp(const int64_t &value) {
  BOOST_ASSERT(object());object()->SetInteger("Mp", value);}


int64_t Character::Getdurability() const {
  BOOST_ASSERT(object());
  return object()->GetInteger("durability");
}


void Character::Setdurability(const int64_t &value) {
  BOOST_ASSERT(object());object()->SetInteger("durability", value);}


Character::Character(const Ptr<Object> &object)
    : ObjectProxy(object) {
}


DEFINE_CLASS_PTR(User);


function<bool(const Ptr<User> &)> User::MatchByObjectId(const Object::Id &object_id) {
  function<Object::Id(const Ptr<User> &)> obj_id_getter = bind(&User::Id, _1);
  return bind(&CompareAttribute<User, Object::Id>, _1, object_id, obj_id_getter, kEqual);
}


function<bool(const Ptr<User> &)> User::MatchById(const string &id, MatchCondition cond) {
  function<string(const Ptr<User> &)> attribute_getter = bind(&User::GetId, _1);
  return bind(&CompareAttribute<User, string>, _1, id, attribute_getter, cond);
}


function<bool(const Ptr<User> &)> User::MatchByMyCharacter(const function<bool(const Ptr<Character> &)> &match) {
  function<Ptr<Character>(const Ptr<User> &)> attribute_getter = bind(&User::GetMyCharacter, _1);
  return bind(&CompareAttribute2<User, Ptr<Character> >, _1, match, attribute_getter);
};


void User::RegisterIdTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("User", "Id", condition, action);
}


void User::RegisterMyCharacterTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("User", "MyCharacter", condition, action);
}


Ptr<User::OpaqueData> User::CreateOpaqueDataFromJson(const Json &json) {
  if (not json.IsObject()) {
    LOG(ERROR) << "not object type";
    return Ptr<OpaqueData>();
  }

  Ptr<OpaqueData> data(new OpaqueData);

  if (json.HasAttribute("MyCharacter")) {
    if (not json["MyCharacter"].IsObject()) {
      LOG(ERROR) << "wrong 'MyCharacter' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->my_character = Character::CreateOpaqueDataFromJson(json["MyCharacter"]);
    if (not data->my_character)
      return Ptr<OpaqueData>();
  }
  return data;
}


Ptr<User> User::Create(const string &id) {
  AttributeValueMap key_params;
  key_params["Id"].reset(new AttributeValue(id));

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("User"));
  BOOST_ASSERT(model);

  // try to fetch by same key values.
  if (FetchById(id, kReadLock)) {
    // key value is duplicated.
    return kNullPtr;
  }

  Ptr<Object> obj = Object::Create(model, key_params);
  if (not obj) {
    // key value is duplicated.
    return kNullPtr;
  }

  return Ptr<User>(new User(obj));
}


Ptr<User> User::Fetch(
    const Object::Id &id,
    LockType lock_type) {
  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("User"));
  BOOST_ASSERT(model);

  Ptr<Object> obj = Object::Fetch(model, id, lock_type);
  if (not obj)
    return kNullPtr;

  return Ptr<User>(new User(obj));
}


void User::Fetch(
    const std::vector<Object::Id> &ids,
    std::vector<std::pair<Object::Id, Ptr<User> > > *result,
    LockType lock_type) {
  BOOST_ASSERT(result);
  BOOST_ASSERT(result->empty());

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("User"));
  BOOST_ASSERT(model);

  std::vector<std::pair<Object::Id, Ptr<Object> > > objs;
  objs.reserve(ids.size());
  Object::Fetch(model, ids, lock_type, &objs);
  BOOST_ASSERT(objs.size() == ids.size());

  result->reserve(ids.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    Ptr<User> wrapped_obj;
    if (objs[i].second)
      wrapped_obj.reset(new User(objs[i].second));
    result->push_back(std::make_pair(objs[i].first, wrapped_obj));
  }

  BOOST_ASSERT(result->size() == ids.size());
}


Ptr<User> User::FetchById(const string &value, LockType lock_type) {
  Ptr<AttributeValue> key_value(new AttributeValue(value));
  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("User"));
  BOOST_ASSERT(model);

  Ptr<Object> obj = Object::Fetch(model, "Id",  key_value, lock_type);
  if (not obj)
    return kNullPtr;

  return Ptr<User>(new User(obj));
}


void User::FetchById(
    const std::vector<string> &values,
    std::vector<std::pair<string, Ptr<User> > > *result,
    LockType lock_type) {
  BOOST_ASSERT(result);
  BOOST_ASSERT(result->empty());

  std::vector<Ptr<AttributeValue> > key_values;
  key_values.reserve(values.size());
  for (size_t i = 0; i < values.size(); ++i) {
    key_values.push_back(Ptr<AttributeValue>(new AttributeValue(values[i])));
  }

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("User"));
  BOOST_ASSERT(model);

  std::vector<std::pair<Ptr<AttributeValue>, Ptr<Object> > > objs;
  Object::Fetch(model, "Id", key_values, lock_type, &objs);
  BOOST_ASSERT(objs.size() == key_values.size());

  result->reserve(values.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    Ptr<User> wrapped_obj;
    if (objs[i].second)
      wrapped_obj.reset(new User(objs[i].second));
    BOOST_ASSERT(AttributeValue(values[i]) == *objs[i].first);
    result->push_back(std::make_pair(values[i], wrapped_obj));
  }

  BOOST_ASSERT(result->size() == values.size());
}


bool User::IsNull() const {
  return ObjectProxy::IsNull();
}


bool User::IsFresh() const {
  return ObjectProxy::IsFresh();
}


bool User::Refresh() {
  return ObjectProxy::Refresh();
}


const Object::Id &User::Id() const {
  BOOST_ASSERT(object());
  return object()->id();
}


void User::Delete() {
  object()->Delete();
  BOOST_ASSERT(IsNull());
}


bool User::PopulateFrom(const Ptr<OpaqueData> &opaque_data) {
  if (opaque_data->my_character) {
    Ptr<Character> my_character = GetMyCharacter();
    if (not my_character) {
      LOG(ERROR) << "failed to create 'MyCharacter'. 'Character' has key attribute.";
      return false;
    }
    BOOST_ASSERT(my_character);

    if (not my_character->PopulateFrom(opaque_data->my_character))
      return false;
  }
  return true;
}


string User::GetId() const {
  BOOST_ASSERT(object());
  return object()->GetString("Id");
}


void User::SetId(const string &value) {
  BOOST_ASSERT(object());object()->SetString("Id", value);}


Ptr<Character> User::GetMyCharacter() const {
  BOOST_ASSERT(object());
  Object::Id attr_obj_id = object()->GetObject("MyCharacter");
  if (attr_obj_id == Object::kNullId)
    return Character::kNullPtr;
  Ptr<Character> attr_obj = Character::Fetch(attr_obj_id, object()->lock_type());
  if (not attr_obj) {
    LOG(WARNING) << "User(" << object()->id() << ")"
                 << " - MyCharacter(" << attr_obj_id << ") not found";
  }
  return attr_obj;
}


void User::SetMyCharacter(const Ptr<Character> &value) {
  BOOST_ASSERT(object());
  if (value)
    object()->SetObject("MyCharacter", value->Id(), false);
  else
    object()->SetObject("MyCharacter", Object::kNullId, false);
}


void User::DeleteMyCharacter(bool delete_object) {
  BOOST_ASSERT(object());
  object()->SetObject("MyCharacter", Object::kNullId, delete_object);
}


User::User(const Ptr<Object> &object)
    : ObjectProxy(object) {
}


DEFINE_CLASS_PTR(Music2);


function<bool(const Ptr<Music2> &)> Music2::MatchByObjectId(const Object::Id &object_id) {
  function<Object::Id(const Ptr<Music2> &)> obj_id_getter = bind(&Music2::Id, _1);
  return bind(&CompareAttribute<Music2, Object::Id>, _1, object_id, obj_id_getter, kEqual);
}


function<bool(const Ptr<Music2> &)> Music2::MatchByMusicID(const string &musicid, MatchCondition cond) {
  function<string(const Ptr<Music2> &)> attribute_getter = bind(&Music2::GetMusicID, _1);
  return bind(&CompareAttribute<Music2, string>, _1, musicid, attribute_getter, cond);
}


function<bool(const Ptr<Music2> &)> Music2::MatchByMusicTitle(const string &music_title, MatchCondition cond) {
  function<string(const Ptr<Music2> &)> attribute_getter = bind(&Music2::GetMusicTitle, _1);
  return bind(&CompareAttribute<Music2, string>, _1, music_title, attribute_getter, cond);
};


void Music2::RegisterMusicIDTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Music2", "MusicID", condition, action);
}


void Music2::RegisterMusicTitleTrigger(const TriggerCondition &condition, const TriggerAction &action) {
  Object::RegisterAttributeTrigger("Music2", "MusicTitle", condition, action);
}


Ptr<Music2::OpaqueData> Music2::CreateOpaqueDataFromJson(const Json &json) {
  if (not json.IsObject()) {
    LOG(ERROR) << "not object type";
    return Ptr<OpaqueData>();
  }

  Ptr<OpaqueData> data(new OpaqueData);

  if (json.HasAttribute("MusicTitle")) {
    if (not json["MusicTitle"].IsString()) {
      LOG(ERROR) << "wrong 'MusicTitle' value: type mismatch";
      return Ptr<OpaqueData>();
    }
    data->music_title = json["MusicTitle"].GetString();
  }
  return data;
}


Ptr<Music2> Music2::Create(const string &musicid) {
  AttributeValueMap key_params;
  key_params["MusicID"].reset(new AttributeValue(musicid));

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Music2"));
  BOOST_ASSERT(model);

  // try to fetch by same key values.
  if (FetchByMusicID(musicid, kReadLock)) {
    // key value is duplicated.
    return kNullPtr;
  }

  Ptr<Object> obj = Object::Create(model, key_params);
  if (not obj) {
    // key value is duplicated.
    return kNullPtr;
  }

  return Ptr<Music2>(new Music2(obj));
}


Ptr<Music2> Music2::Fetch(
    const Object::Id &id,
    LockType lock_type) {
  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Music2"));
  BOOST_ASSERT(model);

  Ptr<Object> obj = Object::Fetch(model, id, lock_type);
  if (not obj)
    return kNullPtr;

  return Ptr<Music2>(new Music2(obj));
}


void Music2::Fetch(
    const std::vector<Object::Id> &ids,
    std::vector<std::pair<Object::Id, Ptr<Music2> > > *result,
    LockType lock_type) {
  BOOST_ASSERT(result);
  BOOST_ASSERT(result->empty());

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Music2"));
  BOOST_ASSERT(model);

  std::vector<std::pair<Object::Id, Ptr<Object> > > objs;
  objs.reserve(ids.size());
  Object::Fetch(model, ids, lock_type, &objs);
  BOOST_ASSERT(objs.size() == ids.size());

  result->reserve(ids.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    Ptr<Music2> wrapped_obj;
    if (objs[i].second)
      wrapped_obj.reset(new Music2(objs[i].second));
    result->push_back(std::make_pair(objs[i].first, wrapped_obj));
  }

  BOOST_ASSERT(result->size() == ids.size());
}


Ptr<Music2> Music2::FetchByMusicID(const string &value, LockType lock_type) {
  Ptr<AttributeValue> key_value(new AttributeValue(value));
  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Music2"));
  BOOST_ASSERT(model);

  Ptr<Object> obj = Object::Fetch(model, "MusicID",  key_value, lock_type);
  if (not obj)
    return kNullPtr;

  return Ptr<Music2>(new Music2(obj));
}


void Music2::FetchByMusicID(
    const std::vector<string> &values,
    std::vector<std::pair<string, Ptr<Music2> > > *result,
    LockType lock_type) {
  BOOST_ASSERT(result);
  BOOST_ASSERT(result->empty());

  std::vector<Ptr<AttributeValue> > key_values;
  key_values.reserve(values.size());
  for (size_t i = 0; i < values.size(); ++i) {
    key_values.push_back(Ptr<AttributeValue>(new AttributeValue(values[i])));
  }

  const Ptr<const ObjectModel> &model(ObjectModel::FindModel("Music2"));
  BOOST_ASSERT(model);

  std::vector<std::pair<Ptr<AttributeValue>, Ptr<Object> > > objs;
  Object::Fetch(model, "MusicID", key_values, lock_type, &objs);
  BOOST_ASSERT(objs.size() == key_values.size());

  result->reserve(values.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    Ptr<Music2> wrapped_obj;
    if (objs[i].second)
      wrapped_obj.reset(new Music2(objs[i].second));
    BOOST_ASSERT(AttributeValue(values[i]) == *objs[i].first);
    result->push_back(std::make_pair(values[i], wrapped_obj));
  }

  BOOST_ASSERT(result->size() == values.size());
}


bool Music2::IsNull() const {
  return ObjectProxy::IsNull();
}


bool Music2::IsFresh() const {
  return ObjectProxy::IsFresh();
}


bool Music2::Refresh() {
  return ObjectProxy::Refresh();
}


const Object::Id &Music2::Id() const {
  BOOST_ASSERT(object());
  return object()->id();
}


void Music2::Delete() {
  object()->Delete();
  BOOST_ASSERT(IsNull());
}


bool Music2::PopulateFrom(const Ptr<OpaqueData> &opaque_data) {
  SetMusicTitle(opaque_data->music_title);
  return true;
}


string Music2::GetMusicID() const {
  BOOST_ASSERT(object());
  return object()->GetString("MusicID");
}


void Music2::SetMusicID(const string &value) {
  BOOST_ASSERT(object());object()->SetString("MusicID", value);}


string Music2::GetMusicTitle() const {
  BOOST_ASSERT(object());
  return object()->GetString("MusicTitle");
}


void Music2::SetMusicTitle(const string &value) {
  BOOST_ASSERT(object());object()->SetString("MusicTitle", value);}


Music2::Music2(const Ptr<Object> &object)
    : ObjectProxy(object) {
}


void RegisterAlbumModel() {
  AttributeModelVector attrs;

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "AlbumID", fun::AttributeModel::kString, true , false, false, false)));

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "AlbumTitle", fun::AttributeModel::kString, false, false, false, false)));

  Ptr<const ObjectModel> model(new ObjectModel("Album", attrs));
  ObjectModel::AddModel(model);

  // Regiters counter.
  UpdateCounter(
      "funapi_object_model",
      "Album",
      "The number of active Album objects in memory",
      0);
}


void RegisterPetModel() {
  AttributeModelVector attrs;

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "PetLife", fun::AttributeModel::kInteger, false, false, false, false)));

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "PetCode", fun::AttributeModel::kInteger, false, false, false, false)));

  Ptr<const ObjectModel> model(new ObjectModel("Pet", attrs));
  ObjectModel::AddModel(model);

  // Regiters counter.
  UpdateCounter(
      "funapi_object_model",
      "Pet",
      "The number of active Pet objects in memory",
      0);
}


void RegisterCharacterModel() {
  AttributeModelVector attrs;

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "Name", fun::AttributeModel::kString, true , false, false, false)));

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "Exp", fun::AttributeModel::kInteger, false, false, false, false)));

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "Level", fun::AttributeModel::kInteger, false, false, false, false)));

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "Hp", fun::AttributeModel::kInteger, false, false, false, false)));

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "Mp", fun::AttributeModel::kInteger, false, false, false, false)));

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "durability", fun::AttributeModel::kInteger, false, false, false, false)));

  Ptr<const ObjectModel> model(new ObjectModel("Character", attrs));
  ObjectModel::AddModel(model);

  // Regiters counter.
  UpdateCounter(
      "funapi_object_model",
      "Character",
      "The number of active Character objects in memory",
      0);
}


void RegisterUserModel() {
  AttributeModelVector attrs;

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "Id", fun::AttributeModel::kString, true , false, false, false)));

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "MyCharacter", "Character", false, false, false, false)));

  Ptr<const ObjectModel> model(new ObjectModel("User", attrs));
  ObjectModel::AddModel(model);

  // Regiters counter.
  UpdateCounter(
      "funapi_object_model",
      "User",
      "The number of active User objects in memory",
      0);
}


void RegisterMusic2Model() {
  AttributeModelVector attrs;

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "MusicID", fun::AttributeModel::kString, true , false, false, false)));

  attrs.push_back(Ptr<const AttributeModel>(
      new AttributeModel(
          "MusicTitle", fun::AttributeModel::kString, false, false, false, false)));

  Ptr<const ObjectModel> model(new ObjectModel("Music2", attrs));
  ObjectModel::AddModel(model);

  // Regiters counter.
  UpdateCounter(
      "funapi_object_model",
      "Music2",
      "The number of active Music2 objects in memory",
      0);
}


void ObjectModelInit() {
  RegisterAlbumModel();
  RegisterPetModel();
  RegisterCharacterModel();
  RegisterUserModel();
  RegisterMusic2Model();

  Object::ObjectModelInit();
}


#ifdef ENABLE_FUNAPI_CS_API
namespace cs_api {

using fun::Json;
using fun::http::Request;
using fun::http::Response;

typedef fun::ApiService::MatchResult Params;


namespace {
static CsApiHandler *g_handler = NULL;
}


CsApiHandler::CsApiHandler() : schemas_(boost::assign::map_list_of
    ("Album", "{\"Album\": {\"propertylist\": [{\"readonly\": true, \"type\": \"string\", \"name\": \"AlbumID\", \"key\": true}, {\"type\": \"string\", \"name\": \"AlbumTitle\"}], \"type\": \"object\"}}")
    ("Pet", "{\"Pet\": {\"propertylist\": [{\"type\": \"integer\", \"name\": \"PetLife\"}, {\"type\": \"integer\", \"name\": \"PetCode\"}], \"type\": \"object\"}}")
    ("Character", "{\"Character\": {\"propertylist\": [{\"readonly\": true, \"type\": \"string\", \"name\": \"Name\", \"key\": true}, {\"type\": \"integer\", \"name\": \"Exp\"}, {\"type\": \"integer\", \"name\": \"Level\"}, {\"type\": \"integer\", \"name\": \"Hp\"}, {\"type\": \"integer\", \"name\": \"Mp\"}, {\"type\": \"integer\", \"name\": \"durability\"}], \"type\": \"object\"}}")
    ("User", "{\"User\": {\"propertylist\": [{\"readonly\": true, \"type\": \"string\", \"name\": \"Id\", \"key\": true}, {\"type\": \"object\", \"name\": \"MyCharacter\", \"schema\": \"Character\"}], \"type\": \"object\"}}")
    ("Music2", "{\"Music2\": {\"propertylist\": [{\"readonly\": true, \"type\": \"string\", \"name\": \"MusicID\", \"key\": true}, {\"type\": \"string\", \"name\": \"MusicTitle\"}], \"type\": \"object\"}}").convert_to_container<boost::unordered_map<string, string> >()),
  getters_(boost::assign::map_list_of("Album", FetchAlbum)("Character", FetchCharacter)("User", FetchUser)("Music2", FetchMusic2).convert_to_container<CsApiHandler::getter_map>())
{
}


CsApiHandler::~CsApiHandler() {
}


bool CsApiHandler::GetSchemaList(std::vector<std::string> *result) {
  if (!result)
    return false;
  for (schema_map::const_iterator i = schemas_.begin(), ie = schemas_.end();
        i != ie; ++i)
    result->push_back(i->first);
  return true;
}


bool CsApiHandler::ShowSchema(const string &name, string *result) {
  if (!result)
    return false;
  schema_map::const_iterator it = schemas_.find(name);
  if (it != schemas_.end())
    result->assign(it->second);
  return true;
}


bool CsApiHandler::GetAccountTypes(std::vector<std::string>*) {
  return false;
}


bool CsApiHandler::GetAccount(const string&, const string&, Json*) {
  return false;
}


bool CsApiHandler::GetAccountCash(const string&, const string&, Json*) {
  return false;
}

bool CsApiHandler::UpdateAccountCash(
    const string&, const string&, const Json&, Json*) {
  return false;
}


bool CsApiHandler::GetAccountBillingHistory(const std::string &account_type,
      const std::string &uid, int64_t from_ts, int64_t until_ts,
      fun::Json *result) {
  return false;
}


const std::string &CsApiHandler::GetBillerUrl() const {
  static std::string _url;
  return _url;
}


bool CsApiHandler::GetHistoryFromBiller(const std::string &key, int64_t from_ts,
    int64_t until_ts, fun::Json *result) const {
  std::string url = GetBillerUrl();
  if (url.empty())
    return false;

  if (*url.rend() != '/')
    url += '/';

  url += key + "/?from=" + boost::lexical_cast<std::string>(from_ts)
      + "&until=" + boost::lexical_cast<std::string>(until_ts);

  // get response from iFunEngine Biller
  Json response;
  fun::HttpClient client;
  client.set_verbose(false);
  client.Get(url);
  const fun::http::Response &res = client.response();
  if (res.status_code != 200
      || !response.FromString(res.body)
      || !response.HasAttribute("receipts")
      || !response["receipts"].IsArray()) {
    result->SetNull();
    return true;
  }

  Json &receipts = response["receipts"];
  Json &out = (*result)["billing_history"];
  out.SetArray();
  const unsigned len = receipts.Size();
  for (unsigned i = 0; i < len; ++i) {
    out.PushBack();
    Json &dst = out[i];
    Json &src = receipts[i];

    if (src.HasAttribute("product_id"))
      dst["product_id"].SetString(src["product_id"].GetString());

    if (src.HasAttribute("quantity"))
      dst["quantity"].SetInteger(src["quantity"].GetInteger());
    else
      dst["quantity"].SetInteger(1);

    if (src.HasAttribute("purchase_timestamp"))
      dst["store_timestamp"].SetInteger(
          src["purchase_timestamp"].GetInteger());
    if (src.HasAttribute("insert_timestamp"))
      dst["server_timestamp"].SetInteger(src["insert_timestamp"].GetInteger());
  }

  return true;
}


bool CsApiHandler::GetData(const string& schema_type, const string &key,
    Json *result) {
  if (!result)
    return false;
  getter_map::const_iterator func = getters_.find(schema_type);
  BOOST_ASSERT(func != getters_.end());
  if (func == getters_.end())
    return false;

  if (!func->second(key, *result))
    result->SetNull();
  return true;
}


// Album dumper
void DumpJson(my_project::Album &obj, Json &out) {
  out["AlbumID"].SetString(obj.GetAlbumID());
  out["AlbumTitle"].SetString(obj.GetAlbumTitle());
}


// Pet dumper
void DumpJson(my_project::Pet &obj, Json &out) {
  out["PetLife"].SetInteger(obj.GetPetLife());
  out["PetCode"].SetInteger(obj.GetPetCode());
}


// Character dumper
void DumpJson(my_project::Character &obj, Json &out) {
  out["Name"].SetString(obj.GetName());
  out["Exp"].SetInteger(obj.GetExp());
  out["Level"].SetInteger(obj.GetLevel());
  out["Hp"].SetInteger(obj.GetHp());
  out["Mp"].SetInteger(obj.GetMp());
  out["durability"].SetInteger(obj.Getdurability());
}


// User dumper
void DumpJson(my_project::User &obj, Json &out) {
  out["Id"].SetString(obj.GetId());
  // NOTE: MyCharacter (object)
  {
    Json &out_obj = out["MyCharacter"];
    out_obj.SetObject();
    DumpJson(*obj.GetMyCharacter(), out_obj);
  }
}


// Music2 dumper
void DumpJson(my_project::Music2 &obj, Json &out) {
  out["MusicID"].SetString(obj.GetMusicID());
  out["MusicTitle"].SetString(obj.GetMusicTitle());
}



// Album
bool FetchAlbum(const std::string &key, Json &out) {
  Ptr<Album> obj = Album::FetchByAlbumID(key);

  if (!obj)
    return false;
  DumpJson(*obj, out);
  return true;
}

// Character
bool FetchCharacter(const std::string &key, Json &out) {
  Ptr<Character> obj = Character::FetchByName(key);

  if (!obj)
    return false;
  DumpJson(*obj, out);
  return true;
}

// User
bool FetchUser(const std::string &key, Json &out) {
  Ptr<User> obj = User::FetchById(key);

  if (!obj)
    return false;
  DumpJson(*obj, out);
  return true;
}

// Music2
bool FetchMusic2(const std::string &key, Json &out) {
  Ptr<Music2> obj = Music2::FetchByMusicID(key);

  if (!obj)
    return false;
  DumpJson(*obj, out);
  return true;
}


void HandleSchemaList(Ptr<Response> response, const Request &request,
    const Params &params) {
  DLOG(INFO) << "GET /v1/schema/";
  std::vector<std::string> schema_list;
  if (!g_handler->GetSchemaList(&schema_list)) {
    response->status_code = fun::http::kNotImplemented;
    response->body = "not implemented";
    return;
  }

  response->status_code = fun::http::kOk;
  Json msg;
  msg["schemas"].SetArray();
  Json &schemas = msg["schemas"];
  for (std::vector<string>::const_iterator i = schema_list.begin(),
        ie = schema_list.end(); i != ie; ++i)
    schemas.PushBack(*i);
  response->body = msg.ToString();
}


void HandleSchemaGet(Ptr<Response> response, const Request &request,
    const Params &params) {
  response->status_code = fun::http::kOk;
  DLOG(INFO) << "GET /v1/schema/{" << params[1] << "}";
  if (!g_handler->ShowSchema(params[1], &(response->body))) {
    response->status_code = fun::http::kNotImplemented;
    response->body = "not implemented";
    return;
  }

  if (response->body.empty()) {
    response->status_code = fun::http::kNotFound;
    response->body = "not found";
    return;
  }
}


void HandleAccountList(Ptr<Response> response, const Request &request,
    const Params &params) {
  DLOG(INFO) << "GET /v1/account";
  response->status_code = fun::http::kOk;
  Json msg;
  Json &accounts = msg["accounts"];
  accounts.SetArray();
  std::vector<string> _accounts;
  if (!g_handler->GetAccountTypes(&_accounts)) {
    response->status_code = fun::http::kNotImplemented;
    return;
  }

  for (std::vector<string>::const_iterator i = _accounts.begin(),
        ie = _accounts.end(); i != ie; ++i)
    accounts.PushBack(*i);
  response->body = msg.ToString();
}


void HandleAccountGet(Ptr<Response> response, const Request &request,
    const Params &params) {
  DLOG(INFO) << "GET /v1/account/{" << params[1] << "}/{" << params[2] << "}";

  Json msg;
  Json &out = msg["account"];
  out.SetObject();
  if (!g_handler->GetAccount(params[1], params[2], &out)) {
    response->status_code = fun::http::kNotImplemented;
    return;
  }
  if (out.IsNull()) {
    response->status_code = fun::http::kNotFound;
    return;
  }

  msg["account_type"].SetString(params[1]);
  msg["account_id"].SetString(params[2]);
  response->status_code = fun::http::kOk;
  response->body = msg.ToString();
  return;
}


void HandleAccountGetCash(Ptr<Response> response, const Request &request,
    const Params &params) {
  DLOG(INFO) << "GET /v1/account/{" << params[1] << "}/{" << params[2]
      << "}/cash";

  Json obj;
  obj.SetObject();
  if (!g_handler->GetAccountCash(params[1], params[2], &obj)) {
    response->status_code = fun::http::kNotImplemented;
    return;
  }

  if (obj.IsNull()) {
    response->status_code = fun::http::kNotFound;
    return;
  }

  response->status_code = fun::http::kOk;
  response->body = obj.ToString();
  return;
}


void HandleAccountGetBillingHistory(Ptr<Response> response,
    const Request &request, const Params &params) {
  DLOG(INFO) << "GET /v1/account/{" << params[1] << "}/{" << params[2]
      << "}/billing-history";

  int64_t until_ts = std::time(NULL);
  int64_t from_ts = until_ts - (86400 * 7);

  try {
    fun::http::GetParameter::const_iterator it;
    it = request.get_parameter.find("from");
    if (it != request.get_parameter.end()) {
      DLOG(INFO) << "from_ts: " << it->second;
      from_ts = boost::lexical_cast<int64_t>(it->second);
    }

    it = request.get_parameter.find("until");
    if (it != request.get_parameter.end()) {
      DLOG(INFO) << "until_ts: " << it->second;
      until_ts = boost::lexical_cast<int64_t>(it->second);
    }
  } catch (boost::bad_lexical_cast &) {
    LOG(ERROR) << "Invalid timestamp";
    response->status_code = fun::http::kBadRequest;
    response->body = "Invalid timestamp";
    return;
  }

  Json result;
  if (!g_handler->GetAccountBillingHistory(
        params[1], params[2], from_ts, until_ts, &result)) {
    response->status_code = fun::http::kNotImplemented;
    return;
  }

  if (result.IsNull()) {
    response->status_code = fun::http::kNotFound;
    return;
  }

  response->status_code = fun::http::kOk;
  response->body = result.ToString();
  return;
}


void HandleAccountUpdateCash(Ptr<Response> response, const Request &request,
    const Params &params) {
  DLOG(INFO) << "PUT /v1/account/{" << params[1] << "}/{" << params[2]
      << "}/cash";

  Json body;
  if (!body.FromString(request.body)) {
    LOG(ERROR) << "Invalid body";
    response->status_code = fun::http::kBadRequest;
    return;
  }

  Json result;
  if (!g_handler->UpdateAccountCash(params[1], params[2], body, &result)) {
    LOG(ERROR) << "Update cash handler failed (" << params[1]
        << ", " << params[2] << ')';
    response->status_code = fun::http::kNotImplemented;
    return;
  }

  if (result.IsNull()) {
    response->status_code = fun::http::kNotFound;
    return;
  }

  response->status_code = fun::http::kOk;
  response->body = result.ToString();
  return;
}


void HandleDataGet(Ptr<Response> response, const Request &request,
    const Params &params, const std::string &schema) {
  const string key = params["key"];
  DLOG(INFO) << "GET /v1/data/{" << schema << "}/{" << key << "}";
  Json msg;
  Json &out = msg[schema];
  out.SetObject();

  if (!g_handler->GetData(schema, key, &out)) {
    response->status_code = fun::http::kNotImplemented;
    return;
  }

  if (out.IsNull()) {
    response->status_code = fun::http::kNotFound;
    return;
  }
  response->status_code = fun::http::kOk;
  response->body = msg.ToString();
}


bool InitializeCustomerServiceAPI(CsApiHandler *handler) {
  DLOG(INFO) << "Registering CS API handlers (v1)";
  g_handler = handler;
  BOOST_ASSERT(g_handler);

  ApiService::RegisterHandler(http::kGet,
                              boost::regex("/v1/schema/"),
                              HandleSchemaList);
  ApiService::RegisterHandler(http::kGet,
                              boost::regex("/v1/schema/(?<name>[A-Za-z_]+)"),
                              HandleSchemaGet);

  ApiService::RegisterHandler(http::kGet,
                              boost::regex("/v1/account/"),
                              HandleAccountList);
  const char *pattern = "/v1/account/(?<name>[^/]+)/(?<key>[^/]+)/";
  ApiService::RegisterHandler(http::kGet,
                              boost::regex(pattern),
                              HandleAccountGet);

  const char *pattern_cash = "/v1/account/(?<name>[^/]+)/(?<key>[^/]+)/cash";
  ApiService::RegisterHandler(http::kGet,
                              boost::regex(pattern_cash),
                              HandleAccountGetCash);
  ApiService::RegisterHandler(http::kPost,
                              boost::regex(pattern_cash),
                              HandleAccountUpdateCash);

  const char *pattern_history
      = "/v1/account/(?<name>[^/]+)/(?<key>[^/]+)/billing-history";
  ApiService::RegisterHandler(http::kGet,
                              boost::regex(pattern_history),
                              HandleAccountGetBillingHistory);

  ApiService::RegisterHandler(
      http::kGet,
      boost::regex("/v1/data/Album/(?<key>[^/]+)"),
      boost::bind(HandleDataGet, _1, _2, _3, std::string("Album")));

  ApiService::RegisterHandler(
      http::kGet,
      boost::regex("/v1/data/Character/(?<key>[^/]+)"),
      boost::bind(HandleDataGet, _1, _2, _3, std::string("Character")));

  ApiService::RegisterHandler(
      http::kGet,
      boost::regex("/v1/data/User/(?<key>[^/]+)"),
      boost::bind(HandleDataGet, _1, _2, _3, std::string("User")));

  ApiService::RegisterHandler(
      http::kGet,
      boost::regex("/v1/data/Music2/(?<key>[^/]+)"),
      boost::bind(HandleDataGet, _1, _2, _3, std::string("Music2")));

  return true;
}

}  // namespace cs_api
#endif

};  // namespace my_project
