#include "AdvancedTypeAnalyzer.hpp"
#include <vector>
#include <string>
#include <cassert>
#include <sstream>
#include <iostream>

int main() {
    std::ostringstream buf;
    std::streambuf* oldBuf = std::cout.rdbuf(buf.rdbuf());

    int a = 10;
    double b = 3.14;
    std::string s = "Hello";
    int* p = &a;
    std::vector<int> vi = {1,2,3};
    std::vector<std::string> vs = {"x","y"};

    AdvancedTypeAnalyzer::analyze(a);
    AdvancedTypeAnalyzer::analyze(s);
    AdvancedTypeAnalyzer::analyze(p);
    AdvancedTypeAnalyzer::analyze(vi);
    AdvancedTypeAnalyzer::analyze(vs);

    std::cout.rdbuf(oldBuf);
    std::string output = buf.str();

    assert(output.find("numeric type detected") != std::string::npos);
    assert(output.find("string-like type detected") != std::string::npos);
    assert(output.find("pointer to") != std::string::npos);
    assert(output.find("container of") != std::string::npos);

    std::cout << "All tests passed ✅\n";
    return 0;
}
