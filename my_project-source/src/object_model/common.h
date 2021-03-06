// Copyright (C) 2013-2015 iFunFactory Inc. All Rights Reserved.
//
// This work is confidential and proprietary to iFunFactory Inc. and
// must not be used, disclosed, copied, or distributed without the prior
// consent of iFunFactory Inc.

// THIS FILE WAS AUTOMATICALLY GENERATED. DO NOT EDIT.

#ifndef SRC_OBJECT_MODEL_COMMON_H
#define SRC_OBJECT_MODEL_COMMON_H

#include <boost/enable_shared_from_this.hpp>
#include <boost/foreach.hpp>
#include <boost/noncopyable.hpp>
#include <boost/unordered_map.hpp>

#include <funapi.h>

#include <glog/logging.h>


namespace my_project {

class Album;
class Pet;
class Character;
class User;
class Music2;


enum MatchCondition {
  kEqual = 0,
  kLess,
  kGreater
};


template <typename T>
T ConvertTo(const AttributeValue &v);


template <>
inline bool ConvertTo<bool>(const AttributeValue &v) {
  BOOST_ASSERT(v.IsBoolean());
  return v.GetBoolean();
}


template <>
inline int64_t ConvertTo<int64_t>(const AttributeValue &v) {
  BOOST_ASSERT(v.IsInteger());
  return v.GetInteger();
}


template <>
inline double ConvertTo<double>(const AttributeValue &v) {
  BOOST_ASSERT(v.IsDouble());
  return v.GetDouble();
}


template <>
inline string ConvertTo<string>(const AttributeValue &v) {
  BOOST_ASSERT(v.IsString());
  return v.GetString();
}


template <>
inline Object::Id ConvertTo<Object::Id>(const AttributeValue &v) {
  BOOST_ASSERT(v.IsObject());
  return v.GetObject();
}


template <typename T>
AttributeValue ConvertTo(const T &v) {
  return AttributeValue(v);
}


template <typename T>
class ArrayRef {
 public:
  ArrayRef(const Ptr<Object> &owner, const string &attribute_name);

  size_t Size() const;
  T GetAt(size_t index) const;
  void SetAt(size_t index, const T &value);
  void InsertAt(size_t index, const T &value);
  void EraseAt(size_t index, bool delete_object = true);
  bool Has(size_t index) const;
  void Match(const function<bool(const T &)> &match, std::vector<T> *values) const;
  size_t Count(const function<bool(const T &)> &match) const;
  void Clear(bool delete_object = true);

  T Front() const;
  T Back() const;
  void PushFront(const T &value);
  void PushBack(const T &value);

  int64_t FindFirstEmptySlot() const;

 private:
  Ptr<Object> owner_;
  const string attribute_name_;
};


template <typename T>
ArrayRef<T>::ArrayRef(
    const Ptr<Object> &owner, const string &attribute_name)
    : owner_(owner), attribute_name_(attribute_name) {
}


template <typename T>
size_t ArrayRef<T>::Size() const {
  return owner_->GetArraySize(attribute_name_);
}


template <typename T>
void ArrayRef<T>::EraseAt(size_t index, bool delete_object) {
  owner_->EraseArrayElement(attribute_name_, index, delete_object);
}


template <typename T>
bool ArrayRef<T>::Has(size_t index) const {
  return index >= 0 && index < Size();
}


template <typename T>
void ArrayRef<T>::Match(const function<bool(const T &)> &match, std::vector<T> *values) const {
  BOOST_ASSERT(match);
  BOOST_ASSERT(values);
  const size_t size = Size();
  for (size_t i = 0; i < size; ++i) {
    T value = GetAt(i);
    if (match(value)) {
      values->push_back(value);
    }
  }
}


template <typename T>
size_t ArrayRef<T>::Count(const function<bool(const T &)> &match) const {
  BOOST_ASSERT(match);
  size_t count = 0;
  const size_t size = Size();
  for (size_t i = 0; i < size; ++i) {
    T value = GetAt(i);
    if (match(value)) {
      ++count;
    }
  }
  return count;
}


template <typename T>
void ArrayRef<T>::Clear(bool delete_object) {
  size_t size = Size();
  for (size_t i = 1; i <= size; ++i) {
    EraseAt(size - i, delete_object);
  }
  BOOST_ASSERT(Size() == 0);
}


template <typename T>
int64_t ArrayRef<T>::FindFirstEmptySlot() const {
  return owner_->FindFirstEmptyArraySlot(attribute_name_, ConvertTo<>(T()));
}


template <typename KeyType, typename ValueType>
class MapRefBase {
 public:
  MapRefBase(const Ptr<Object> &owner, const string &attribute_name);

  ValueType GetAt(const KeyType &key) const;
  void SetAt(const KeyType &key, const ValueType &value);
  bool EraseAt(const KeyType &key, bool delete_object = true);
  bool Has(const KeyType &key) const;
  void Clear(bool delete_object = true);

  std::vector<KeyType> Keys() const;

 protected:
  Ptr<Object> owner_;
  const string attribute_name_;
};


template <typename KeyType, typename ValueType>
class MapRef : public MapRefBase<KeyType, ValueType> {
 public:
  MapRef(const Ptr<Object> &owner, const string &attribute_name);

  // see 'class MapRefBase'
};


template <typename ValueType>
class MapRef<int64_t, ValueType> : public MapRefBase<int64_t, ValueType> {
 public:
  MapRef(const Ptr<Object> &owner, const string &attribute_name);

  // see 'class MapRefBase'

