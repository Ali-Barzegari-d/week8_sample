#include "TypeAnalyzer.hpp"
#include <iostream>
#include <sstream>
#include <cassert>

int main() {
    std::ostringstream buffer;
    std::streambuf* oldBuf = std::cout.rdbuf(buffer.rdbuf());

    // Valid tests
    TypeAnalyzer::analyze(42);
    TypeAnalyzer::analyze(3.14);
    TypeAnalyzer::analyze(std::string("Hello"));
    TypeAnalyzer::analyze("World");

    std::cout.rdbuf(oldBuf);
    std::string output = buffer.str();

    // Must contain both messages
    assert(output.find("numeric type detected") != std::string::npos);
    assert(output.find("string-like type detected") != std::string::npos);

    // Uncommenting below should cause compilation error:
    // struct Foo {};
    // Foo f;
    // TypeAnalyzer::analyze(f); // ❌ should not compile

    std::cout << "All tests passed ✅\n";
    return 0;
}
