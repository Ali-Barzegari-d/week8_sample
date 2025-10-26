#include "ConfigManager.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

ConfigManager::ConfigManager(const std::string& path)
    : filePath_(path)
{
    // TODO: Attempt to open the file for reading.
    //       If it cannot be opened, throw std::runtime_error("File not found").
    //       Otherwise, call load().
}

void ConfigManager::load()
{
    // TODO: Clear existing data_.
    //       Read the file line by line.
    //       Each line has format "key=value".
    //       Ignore empty lines.
    //       Split at the first '=' and store into data_.
    //       Use RAII: file closes automatically when ifstream goes out of scope.
}

std::optional<std::string> ConfigManager::get(const std::string& key) const
{
    // TODO: Search for key in data_.
    //       If found, return the value.
    //       Otherwise, return std::nullopt.
    return std::nullopt;
}

void ConfigManager::set(const std::string& key, const std::string& value)
{
    // TODO: Insert or update (key, value) in the map.
}

void ConfigManager::save() const
{
    // TODO: Open file in write mode (truncate).
    //       If opening fails, throw std::runtime_error("Cannot save file").
    //       Write all key=value pairs, one per line.
    //       Ensure RAII safety (fstream closes automatically).
}
