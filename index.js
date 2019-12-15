const fdc = require('./build/Release/filter_driver_control.node')

module.exports = {
  open_device() {
    return fdc.openDevice()
  },
  lock() {
    return fdc.lock()
  },
  unlock() {
    return fdc.unlock()
  },
  close_device() {
    return fdc.closeDevice()
  }
}