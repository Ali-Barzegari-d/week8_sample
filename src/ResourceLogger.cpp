#include "ResourceLogger.hpp"
#include <iomanip>
#include <sstream>
#include <stdexcept>

ResourceLogger::ResourceLogger(const std::string& path)
    : filePath_(path)
{
    // TODO: Open the file in append mode.
    //       If opening fails, throw std::runtime_error("Cannot open log file").
}

ResourceLogger::ResourceLogger(ResourceLogger&& other) noexcept
    : filePath_(std::move(other.filePath_))
{
    // TODO: Move file stream safely from other to this.
}

ResourceLogger& ResourceLogger::operator=(ResourceLogger&& other) noexcept
{
    // TODO: Handle self-assignment, close current file if open,
    //       then move file_ and filePath_ from other.
    return *this;
}

ResourceLogger::~ResourceLogger()
{
    // TODO: Ensure the file is properly closed.
}

void ResourceLogger::write(Level level, const std::string& message)
{
    // TODO:
    // 1. Verify that the file is open.
    // 2. Create a formatted log line: "[timestamp] [LEVEL] message"
    // 3. Write it to the file and flush.
    // 4. If any write fails, throw std::runtime_error("Failed to write log").
}

std::string ResourceLogger::level_to_string(Level level)
{
    // TODO: Convert Level enum to readable string ("INFO", "WARNING", "ERROR")
    return {};
}

std::string ResourceLogger::current_timestamp()
{
    // TODO:
    // Use std::chrono::system_clock and std::put_time to build a timestamp
    // in format "YYYY-MM-DD HH:MM:SS"
    return {};
}
