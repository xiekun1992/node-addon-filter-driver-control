#include <napi.h>
#include "filter_driver_control_wrapper.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  FilterDriverControl::initMethods(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll);