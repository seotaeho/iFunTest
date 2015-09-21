// Copyright (C) 2013-2015 iFunFactory Inc. All Rights Reserved.
//
// This work is confidential and proprietary to iFunFactory Inc. and
// must not be used, disclosed, copied, or distributed without the prior
// consent of iFunFactory Inc.

// THIS FILE WAS AUTOMATICALLY GENERATED. DO NOT EDIT.

#ifndef SRC_OBJECT_MODEL_USER_H_
#define SRC_OBJECT_MODEL_USER_H_

#include <boost/enable_shared_from_this.hpp>
#include <boost/foreach.hpp>
#include <boost/noncopyable.hpp>
#include <boost/unordered_map.hpp>

#include <funapi.h>

#include <glog/logging.h>

#include "object_model/common.h"


namespace my_project {

class Character;


class User : public ObjectProxy {
 public:
  DECLARE_CLASS_PTR(User);

  struct OpaqueData;

  static function<bool(const Ptr<User> &)> MatchByObjectId(const Object::Id &object_id);
  static function<bool(const Ptr<User> &)> MatchById(const string &id, MatchCondition cond = kEqual);
  static function<bool(const Ptr<User> &)> MatchByMyCharacter(const function<bool(const Ptr<Character> &)> &match);

  typedef function<bool(const Object::Id &/*object id*/)> TriggerCondition;
  typedef function<void(const Object::Id &/*object id*/)> TriggerAction;

  static void RegisterIdTrigger(const TriggerCondition &condition, const TriggerAction &action);
  static void RegisterMyCharacterTrigger(const TriggerCondition &condition, const TriggerAction &action);

  static Ptr<OpaqueData> CreateOpaqueDataFromJson(const Json &json);

  // Create// Create
  static Ptr<User> Create(const string &id) ROLLBACK;

  // Fetch by object id
  static Ptr<User> Fetch(
      const Object::Id &id,
      LockType lock_type = kWriteLock) ROLLBACK;
  static void Fetch(
      const std::vector<Object::Id> &ids,
      std::vector<std::pair<Object::Id, Ptr<User> > > *result,
      LockType lock_type = kWriteLock) ROLLBACK;

  // Fetch by Id
  static Ptr<User> FetchById(
      const string &value,
      LockType lock_type = kWriteLock) ROLLBACK;
  static void FetchById(
      const std::vector<string> &values,
      std::vector<std::pair<string, Ptr<User> > > *result,
      LockType lock_type = kWriteLock) ROLLBACK;

  bool IsNull() const;

  bool IsFresh() const;
  bool Refresh() ROLLBACK;

  const Object::Id &Id() const;

  void Delete();

  bool PopulateFrom(const Ptr<OpaqueData> &opaque_data);

  // Getter/Setter for 'Id' attribute
  string GetId() const;
  void SetId(const string &value);

  // Getter/Setter for 'MyCharacter' attribute
  Ptr<Character> GetMyCharacter() const;
  void SetMyCharacter(const Ptr<Character> &value);
  void DeleteMyCharacter(bool delete_object = true);

 private:
  User(const Ptr<Object> &object);
};


template <>
inline Ptr<User> ConvertTo<Ptr<User> >(const AttributeValue &v) {
  BOOST_ASSERT(v.IsObject());
  if (v.GetObject() == Object::kNullId) {
    return User::kNullPtr;
  }
  return User::Fetch(v.GetObject());
}


template <>
inline AttributeValue ConvertTo<Ptr<User> >(const Ptr<User> &v) {
  if (not v) {
    return AttributeValue(Object::kNullId);
  }
  return AttributeValue(v->Id());
}

};  // namespace my_project

#endif  // SRC_OBJECT_MODEL_USER_H_
