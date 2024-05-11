#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "fmt/format.h"

namespace hezel
{
class Log
{
public:
    Log();
    ~Log();
    
    static void Init();
    static std::shared_ptr<spdlog::logger>& get_core_logger()
    {
        return core_logger_;
    }
    static std::shared_ptr<spdlog::logger>& get_client_logger()
    {
        return client_logger_;
    }

private:
    static std::shared_ptr<spdlog::logger> core_logger_;
    static std::shared_ptr<spdlog::logger> client_logger_;
};
}

// core log macro
#define HZ_CORE_ERROR(...) ::hezel::Log::get_core_logger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...) ::hezel::Log::get_core_logger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::hezel::Log::get_core_logger()->info(__VA_ARGS__)
#define HZ_CORE_TRACE(...) ::hezel::Log::get_core_logger()->trace(__VA_ARGS__)

// client log macro
#define HZ_CLIENT_ERROR(...) ::hezel::Log::get_client_logger()->error(__VA_ARGS__)
#define HZ_CLIENT_ERROR(...) ::hezel::Log::get_client_logger()->error(__VA_ARGS__)
#define HZ_CLIENT_WARN(...) ::hezel::Log::get_client_logger()->warn(__VA_ARGS__)
#define HZ_CLIENT_INFO(...) ::hezel::Log::get_client_logger()->info(__VA_ARGS__)
#define HZ_CLIENT_TRACE(...) ::hezel::Log::get_client_logger()->trace(__VA_ARGS__)