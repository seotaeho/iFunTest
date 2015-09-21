// Copyright (C) 2013-2015 iFunFactory Inc. All Rights Reserved.
//
// This work is confidential and proprietary to iFunFactory Inc. and
// must not be used, disclosed, copied, or distributed without the prior
// consent of iFunFactory Inc.

// THIS FILE WAS AUTOMATICALLY GENERATED. DO NOT EDIT.

#ifndef SRC_OBJECT_MODEL_ALBUM_H_
#define SRC_OBJECT_MODEL_ALBUM_H_

#include <boost/enable_shared_from_this.hpp>
#include <boost/foreach.hpp>
#include <boost/noncopyable.hpp>
#include <boost/unordered_map.hpp>

#include <funapi.h>

#include <glog/logging.h>

#include "object_model/common.h"


namespace my_project {



class Album : public ObjectProxy {
 public:
  DECLARE_CLASS_PTR(Album);

  struct OpaqueData;

  static function<bool(const Ptr<Album> &)> MatchByObjectId(const Object::Id &object_id);
  static function<bool(const Ptr<Album> &)> MatchByAlbumID(const string &albumid, MatchCondition cond = kEqual);
  static function<bool(const Ptr<Album> &)> MatchByAlbumTitle(const string &album_title, MatchCondition cond = kEqual);

  typedef function<bool(const Object::Id &/*object id*/)> TriggerCondition;
  typedef function<void(const Object::Id &/*object id*/)> TriggerAction;

  static void RegisterAlbumIDTrigger(const TriggerCondition &condition, const TriggerAction &action);
  static void RegisterAlbumTitleTrigger(const TriggerCondition &condition, const TriggerAction &action);

  static Ptr<OpaqueData> CreateOpaqueDataFromJson(const Json &json);

  // Create// Create
  static Ptr<Album> Create(const string &albumid) ROLLBACK;

  // Fetch by object id
  static Ptr<Album> Fetch(
      const Object::Id &id,
      LockType lock_type = kWriteLock) ROLLBACK;
  static void Fetch(
      const std::vector<Object::Id> &ids,
      std::vector<std::pair<Object::Id, Ptr<Album> > > *result,
      LockType lock_type = kWriteLock) ROLLBACK;

  // Fetch by AlbumID
  static Ptr<Album> FetchByAlbumID(
      const string &value,
      LockType lock_type = kWriteLock) ROLLBACK;
  static void FetchByAlbumID(
      const std::vector<string> &values,
      std::vector<std::pair<string, Ptr<Album> > > *result,
      LockType lock_type = kWriteLock) ROLLBACK;

  bool IsNull() const;

  bool IsFresh() const;
  bool Refresh() ROLLBACK;

  const Object::Id &Id() const;

  void Delete();

  bool PopulateFrom(const Ptr<OpaqueData> &opaque_data);

  // Getter/Setter for 'AlbumID' attribute
  string GetAlbumID() const;
  void SetAlbumID(const string &value);

  // Getter/Setter for 'AlbumTitle' attribute
  string GetAlbumTitle() const;
  void SetAlbumTitle(const string &value);

 private:
  Album(const Ptr<Object> &object);
};


template <>
inline Ptr<Album> ConvertTo<Ptr<Album> >(const AttributeValue &v) {
  BOOST_ASSERT(v.IsObject());
  if (v.GetObject() == Object::kNullId) {
    return Album::kNullPtr;
  }
  return Album::Fetch(v.GetObject());
}


template <>
inline AttributeValue ConvertTo<Ptr<Album> >(const Ptr<Album> &v) {
  if (not v) {
    return AttributeValue(Object::kNullId);
  }
  return AttributeValue(v->Id());
}

};  // namespace my_project

#endif  // SRC_OBJECT_MODEL_ALBUM_H_
