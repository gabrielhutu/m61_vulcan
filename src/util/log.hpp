#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <mutex>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace m61
{


    enum class LogLevel
    {
        INFO,
        WARNING,
        ERROR
    };

    class Logger
    {
    public:
        static void log(const std::string_view &message, const LogLevel level);
    private:
        
        static std::mutex m_mutex;

        static std::string_view getLogLevelString(const LogLevel level);

        static std::string_view getCurrentDateTime();
    };

}

#endif // LOG_HPP