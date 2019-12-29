#include "filter_driver_control_wrapper.h"

fdc::FDC fdc_obj;
namespace FilterDriverControl {
  Napi::Value open_device(const Napi::CallbackInfo& info) {
    return Napi::Boolean::New(info.Env(), fdc_obj.open_device());
  }
  Napi::Value close_device(const Napi::CallbackInfo& info) {
    return Napi::Boolean::New(info.Env(), fdc_obj.close_device());
  }
  Napi::Value lock(const Napi::CallbackInfo& info) {
    return Napi::Boolean::New(info.Env(), fdc_obj.lock());
  }
  Napi::Value unlock(const Napi::CallbackInfo& info) {
    return Napi::Boolean::New(info.Env(), fdc_obj.unlock());
  }
  Napi::Object initMethods(Napi::Env env, Napi::Object exports) {
    exports.Set("openDevice", Napi::Function::New(env, FilterDriverControl::open_device));
    exports.Set("closeDevice", Napi::Function::New(env, FilterDriverControl::close_device));
    exports.Set("lock", Napi::Function::New(env, FilterDriverControl::lock));
    exports.Set("unlock", Napi::Function::New(env, FilterDriverControl::unlock));
    return exports;
  }
}