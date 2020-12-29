const http = require('http')
const fs = require('fs')
const path = require('path')
const fdc = require('./index')

http.createServer((req, res) => {
  if (req.url == '/lock') {
    fdc.open_device()
    fdc.lock()
    fdc.close_device()
    res.statusCode = 200
    res.end('locked')
  } else if (req.url == '/unlock') {
    fdc.open_device()
    fdc.unlock()
    fdc.close_device()
    res.statusCode = 200
    res.end('unlocked')
  } else {
    res.statusCode = 200
    res.setHeader('content-type', 'text/html')
    res.end(fs.readFileSync(path.join(__dirname, 'test.html')))
  }
}).listen(3000)

process.addListener('uncaughtException', () => {
  fdc.close_device()
})
process.addListener('beforeExit', () => {
  fdc.close_device()
})