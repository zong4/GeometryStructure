#pragma once

#include <memory>

// this ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#pragma warning(pop)

namespace zong
{
namespace common
{

/// <summary>
/// two loggers has different name, one is for core, and another is for editor
/// </summary>
class Log
{
private:
    static std::shared_ptr<spdlog::logger> _coreLogger;
    static std::shared_ptr<spdlog::logger> _clientLogger;

public:
    /// <summary>
    /// init loggers with two names, and set log filename
    /// </summary>
    static void init();

    static const std::shared_ptr<spdlog::logger>& coreLogger();
    static const std::shared_ptr<spdlog::logger>& clientLogger();
};

} // namespace common
} // namespace zong

/**
 * @defgroup Log Log.h debug macro
 * @{core log macros: \n
 * * ZONG_CORE_TRACE: basic information
 * * ZONG_CORE_INFO: need be optimized
 * * ZONG_CORE_WARN: should be solved
 * * ZONG_CORE_ERROR: error
 * * ZONG_CORE_CRITICAL: serious error
 *
 * client log macros: \n
 * * ZONG_TRACE: basic information
 * * ZONG_INFO: need be optimized
 * * ZONG_WARN: should be solved
 * * ZONG_ERROR: error
 * * ZONG_CRITICAL: serious error
 */

#ifdef DEBUG
  // core log macros
    #define ZONG_CORE_TRACE(...) zong::common::Log::coreLogger()->trace(__VA_ARGS__)
    #define ZONG_CORE_INFO(...) zong::common::Log::coreLogger()->info(__VA_ARGS__)
    #define ZONG_CORE_WARN(...) zong::common::Log::coreLogger()->warn(__VA_ARGS__)
    #define ZONG_CORE_ERROR(...) zong::common::Log::coreLogger()->error(__VA_ARGS__)
    #define ZONG_CORE_CRITICAL(...) zong::common::Log::coreLogger()->critical(__VA_ARGS__)

    // client log macros
    #define ZONG_TRACE(...) zong::common::Log::clientLogger()->trace(__VA_ARGS__)
    #define ZONG_INFO(...) zong::common::Log::clientLogger()->info(__VA_ARGS__)
    #define ZONG_WARN(...) zong::common::Log::clientLogger()->warn(__VA_ARGS__)
    #define ZONG_ERROR(...) zong::common::Log::clientLogger()->error(__VA_ARGS__)
    #define ZONG_CRITICAL(...) zong::common::Log::clientLogger()->critical(__VA_ARGS__)
#elif RELEASE
  // core log macros
    #define ZONG_CORE_TRACE(...)
    #define ZONG_CORE_INFO(...)
    #define ZONG_CORE_WARN(...)
    #define ZONG_CORE_ERROR(...)
    #define ZONG_CORE_CRITICAL(...)

    // client log macros
    #define ZONG_TRACE(...)
    #define ZONG_INFO(...)
    #define ZONG_WARN(...)
    #define ZONG_ERROR(...)
    #define ZONG_CRITICAL(...)
#endif

/** @} */