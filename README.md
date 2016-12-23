# Flow
this is a net framework used for asynchronous message communication

### install
1. install libuv in ordinary directory
2. git clone this project

> debug way

cd Debug && cmake -DCMAKE_BUILD_TYPE=Debug .. && make

> release way

cd Release && cmake  -DCMAKE_BUILD_TYPE=Release .. && make

### run
- cd bin
> debug way

- ./server    run serverd
- ./client    run clientd

> Release way

- ./server    run server
- ./client    run client

> just support simple echo function

### continue...
- 2016.11.24 进一步封装了，逐渐见识到了libuv的异步特性，还有一些线程上调用方法的限制不太懂

- 2016.11.28 写了初步的stage，线程

- 2016.11.30 完成线程同步工作，解决若干内存bug，stage已经正常使用

- 2016.12.8 完成session，message的json化

- 2016.12.20 完成log封装

- 2016.12.21 debug release 分离

- 单元测试，如何写出测试驱动的代码 [参考](https://www.toptal.com/qa/how-to-write-testable-code-and-why-it-matters)
  这篇文字确实不错，但是重构的代价太大了。懒得改了。。。
### TODO...
- 异步情况下，程序如何设计使用？
- server端并不会管理有哪些客户连接上来了，client端会管理有多少个connect到其他server上了
- 考虑进程如何关闭线程，干净退出

### bug_list:
1. You cannot call uv_write() or uv_read_start() from a different thread than the one that calls uv_run().
2. 某一边断开后，另一端会报段错  **deal**
3. valgrind 报错 Invalid write of size 8 位置FlowMessage::SetData **deal** 发送数据的 uv_write_t没有动态分配空间导致回调函数中无法访问
4. 为啥flow_client.cc 创建一个FlowMessage居然会导致uv_write coredump **deal** 应该是message内部的内存回收，没写好
5. server 段有可能内存泄漏的地方，可能是ctrl+c 强行终止导致的，真的有必要为了优雅关闭花费那么多时间么，数据写回磁盘才是正道，毕竟程序结束内存都归还了。
6. Exiting thread still holds 1 lock **deal** 嵌套的lock导致的
7. 为啥函数传值变成了传引用？ 尼玛，循环引用头文件发生了
8. 遇到瓶颈了，感觉工程里的头文件都是乱include的，现在换个顺序都会报不同的错误,**其实能够保证头文件自包含,避免隐含依赖就可以避免循环引用**
9. 删除了flow_session.h里面的一个前置声明class uv_steam，换成头文件;发现居然就都不报错了（前置声明滥用），我等于在flow域中又声明了一个uv_stream
10.以前没有注意到函数返回const char*问题，返回的指针指向的地址空间被归还，跑起来没有错误的原因是很幸运还这块地址空间还没有被overwitten，所以需要通过拷贝的方式才能解决这个问题
11. 注意，如果已经生成了so库，那么头文件的防止重复引用的宏就失效了，之后再次引用该头文件就会报重复定义的错误，如果你头文件里面有定义行为的话
内部链接 外部链接的区别 [参考](http://blog.csdn.net/ithzhang/article/details/8119286) 
### the most beautiful images


### beautiful images
![0 error memory](https://github.com/hunterzhao/flow/blob/master/images/happy1.png)