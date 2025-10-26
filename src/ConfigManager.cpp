#include "ConfigManager.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

ConfigManager::ConfigManager(const std::string& path)
    : filePath_(path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    file.close();
    load();
}

void ConfigManager::load()
{
    data_.clear();
    std::ifstream file(filePath_);
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::size_t pos = line.find('=');
        if (pos == std::string::npos) continue; // skip malformed lines

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        data_[key] = value;
    }
}

std::optional<std::string> ConfigManager::get(const std::string& key) const
{
    auto it = data_.find(key);
    if (it != data_.end())
        return it->second;
    return std::nullopt;
}

void ConfigManager::set(const std::string& key, const std::string& value)
{
    data_[key] = value;
}

void ConfigManager::save() const
{
    std::ofstream file(filePath_, std::ios::trunc);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot save file");
    }

    for (const auto& [key, value] : data_) {
        file << key << "=" << value << "\n";
    }
}
