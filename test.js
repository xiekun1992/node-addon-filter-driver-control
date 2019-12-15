const http = require('http')
const fdc = require('./index')

fdc.open_device()

http.createServer((req, res) => {
  if (req.url == '/lock') {
    fdc.lock()
    res.statusCode = 200
    res.end('locked')
  } else if (req.url == '/unlock') {
    fdc.unlock()
    res.statusCode = 200
    res.end('unlocked')
  } else {
    res.statusCode = 404
    res.end()
  }
}).listen(3000)

process.addListener('uncaughtException', () => {
  fdc.close_device()
})
process.addListener('beforeExit', () => {
  fdc.close_device()
})