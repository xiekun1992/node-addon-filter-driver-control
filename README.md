# node-addon-filter-driver-control
a node addon wrapper for custom Windows filter driver which locks and unlocks mouse, keyboard, touch screen input

## API
```javascript
{
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
```
## Usage
check out `test.js`
