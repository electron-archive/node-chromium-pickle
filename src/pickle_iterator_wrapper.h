// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SRC_PICKLE_ITERATOR_WRAPPER_H_
#define SRC_PICKLE_ITERATOR_WRAPPER_H_

#include "native_mate/handle.h"
#include "native_mate/wrappable.h"
#include "src/pickle.h"

namespace mate {
class Arguments;
}

class PickleIteratorWrapper : public mate::Wrappable,
                              public PickleIterator {
 public:
  static mate::Handle<PickleIteratorWrapper> Create(
      v8::Isolate* isolate, const Pickle& pickle);

 protected:
  explicit PickleIteratorWrapper(const Pickle& pickle);
  virtual ~PickleIteratorWrapper();

  v8::Handle<v8::Value> ReadBool(mate::Arguments* args);
  v8::Handle<v8::Value> ReadInt(mate::Arguments* args);
  v8::Handle<v8::Value> ReadUInt32(mate::Arguments* args);
  v8::Handle<v8::Value> ReadInt64(mate::Arguments* args);
  v8::Handle<v8::Value> ReadUInt64(mate::Arguments* args);
  v8::Handle<v8::Value> ReadFloat(mate::Arguments* args);
  v8::Handle<v8::Value> ReadDouble(mate::Arguments* args);
  v8::Handle<v8::Value> ReadString(mate::Arguments* args);

  // mate::Wrappable:
  virtual mate::ObjectTemplateBuilder GetObjectTemplateBuilder(
      v8::Isolate* isolate);

 private:
  DISALLOW_COPY_AND_ASSIGN(PickleIteratorWrapper);
};

#endif  // SRC_PICKLE_ITERATOR_WRAPPER_H_
