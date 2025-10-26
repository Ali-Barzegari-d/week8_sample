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

    explicit ResourceLogger(const std::string& path);

    ResourceLogger(const ResourceLogger&) = delete;
    ResourceLogger& operator=(const ResourceLogger&) = delete;

    ResourceLogger(ResourceLogger&& other) noexcept;
    ResourceLogger& operator=(ResourceLogger&& other) noexcept;

    ~ResourceLogger();

    void write(Level level, const std::string& message);

private:
    std::ofstream file_;
    std::string filePath_;

    static std::string level_to_string(Level level);
    static std::string current_timestamp();
};

#endif // RESOURCE_LOGGER_HPP
