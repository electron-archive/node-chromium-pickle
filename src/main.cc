// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "native_mate/arguments.h"
#include "native_mate/dictionary.h"
#include "node.h"
#include "node_buffer.h"
#include "src/pickle_wrapper.h"

namespace {

v8::Handle<v8::Value> CreatePickleFromBuffer(
    mate::Arguments* args, v8::Handle<v8::Object> buffer) {
  if (!node::Buffer::HasInstance(buffer)) {
    args->ThrowTypeError("Can only create from Buffer");
    return MATE_UNDEFINED(args->isolate());
  }

  return PickleWrapper::CreateFrom(
      args->isolate(),
      node::Buffer::Data(buffer),
      node::Buffer::Length(buffer)).ToV8();
}

void Init(v8::Handle<v8::Object> exports) {
  mate::Dictionary dict(v8::Isolate::GetCurrent(), exports);
  dict.SetMethod("createEmpty", PickleWrapper::Create);
  dict.SetMethod("createFromBuffer", CreatePickleFromBuffer);
}

}  // namespace

NODE_MODULE(pickle, Init)
