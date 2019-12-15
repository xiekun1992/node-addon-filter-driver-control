#pragma once
#ifndef _NODE_ADDON_FILTER_DRIVER_CONTROL
#define _NODE_ADDON_FILTER_DRIVER_CONTROL

#include <windows.h>
#include <winioctl.h>

#define IOCTL_LOCK   CTL_CODE(FILE_DEVICE_UNKNOWN, 0x900, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_UNLOCK CTL_CODE(FILE_DEVICE_UNKNOWN, 0x901, METHOD_BUFFERED, FILE_ANY_ACCESS)

namespace fdc {
  class FDC {
    private:
      HANDLE device_handle;
    public:
      FDC();
      ~FDC();
      bool open_device();
      bool lock();
      bool unlock();
      bool close_device();
  };
}

#endif