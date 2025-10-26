#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include <string>
#include <map>
#include <optional>

class ConfigManager {
public:
    explicit ConfigManager(const std::string& path);

    std::optional<std::string> get(const std::string& key) const;
    void set(const std::string& key, const std::string& value);
    void save() const;

private:
    std::string filePath_;
    std::map<std::string, std::string> data_;

    void load();
};

#endif // CONFIG_MANAGER_HPP
