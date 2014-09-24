// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/pickle_iterator_wrapper.h"

#include <string>

#include "native_mate/arguments.h"
#include "native_mate/object_template_builder.h"

namespace {

v8::Handle<v8::Value> ThrowError(mate::Arguments* args) {
  args->ThrowTypeError("Data can not be extracted");
  return MATE_UNDEFINED(args->isolate());
}

}  // namespace

PickleIteratorWrapper::PickleIteratorWrapper(const Pickle& pickle)
    : PickleIterator(pickle) {
}

PickleIteratorWrapper::~PickleIteratorWrapper() {
}

v8::Handle<v8::Value> PickleIteratorWrapper::ReadBool(mate::Arguments* args) {
  bool r;
  if (!PickleIterator::ReadBool(&r))
    return ThrowError(args);
  return mate::ConvertToV8(args->isolate(), r);
}

v8::Handle<v8::Value> PickleIteratorWrapper::ReadInt(mate::Arguments* args) {
  int r;
  if (!PickleIterator::ReadInt(&r))
    return ThrowError(args);
  return mate::ConvertToV8(args->isolate(), r);
}

v8::Handle<v8::Value> PickleIteratorWrapper::ReadUInt32(mate::Arguments* args) {
  uint32 r;
  if (!PickleIterator::ReadUInt32(&r))
    return ThrowError(args);
  return mate::ConvertToV8(args->isolate(), r);
}

v8::Handle<v8::Value> PickleIteratorWrapper::ReadInt64(mate::Arguments* args) {
  int64 r;
  if (!PickleIterator::ReadInt64(&r))
    return ThrowError(args);
  return mate::ConvertToV8(args->isolate(), r);
}

v8::Handle<v8::Value> PickleIteratorWrapper::ReadUInt64(mate::Arguments* args) {
  uint64 r;
  if (!PickleIterator::ReadUInt64(&r))
    return ThrowError(args);
  return mate::ConvertToV8(args->isolate(), r);
}

v8::Handle<v8::Value> PickleIteratorWrapper::ReadFloat(mate::Arguments* args) {
  float r;
  if (!PickleIterator::ReadFloat(&r))
    return ThrowError(args);
  return mate::ConvertToV8(args->isolate(), r);
}

v8::Handle<v8::Value> PickleIteratorWrapper::ReadDouble(mate::Arguments* args) {
  double r;
  if (!PickleIterator::ReadDouble(&r))
    return ThrowError(args);
  return mate::ConvertToV8(args->isolate(), r);
}

v8::Handle<v8::Value> PickleIteratorWrapper::ReadString(mate::Arguments* args) {
  std::string r;
  if (!PickleIterator::ReadString(&r))
    return ThrowError(args);
  return mate::ConvertToV8(args->isolate(), r);
}

mate::ObjectTemplateBuilder PickleIteratorWrapper::GetObjectTemplateBuilder(
    v8::Isolate* isolate) {
  return mate::ObjectTemplateBuilder(isolate)
      .SetMethod("readBool", &PickleIteratorWrapper::ReadBool)
      .SetMethod("readInt", &PickleIteratorWrapper::ReadInt)
      .SetMethod("readUInt32", &PickleIteratorWrapper::ReadUInt32)
      .SetMethod("readInt64", &PickleIteratorWrapper::ReadInt64)
      .SetMethod("readUInt64", &PickleIteratorWrapper::ReadUInt64)
      .SetMethod("readFloat", &PickleIteratorWrapper::ReadFloat)
      .SetMethod("readDouble", &PickleIteratorWrapper::ReadDouble)
      .SetMethod("readString", &PickleIteratorWrapper::ReadString);
}

// static
mate::Handle<PickleIteratorWrapper> PickleIteratorWrapper::Create(
    v8::Isolate* isolate, const Pickle& pickle) {
  return mate::CreateHandle(isolate, new PickleIteratorWrapper(pickle));
}
