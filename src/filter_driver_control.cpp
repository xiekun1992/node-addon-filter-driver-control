#include "filter_driver_control.h"

namespace fdc {
  FDC::FDC() {}
  FDC::~FDC() {}
  bool FDC::open_device() {
    device_handle = CreateFileW(L"\\\\.\\F3dBlockerSymbol", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_SYSTEM, NULL);
    if (device_handle == INVALID_HANDLE_VALUE) { // -1
      return false; 
    }
    return true;
  }
  bool FDC::lock() {
    if (device_handle > 0) {
      DWORD a = 0, b = 0, read_bytes = 0;
      DeviceIoControl(device_handle, IOCTL_LOCK, &a, sizeof(a), &b, sizeof(b), &read_bytes, NULL);
      return true;
    }
    return false;
  }
  bool FDC::unlock() {
    if (device_handle > 0) {
      DWORD a = 0, b = 0, read_bytes = 0;
      DeviceIoControl(device_handle, IOCTL_UNLOCK, &a, sizeof(a), &b, sizeof(b), &read_bytes, NULL);
      return true;
    }
    return false;
  }
  bool FDC::close_device() {
    if (device_handle > 0) {
      if (CloseHandle(device_handle) != 0) {
        return true;
      }
    }
    return false;
  }
}