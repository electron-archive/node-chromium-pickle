// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "native_mate/dictionary.h"
#include "node.h"
#include "src/pickle_wrapper.h"

namespace {

void Init(v8::Handle<v8::Object> exports) {
  mate::Dictionary dict(v8::Isolate::GetCurrent(), exports);
  dict.SetMethod("createEmpty", PickleWrapper::Create);
}

}  // namespace

NODE_MODULE(pickle, Init)
