#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include <string>
#include <map>
#include <optional>

class ConfigManager {
public:
    // Construct with a path to the configuration file.
    explicit ConfigManager(const std::string& path);

    // Retrieve a value for a given key. Return std::nullopt if not found.
    std::optional<std::string> get(const std::string& key) const;

    // Add or update a key-value pair.
    void set(const std::string& key, const std::string& value);

    // Save all current key-value pairs back to the file.
    void save() const;

private:
    std::string filePath_;
    std::map<std::string, std::string> data_;

    // Helper: load file contents into data_
    void load();

    // TODO: You may add private helper functions if needed.
};

#endif // CONFIG_MANAGER_HPP