  int64_t FindFirstEmptySlot() const;
};


template <typename KeyType, typename ValueType>
MapRefBase<KeyType, ValueType>::MapRefBase(
    const Ptr<Object> &owner, const string &attribute_name)
    : owner_(owner), attribute_name_(attribute_name) {
}


template <typename KeyType, typename ValueType>
ValueType MapRefBase<KeyType, ValueType>::GetAt(const KeyType &key) const {
  Ptr<AttributeValue> r =
      owner_->GetMapElement(attribute_name_, AttributeValue(key));
  LOG_IF(FATAL, not r) << "wrong key: " << key;
  return ConvertTo<ValueType>(*r);
}


template <typename KeyType, typename ValueType>
void MapRefBase<KeyType, ValueType>::SetAt(const KeyType &key, const ValueType &value) {
  owner_->SetMapElement(
      attribute_name_,
      AttributeValue(key),
      Ptr<AttributeValue>(new AttributeValue(ConvertTo<>(value))));
}


template <typename KeyType, typename ValueType>
bool MapRefBase<KeyType, ValueType>::EraseAt(const KeyType &key, bool delete_object) {
  return owner_->EraseMapElement(
      attribute_name_, AttributeValue(key), delete_object);
}


template <typename KeyType, typename ValueType>
bool MapRefBase<KeyType, ValueType>::Has(const KeyType &key) const {
  return owner_->HasMapElement(
      attribute_name_, AttributeValue(key));
}


template <typename KeyType, typename ValueType>
void MapRefBase<KeyType, ValueType>::Clear(bool delete_object) {
  std::vector<KeyType> keys = Keys();
  BOOST_FOREACH(const KeyType &v, keys) {
    if (EraseAt(v, delete_object) == false) {
      BOOST_ASSERT(false);
    }
  }
}


template <typename KeyType, typename ValueType>
std::vector<KeyType> MapRefBase<KeyType, ValueType>::Keys() const {
  std::vector<AttributeValue> keys1;
  std::vector<KeyType> keys2;
  owner_->GetMapKeys(attribute_name_, &keys1);
  BOOST_FOREACH(const AttributeValue &v, keys1) {
    keys2.push_back(ConvertTo<KeyType>(v));
  }
  return keys2;
}


template <typename KeyType, typename ValueType>
MapRef<KeyType, ValueType>::MapRef(
    const Ptr<Object> &owner, const string &attribute_name)
    : MapRefBase<KeyType, ValueType>(owner, attribute_name) {
}


template <typename ValueType>
MapRef<int64_t, ValueType>::MapRef(
    const Ptr<Object> &owner, const string &attribute_name)
    : MapRefBase<int64_t, ValueType>(owner, attribute_name) {
}


template <typename ValueType>
int64_t MapRef<int64_t, ValueType>::FindFirstEmptySlot() const {
  return MapRef<int64_t, ValueType>::owner_->FindFirstEmptySlot(
      MapRef<int64_t, ValueType>::attribute_name_);
}


void ObjectModelInit();

#ifdef ENABLE_FUNAPI_CS_API

namespace cs_api {

// serialize (database) object as JSON document
void DumpJson(my_project::Album &obj, Json &out);
void DumpJson(my_project::Pet &obj, Json &out);
void DumpJson(my_project::Character &obj, Json &out);
void DumpJson(my_project::User &obj, Json &out);
void DumpJson(my_project::Music2 &obj, Json &out);


// read database object as JSON document
bool FetchAlbum(const std::string &key, Json &out);
bool FetchCharacter(const std::string &key, Json &out);
bool FetchUser(const std::string &key, Json &out);
bool FetchMusic2(const std::string &key, Json &out);


class CsApiHandler {
 public:
  CsApiHandler();
  virtual ~CsApiHandler();

  // return available schema-types in `result`
  virtual bool GetSchemaList(std::vector<std::string> *result);
  // return JSON-schema for `schema_name` in `result`
  virtual bool ShowSchema(
      const std::string& schema_name, std::string *result);
  // get available account-types in `result`
  //   default implementation will raise '501' error
  virtual bool GetAccountTypes(std::vector<std::string> *result);
  // get account-data for user `uid` in `result`
  //   default implementation will raise '501' error
  virtual bool GetAccount(const std::string &account_type,
      const std::string &uid, fun::Json *result);

  virtual bool GetData(const std::string &schema_type,
      const std::string &key, fun::Json *result);

  // cash handlers
  virtual bool GetAccountCash(const std::string &account_type,
      const std::string &uid, fun::Json *result);

  virtual bool UpdateAccountCash(const std::string &account_type,
      const std::string &uid, const fun::Json &cash, fun::Json *result);

  // get billing history from iFunEngine billing service
  //    result should contain "billing_history", which is a array of,
  //    {"product_id": "{id-of-product}",
  //     "quantity": 1,  // # of items
  //     "store_timestamp": 123456789,  // unix timestamp (from store)
  //     "server_timestamp": 123456789}  // unix timestamp (from game-server)
  virtual bool GetAccountBillingHistory(const std::string &account_type,
      const std::string &uid, int64_t from_ts, int64_t until_ts,
      fun::Json *result);

 protected:
  virtual const std::string &GetBillerUrl() const;
  virtual bool GetHistoryFromBiller(const std::string &key, int64_t from_ts,
      int64_t until_ts, fun::Json *result) const;

 protected:
  // list of defined schemas (name, schema as stringified JSON)
  typedef boost::unordered_map<std::string, std::string> schema_map;
  const schema_map schemas_;

  // getters for database object
  typedef boost::unordered_map<
      std::string, boost::function<bool (const std::string&, Json&)> >
      getter_map;
  const getter_map getters_;
};


// handler: // (possibly inherited) instance of CsApiHandler
//    caller should deallocate the handler object after termination
bool InitializeCustomerServiceAPI(CsApiHandler *handler);

}  // namespace cs_api
#endif

};  // namespace my_project

#endif  // SRC_OBJECT_MODEL_COMMON_H
