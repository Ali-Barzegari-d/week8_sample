#include "ConfigManager.hpp"
#include <iostream>
#include <cassert>
#include <fstream>

int main() {
    const std::string path = "test_config.txt";

    // Prepare a sample file
    {
        std::ofstream out(path);
        out << "user=guest\n";
        out << "level=1\n";
    }

    try {
        ConfigManager cfg(path);

        // Existing keys
        auto user = cfg.get("user");
        assert(user.has_value());
        assert(user.value() == "guest");

        // Missing key
        auto missing = cfg.get("theme");
        assert(!missing.has_value());

        // Modify and save
        cfg.set("theme", "dark");
        cfg.set("level", "2");
        cfg.save();

        // Reload to verify persistence
        ConfigManager reloaded(path);
        assert(reloaded.get("user").value() == "guest");
        assert(reloaded.get("level").value() == "2");
        assert(reloaded.get("theme").value() == "dark");

        std::cout << "All tests passed ✅\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
