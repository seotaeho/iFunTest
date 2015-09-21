// Copyright (C) 2013-2015 iFunFactory Inc. All Rights Reserved.
//
// This work is confidential and proprietary to iFunFactory Inc. and
// must not be used, disclosed, copied, or distributed without the prior
// consent of iFunFactory Inc.

// THIS FILE WAS AUTOMATICALLY GENERATED. DO NOT EDIT.

#ifndef SRC_OBJECT_MODEL_PET_H_
#define SRC_OBJECT_MODEL_PET_H_

#include <boost/enable_shared_from_this.hpp>
#include <boost/foreach.hpp>
#include <boost/noncopyable.hpp>
#include <boost/unordered_map.hpp>

#include <funapi.h>

#include <glog/logging.h>

#include "object_model/common.h"


namespace my_project {



class Pet : public ObjectProxy {
 public:
  DECLARE_CLASS_PTR(Pet);

  struct OpaqueData;

  static function<bool(const Ptr<Pet> &)> MatchByObjectId(const Object::Id &object_id);
  static function<bool(const Ptr<Pet> &)> MatchByPetLife(const int64_t &pet_life, MatchCondition cond = kEqual);
  static function<bool(const Ptr<Pet> &)> MatchByPetCode(const int64_t &pet_code, MatchCondition cond = kEqual);

  typedef function<bool(const Object::Id &/*object id*/)> TriggerCondition;
  typedef function<void(const Object::Id &/*object id*/)> TriggerAction;

  static void RegisterPetLifeTrigger(const TriggerCondition &condition, const TriggerAction &action);
  static void RegisterPetCodeTrigger(const TriggerCondition &condition, const TriggerAction &action);

  static Ptr<OpaqueData> CreateOpaqueDataFromJson(const Json &json);

  // Create// Create
  static Ptr<Pet> Create();

  // Fetch by object id
  static Ptr<Pet> Fetch(
      const Object::Id &id,
      LockType lock_type = kWriteLock) ROLLBACK;
  static void Fetch(
      const std::vector<Object::Id> &ids,
      std::vector<std::pair<Object::Id, Ptr<Pet> > > *result,
      LockType lock_type = kWriteLock) ROLLBACK;

  bool IsNull() const;

  bool IsFresh() const;
  bool Refresh() ROLLBACK;

  const Object::Id &Id() const;

  void Delete();

  bool PopulateFrom(const Ptr<OpaqueData> &opaque_data);

  // Getter/Setter for 'PetLife' attribute
  int64_t GetPetLife() const;
  void SetPetLife(const int64_t &value);

  // Getter/Setter for 'PetCode' attribute
  int64_t GetPetCode() const;
  void SetPetCode(const int64_t &value);

 private:
  Pet(const Ptr<Object> &object);
};


template <>
inline Ptr<Pet> ConvertTo<Ptr<Pet> >(const AttributeValue &v) {
  BOOST_ASSERT(v.IsObject());
  if (v.GetObject() == Object::kNullId) {
    return Pet::kNullPtr;
  }
  return Pet::Fetch(v.GetObject());
}


template <>
inline AttributeValue ConvertTo<Ptr<Pet> >(const Ptr<Pet> &v) {
  if (not v) {
    return AttributeValue(Object::kNullId);
  }
  return AttributeValue(v->Id());
}

};  // namespace my_project

#endif  // SRC_OBJECT_MODEL_PET_H_
