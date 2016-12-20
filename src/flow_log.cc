#include "flow_log.h"
#include "spdlog/spdlog.h"

namespace flow {

static FlowLog& fowlog = FlowLog::Instance();  //创建对象，返回引用
std::shared_ptr<spdlog::logger> FlowLog::fow_log;  //声明

FlowLog::level_enum FlowLog::Trace    = spdlog::level::trace;
FlowLog::level_enum FlowLog::Debug    = spdlog::level::debug;
FlowLog::level_enum FlowLog::Info     = spdlog::level::info;
FlowLog::level_enum FlowLog::Warm     = spdlog::level::warn;
FlowLog::level_enum FlowLog::Err      = spdlog::level::err;
FlowLog::level_enum FlowLog::Critical = spdlog::level::critical;
FlowLog::level_enum FlowLog::Off      = spdlog::level::off;

}