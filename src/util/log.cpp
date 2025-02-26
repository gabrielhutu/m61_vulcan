#include "log.hpp"

std::mutex m61::Logger::m_mutex;

void m61::Logger::log(const std::string_view& message, const LogLevel level) 
{
    std::lock_guard<std::mutex> lock(m61::Logger::m_mutex);
    std::cout << "[" << getCurrentDateTime() << "] "
              << "[" << getLogLevelString(level) << "] "
              << message << std::endl;
    std::lock_guard<std::mutex> unlock(m61::Logger::m_mutex);
}

std::string_view m61::Logger::getLogLevelString(const LogLevel level)
{
    switch (level)
    {
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::WARNING:
        return "WARNING";
    case LogLevel::ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}
std::string_view m61::Logger::getCurrentDateTime()
{
    using namespace std::chrono;
    auto now = system_clock::now();
    std::time_t timeNow = system_clock::to_time_t(now);
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

    std::tm tm_now = *std::localtime(&timeNow);
    std::ostringstream oss;
    oss << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S")
        << "." << std::setfill('0') << std::setw(3) << ms.count();
    return (std::string_view)oss.str();
}

