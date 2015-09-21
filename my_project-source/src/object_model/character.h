// Copyright (C) 2013-2015 iFunFactory Inc. All Rights Reserved.
//
// This work is confidential and proprietary to iFunFactory Inc. and
// must not be used, disclosed, copied, or distributed without the prior
// consent of iFunFactory Inc.

// THIS FILE WAS AUTOMATICALLY GENERATED. DO NOT EDIT.

#ifndef SRC_OBJECT_MODEL_CHARACTER_H_
#define SRC_OBJECT_MODEL_CHARACTER_H_

#include <boost/enable_shared_from_this.hpp>
#include <boost/foreach.hpp>
#include <boost/noncopyable.hpp>
#include <boost/unordered_map.hpp>

#include <funapi.h>

#include <glog/logging.h>

#include "object_model/common.h"


namespace my_project {



class Character : public ObjectProxy {
 public:
  DECLARE_CLASS_PTR(Character);

  struct OpaqueData;

  static function<bool(const Ptr<Character> &)> MatchByObjectId(const Object::Id &object_id);
  static function<bool(const Ptr<Character> &)> MatchByName(const string &name, MatchCondition cond = kEqual);
  static function<bool(const Ptr<Character> &)> MatchByExp(const int64_t &exp, MatchCondition cond = kEqual);
  static function<bool(const Ptr<Character> &)> MatchByLevel(const int64_t &level, MatchCondition cond = kEqual);
  static function<bool(const Ptr<Character> &)> MatchByHp(const int64_t &hp, MatchCondition cond = kEqual);
  static function<bool(const Ptr<Character> &)> MatchByMp(const int64_t &mp, MatchCondition cond = kEqual);
  static function<bool(const Ptr<Character> &)> MatchBydurability(const int64_t &durability, MatchCondition cond = kEqual);

  typedef function<bool(const Object::Id &/*object id*/)> TriggerCondition;
  typedef function<void(const Object::Id &/*object id*/)> TriggerAction;

  static void RegisterNameTrigger(const TriggerCondition &condition, const TriggerAction &action);
  static void RegisterExpTrigger(const TriggerCondition &condition, const TriggerAction &action);
  static void RegisterLevelTrigger(const TriggerCondition &condition, const TriggerAction &action);
  static void RegisterHpTrigger(const TriggerCondition &condition, const TriggerAction &action);
  static void RegisterMpTrigger(const TriggerCondition &condition, const TriggerAction &action);
  static void RegisterdurabilityTrigger(const TriggerCondition &condition, const TriggerAction &action);

  static Ptr<OpaqueData> CreateOpaqueDataFromJson(const Json &json);

  // Create// Create
  static Ptr<Character> Create(const string &name) ROLLBACK;

  // Fetch by object id
  static Ptr<Character> Fetch(
      const Object::Id &id,
      LockType lock_type = kWriteLock) ROLLBACK;
  static void Fetch(
      const std::vector<Object::Id> &ids,
      std::vector<std::pair<Object::Id, Ptr<Character> > > *result,
      LockType lock_type = kWriteLock) ROLLBACK;

  // Fetch by Name
  static Ptr<Character> FetchByName(
      const string &value,
      LockType lock_type = kWriteLock) ROLLBACK;
  static void FetchByName(
      const std::vector<string> &values,
      std::vector<std::pair<string, Ptr<Character> > > *result,
      LockType lock_type = kWriteLock) ROLLBACK;

  bool IsNull() const;

  bool IsFresh() const;
  bool Refresh() ROLLBACK;

  const Object::Id &Id() const;

  void Delete();

  bool PopulateFrom(const Ptr<OpaqueData> &opaque_data);

  // Getter/Setter for 'Name' attribute
  string GetName() const;
  void SetName(const string &value);

  // Getter/Setter for 'Exp' attribute
  int64_t GetExp() const;
  void SetExp(const int64_t &value);

  // Getter/Setter for 'Level' attribute
  int64_t GetLevel() const;
  void SetLevel(const int64_t &value);

  // Getter/Setter for 'Hp' attribute
  int64_t GetHp() const;
  void SetHp(const int64_t &value);

  // Getter/Setter for 'Mp' attribute
  int64_t GetMp() const;
  void SetMp(const int64_t &value);

  // Getter/Setter for 'durability' attribute
  int64_t Getdurability() const;
  void Setdurability(const int64_t &value);

 private:
  Character(const Ptr<Object> &object);
};


template <>
inline Ptr<Character> ConvertTo<Ptr<Character> >(const AttributeValue &v) {
  BOOST_ASSERT(v.IsObject());
  if (v.GetObject() == Object::kNullId) {
    return Character::kNullPtr;
  }
  return Character::Fetch(v.GetObject());
}


template <>
inline AttributeValue ConvertTo<Ptr<Character> >(const Ptr<Character> &v) {
  if (not v) {
    return AttributeValue(Object::kNullId);
  }
  return AttributeValue(v->Id());
}

};  // namespace my_project

#endif  // SRC_OBJECT_MODEL_CHARACTER_H_
