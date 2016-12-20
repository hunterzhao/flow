#ifndef FLOW_FRAMEWORK_FLOW_LOG_H
#define FLOW_FRAMEWORK_FLOW_LOG_H

#include <iostream>
#include "spdlog/spdlog.h"
#include "singleton.h"

namespace flow {
class FlowLog : public Singleton<FlowLog> {
public:
	friend class Singleton<FlowLog>;
    typedef spdlog::level::level_enum level_enum ;
    
    static level_enum Trace;
    static level_enum Debug;
    static level_enum Info;
    static level_enum Warm;
    static level_enum Err;
    static level_enum Critical;
    static level_enum Off;

    static void SetLevel(level_enum lev) {
    	spdlog::set_level(lev);
    }
   
    ~FlowLog() {
    	spdlog::drop_all();
    }
     
    static std::shared_ptr<spdlog::logger> fow_log;

private:
    FlowLog() {
        fow_log = spdlog::stdout_color_mt("console");
        //fow_log = spdlog::daily_logger_mt("app", "../log", 0, 0);
    }
};
} // end of namespace
#define LOG flow::FlowLog::fow_log
#define FLOWLOG_TRY try
#define FLOWLOG_CATCH catch (spdlog::spdlog_ex& ex) {      \
    std::cout << "Log failed: " << ex.what() << std::endl;}   

#endif //FLOW_FRAMEWORK_FLOW_LOG_H

// C++为类中提供类成员的初始化列表
// 类对象的构造顺序是这样的：
// 1.分配内存，调用构造函数时，隐式／显示的初始化各数据成员
// 2.进入构造函数后在构造函数中执行一般计算
//   1.类里面的任何成员变量在定义时是不能初始化的。
//   2.一般的数据成员可以在构造函数中初始化。
//   3.const数据成员必须在构造函数的初始化列表中初始化。
//   4.static要在类的定义外面初始化。   
//   5.数组成员是不能在初始化列表里初始化的。
//   6.不能给数组指定明显的初始化。  