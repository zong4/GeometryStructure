#include "log.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace zong
{
namespace common
{

std::shared_ptr<spdlog::logger> Log::_coreLogger   = nullptr;
std::shared_ptr<spdlog::logger> Log::_clientLogger = nullptr;

void Log::init()
{
    if (_coreLogger || _clientLogger)
    {
        ZONG_CORE_INFO("the log has been init");
        return;
    }

    std::vector<spdlog::sink_ptr> logSinks;
    logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/Engine.log", true));

    logSinks[0]->set_pattern("%^[%T] %n: %v%$");
    logSinks[1]->set_pattern("[%T] [%l] %n: %v");

    _coreLogger = std::make_shared<spdlog::logger>("Engine", begin(logSinks), end(logSinks));
    spdlog::register_logger(_coreLogger);
    _coreLogger->set_level(spdlog::level::trace);
    _coreLogger->flush_on(spdlog::level::trace);

    _clientLogger = std::make_shared<spdlog::logger>("Editor", begin(logSinks), end(logSinks));
    spdlog::register_logger(_clientLogger);
    _clientLogger->set_level(spdlog::level::trace);
    _clientLogger->flush_on(spdlog::level::trace);
}

const std::shared_ptr<spdlog::logger>& Log::coreLogger()
{
    return _coreLogger;
}

const std::shared_ptr<spdlog::logger>& Log::clientLogger()
{
    return _clientLogger;
}

} // namespace common
} // namespace zong
