#include "ResourceLogger.hpp"
#include <iomanip>
#include <sstream>
#include <stdexcept>

ResourceLogger::ResourceLogger(const std::string& path)
    : filePath_(path)
{
    file_.open(filePath_, std::ios::app);
    if (!file_.is_open()) {
        throw std::runtime_error("Cannot open log file");
    }
}

ResourceLogger::ResourceLogger(ResourceLogger&& other) noexcept
    : filePath_(std::move(other.filePath_))
{
    file_ = std::move(other.file_);
}

ResourceLogger& ResourceLogger::operator=(ResourceLogger&& other) noexcept
{
    if (this != &other) {
        if (file_.is_open()) {
            file_.close();
        }
        filePath_ = std::move(other.filePath_);
        file_ = std::move(other.file_);
    }
    return *this;
}

ResourceLogger::~ResourceLogger()
{
    if (file_.is_open()) {
        file_.close();
    }
}

void ResourceLogger::write(Level level, const std::string& message)
{
    if (!file_.is_open()) {
        throw std::runtime_error("File not open");
    }

    std::string timestamp = current_timestamp();
    std::string levelStr = level_to_string(level);

    file_ << "[" << timestamp << "] [" << levelStr << "] " << message << "\n";
    file_.flush();

    if (!file_) {
        throw std::runtime_error("Failed to write log");
    }
}

std::string ResourceLogger::level_to_string(Level level)
{
    switch (level) {
        case Level::INFO:    return "INFO";
        case Level::WARNING: return "WARNING";
        case Level::ERROR:   return "ERROR";
        default:             return "UNKNOWN";
    }
}

std::string ResourceLogger::current_timestamp()
{
    using namespace std::chrono;
    auto now = system_clock::now();
    std::time_t t = system_clock::to_time_t(now);

    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
