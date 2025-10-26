#ifndef RESOURCE_LOGGER_HPP
#define RESOURCE_LOGGER_HPP

#include <string>
#include <fstream>
#include <chrono>

class ResourceLogger {
public:
    enum class Level {
        INFO,
        WARNING,
        ERROR
    };

    // Constructor: open the file in append mode
    explicit ResourceLogger(const std::string& path);

    // Deleted copy operations (RAII class)
    ResourceLogger(const ResourceLogger&) = delete;
    ResourceLogger& operator=(const ResourceLogger&) = delete;

    // Movable
    ResourceLogger(ResourceLogger&& other) noexcept;
    ResourceLogger& operator=(ResourceLogger&& other) noexcept;

    // Destructor closes file safely
    ~ResourceLogger();

    // Write message with a given log level
    void write(Level level, const std::string& message);

private:
    std::ofstream file_;
    std::string filePath_;

    // Helper: convert Level to string
    static std::string level_to_string(Level level);

    // Helper: get current time formatted as YYYY-MM-DD HH:MM:SS
    static std::string current_timestamp();

    // TODO: Add any other private helper methods if needed
};

#endif // RESOURCE_LOGGER_HPP
