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

> just support simple echo function

### continue...
- 2016.11.24 进一步封装了，逐渐见识到了libuv的异步特性，还有一些线程上调用方法的限制不太懂

- 2016.11.28 写了初步的stage，线程

### bug_list:
1. You cannot call uv_write() or uv_read_start() from a different thread than the one that calls uv_run().
2. 某一边断开后，另一端会报段错  **deal**
3. valgrind 报错 Invalid write of size 8 位置FlowMessage::SetData
4. 为啥flow_client.cc 创建一个FlowMessage居然会导致uv_write coredump
5. server 段有可能内存泄漏的地方