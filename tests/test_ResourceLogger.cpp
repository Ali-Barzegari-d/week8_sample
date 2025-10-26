#include "ResourceLogger.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

int main() {
    const std::string path = "advanced_log.txt";

    try {
        ResourceLogger logger(path);

        logger.write(ResourceLogger::Level::INFO, "System booted");
        logger.write(ResourceLogger::Level::ERROR, "Failed to open config file");
        logger.write(ResourceLogger::Level::WARNING, "Low memory warning");

        // Move test
        ResourceLogger movedLogger = std::move(logger);
        movedLogger.write(ResourceLogger::Level::INFO, "Logger moved successfully");

        // Validate file contents
        std::ifstream in(path);
        assert(in.is_open());

        std::string line;
        int count = 0;
        while (std::getline(in, line)) {
            assert(line.find("[INFO]") != std::string::npos ||
                   line.find("[ERROR]") != std::string::npos ||
                   line.find("[WARNING]") != std::string::npos);
            count++;
        }
        assert(count >= 4);

        std::cout << "All tests passed ✅\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
