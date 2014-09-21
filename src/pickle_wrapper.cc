// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/pickle_wrapper.h"

#include "native_mate/object_template_builder.h"

PickleWrapper::PickleWrapper() {
}

PickleWrapper::~PickleWrapper() {
}

mate::ObjectTemplateBuilder PickleWrapper::GetObjectTemplateBuilder(
    v8::Isolate* isolate) {
  return mate::ObjectTemplateBuilder(isolate);
}

// static
mate::Handle<PickleWrapper> PickleWrapper::Create(v8::Isolate* isolate) {
  return CreateHandle(isolate, new PickleWrapper);
}
