# Flow
this is a net framework used for asynchronous message communication

### install
1. install libuv in ordinary directory
2. git clone this project
3. cd build && cmake .. && make

### run
- cd bin
- ./server    run server
- ./client    run client
just support simple echo function

### continue...
进一步封装了，逐渐见识到了libuv的异步特性，还有一些线程上调用方法的限制不太懂
You cannot call uv_write() or uv_read_start() from a different thread than the one that calls uv_run().
