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

#ifdef DEBUG
/// <summary>
/// core log, basic information
/// </summary>
inline void CORE_TRACE(std::string const& msg)
{
    common::Log::coreLogger()->trace(msg);
    return;
}

/// <summary>
/// core log, need be optimized
/// </summary>
inline void CORE_INFO(std::string const& msg)
{
    common::Log::coreLogger()->info(msg);
    return;
}

/// <summary>
/// core log, need be controled by user
/// </summary>
inline void CORE_WARN(std::string const& msg)
{
    common::Log::coreLogger()->warn(msg);
    return;
}

/// <summary>
/// core log, error
/// </summary>
inline void CORE_ERROR(std::string const& msg)
{
    common::Log::coreLogger()->error(msg);
    return;
}

/// <summary>
/// core log, serious error
/// </summary>
inline void CORE_CRITICAL(std::string const& msg)
{
    common::Log::coreLogger()->critical(msg);
    return;
}

/// <summary>
/// client log, basic information
/// </summary>
inline void CLIENT_TRACE(std::string const& msg)
{
    common::Log::clientLogger()->trace(msg);
    return;
}

/// <summary>
/// client log, need be optimized
/// </summary>
inline void CLIENT_INFO(std::string const& msg)
{
    common::Log::clientLogger()->info(msg);
    return;
}

/// <summary>
/// client log, need be controled by user
/// </summary>
inline void CLIENT_WARN(std::string const& msg)
{
    common::Log::clientLogger()->warn(msg);
    return;
}

/// <summary>
/// client log, error
/// </summary>
inline void CLIENT_ERROR(std::string const& msg)
{
    common::Log::clientLogger()->error(msg);
    return;
}

/// <summary>
/// client log, serious error
/// </summary>
inline void CLIENT_CRITICAL(std::string const& msg)
{
    common::Log::clientLogger()->critical(msg);
    return;
}
#elif RELEASE
inline void CORE_TRACE(std::string const& msg)
{
    return;
}

inline void CORE_INFO(std::string const& msg)
{
    return;
}

inline void CORE_WARN(std::string const& msg)
{
    return;
}

inline void CORE_ERROR(std::string const& msg)
{
    return;
}

inline void CORE_CRITICAL(std::string const& msg)
{
    return;
}

inline void CLIENT_TRACE(std::string const& msg)
{
    return;
}

inline void CLIENT_INFO(std::string const& msg)
{
    return;
}

inline void CLIENT_WARN(std::string const& msg)
{
    return;
}

inline void CLIENT_ERROR(std::string const& msg)
{
    return;
}

inline void CLIENT_CRITICAL(std::string const& msg)
{
    return;
}
#endif

} // namespace zong
