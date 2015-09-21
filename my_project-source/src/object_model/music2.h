// Copyright (C) 2013-2015 iFunFactory Inc. All Rights Reserved.
//
// This work is confidential and proprietary to iFunFactory Inc. and
// must not be used, disclosed, copied, or distributed without the prior
// consent of iFunFactory Inc.

// THIS FILE WAS AUTOMATICALLY GENERATED. DO NOT EDIT.

#ifndef SRC_OBJECT_MODEL_MUSIC2_H_
#define SRC_OBJECT_MODEL_MUSIC2_H_

#include <boost/enable_shared_from_this.hpp>
#include <boost/foreach.hpp>
#include <boost/noncopyable.hpp>
#include <boost/unordered_map.hpp>

#include <funapi.h>

#include <glog/logging.h>

#include "object_model/common.h"


namespace my_project {



class Music2 : public ObjectProxy {
 public:
  DECLARE_CLASS_PTR(Music2);

  struct OpaqueData;

  static function<bool(const Ptr<Music2> &)> MatchByObjectId(const Object::Id &object_id);
  static function<bool(const Ptr<Music2> &)> MatchByMusicID(const string &musicid, MatchCondition cond = kEqual);
  static function<bool(const Ptr<Music2> &)> MatchByMusicTitle(const string &music_title, MatchCondition cond = kEqual);

  typedef function<bool(const Object::Id &/*object id*/)> TriggerCondition;
  typedef function<void(const Object::Id &/*object id*/)> TriggerAction;

  static void RegisterMusicIDTrigger(const TriggerCondition &condition, const TriggerAction &action);
  static void RegisterMusicTitleTrigger(const TriggerCondition &condition, const TriggerAction &action);

  static Ptr<OpaqueData> CreateOpaqueDataFromJson(const Json &json);

  // Create// Create
  static Ptr<Music2> Create(const string &musicid) ROLLBACK;

  // Fetch by object id
  static Ptr<Music2> Fetch(
      const Object::Id &id,
      LockType lock_type = kWriteLock) ROLLBACK;
  static void Fetch(
      const std::vector<Object::Id> &ids,
      std::vector<std::pair<Object::Id, Ptr<Music2> > > *result,
      LockType lock_type = kWriteLock) ROLLBACK;

  // Fetch by MusicID
  static Ptr<Music2> FetchByMusicID(
      const string &value,
      LockType lock_type = kWriteLock) ROLLBACK;
  static void FetchByMusicID(
      const std::vector<string> &values,
      std::vector<std::pair<string, Ptr<Music2> > > *result,
      LockType lock_type = kWriteLock) ROLLBACK;

  bool IsNull() const;

  bool IsFresh() const;
  bool Refresh() ROLLBACK;

  const Object::Id &Id() const;

  void Delete();

  bool PopulateFrom(const Ptr<OpaqueData> &opaque_data);

  // Getter/Setter for 'MusicID' attribute
  string GetMusicID() const;
  void SetMusicID(const string &value);

  // Getter/Setter for 'MusicTitle' attribute
  string GetMusicTitle() const;
  void SetMusicTitle(const string &value);

 private:
  Music2(const Ptr<Object> &object);
};


template <>
inline Ptr<Music2> ConvertTo<Ptr<Music2> >(const AttributeValue &v) {
  BOOST_ASSERT(v.IsObject());
  if (v.GetObject() == Object::kNullId) {
    return Music2::kNullPtr;
  }
  return Music2::Fetch(v.GetObject());
}


template <>
inline AttributeValue ConvertTo<Ptr<Music2> >(const Ptr<Music2> &v) {
  if (not v) {
    return AttributeValue(Object::kNullId);
  }
  return AttributeValue(v->Id());
}

};  // namespace my_project

#endif  // SRC_OBJECT_MODEL_MUSIC2_H_
