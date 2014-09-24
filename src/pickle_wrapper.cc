// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/pickle_wrapper.h"

#include "native_mate/object_template_builder.h"
#include "node_buffer.h"

namespace mate {

template<>
struct Converter<Pickle*> {
  static bool FromV8(v8::Isolate* isolate, v8::Handle<v8::Value> val,
                     Pickle** out) {
    PickleWrapper* child;
    if (!ConvertFromV8(isolate, val, &child))
      return false;
    *out = static_cast<Pickle*>(child);
    return true;
  }
};

}  // namespace mate

PickleWrapper::PickleWrapper() {
}

PickleWrapper::PickleWrapper(const char* data, int data_len)
    : Pickle(data, data_len) {
}

PickleWrapper::~PickleWrapper() {
}

v8::Handle<v8::Value> PickleWrapper::GetData(v8::Isolate* isolate) const {
#if NODE_VERSION_AT_LEAST(0, 11, 0)
  return node::Buffer::New(
      isolate, reinterpret_cast<const char*>(data()), size());
#else
  return v8::Local<v8::Object>::New(node::Buffer::New(
      reinterpret_cast<const char*>(data()), size())->handle_);
#endif
}

mate::Handle<PickleIteratorWrapper> PickleWrapper::CreateIterator(
    v8::Isolate* isolate) const {
  return PickleIteratorWrapper::Create(isolate, *this);
}

mate::ObjectTemplateBuilder PickleWrapper::GetObjectTemplateBuilder(
    v8::Isolate* isolate) {
  return mate::ObjectTemplateBuilder(isolate)
      .SetMethod("writeBool", &PickleWrapper::WriteBool)
      .SetMethod("writeInt", &PickleWrapper::WriteInt)
      .SetMethod("writeUInt32", &PickleWrapper::WriteUInt32)
      .SetMethod("writeInt64", &PickleWrapper::WriteInt64)
      .SetMethod("writeUInt64", &PickleWrapper::WriteUInt64)
      .SetMethod("writeFloat", &PickleWrapper::WriteFloat)
      .SetMethod("writeDouble", &PickleWrapper::WriteDouble)
      .SetMethod("writeString", &PickleWrapper::WriteString)
      .SetMethod("createIterator", &PickleWrapper::CreateIterator)
      .SetMethod("toBuffer", &PickleWrapper::GetData);
}

// static
mate::Handle<PickleWrapper> PickleWrapper::Create(v8::Isolate* isolate) {
  return mate::CreateHandle(isolate, new PickleWrapper);
}

// static
mate::Handle<PickleWrapper> PickleWrapper::CreateFrom(
    v8::Isolate* isolate, const char* data, int data_len) {
  return mate::CreateHandle(isolate, new PickleWrapper(data, data_len));
}
