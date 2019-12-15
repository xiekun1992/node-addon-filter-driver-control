#pragma once
#ifndef _FILTER_DRIVER_CONTROL_WRAPPER
#define _FILTER_DRIVER_CONTROL_WRAPPER

#include <napi.h>
#include "../filter_driver_control.h"

namespace FilterDriverControl {
  Napi::Value open_device(const Napi::CallbackInfo& info);
  Napi::Value close_device(const Napi::CallbackInfo& info);
  Napi::Value lock(const Napi::CallbackInfo& info);
  Napi::Value unlock(const Napi::CallbackInfo& info);
  Napi::Object initMethods(Napi::Env env, Napi::Object exports);
}

#endif