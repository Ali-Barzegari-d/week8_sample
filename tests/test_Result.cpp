#include "Result.hpp"
#include <iostream>
#include <cassert>
#include <string>

int main() {
    // Construct ok and error results
    auto ok = Result<int, std::string>::Ok(42);
    auto err = Result<int, std::string>::Err("Invalid input");

    // Check state
    assert(ok.is_ok());
    assert(!ok.is_err());
    assert(err.is_err());
    assert(!err.is_ok());

    // unwrap
    assert(ok.unwrap() == 42);

    bool threw = false;
    try {
        err.unwrap(); // should throw
    } catch (const std::runtime_error& e) {
        threw = true;
    }
    assert(threw);

    // unwrap_err
    assert(err.unwrap_err() == "Invalid input");

    bool threw2 = false;
    try {
        ok.unwrap_err(); // should throw
    } catch (const std::runtime_error&) {
        threw2 = true;
    }
    assert(threw2);

    std::cout << "All tests passed ✅\n";
    return 0;
}
