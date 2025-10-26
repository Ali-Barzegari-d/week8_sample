#include "AdvancedTypeAnalyzer.hpp"
#include <type_traits>

// ------- type_description implementations -------

// Numeric types
template <typename T>
requires Numeric<T>
std::string AdvancedTypeAnalyzer::type_description()
{
    (void)T{}; // no-op: ensure we don't depend on construction
    return std::string("numeric type detected");
}

// String-like types
template <typename T>
requires StringLike<T>
std::string AdvancedTypeAnalyzer::type_description()
{
    return std::string("string-like type detected");
}

// Pointer types: "pointer to <inner description>"
template <typename T>
requires Pointer<T>
std::string AdvancedTypeAnalyzer::type_description()
{
    using Inner = std::remove_pointer_t<std::decay_t<T>>;
    return std::string("pointer to ") + AdvancedTypeAnalyzer::type_description<Inner>();
}

// Container types: "container of <inner description>"
template <typename T>
requires Container<T>
std::string AdvancedTypeAnalyzer::type_description()
{
    using Dec = std::decay_t<T>;
    using Inner = typename Dec::value_type;
    return std::string("container of ") + AdvancedTypeAnalyzer::type_description<Inner>();
}

// ------- analyze (entry point) -------

template <typename T>
void AdvancedTypeAnalyzer::analyze(const T& /*value*/)
{
    using Dec = std::decay_t<T>;
    std::cout << "Analyzing type:\n  → " << AdvancedTypeAnalyzer::type_description<Dec>() << "\n\n";
}

// ------- Explicit instantiations for common types used in tests -------
// This avoids potential linker issues for template functions defined in .cpp

template void AdvancedTypeAnalyzer::analyze<int>(const int&);
template void AdvancedTypeAnalyzer::analyze<double>(const double&);
template void AdvancedTypeAnalyzer::analyze<std::string>(const std::string&);
template void AdvancedTypeAnalyzer::analyze<const char*>(const char*&);
template void AdvancedTypeAnalyzer::analyze<int*>(int*&);
template void AdvancedTypeAnalyzer::analyze<std::vector<int>>(const std::vector<int>&);
template void AdvancedTypeAnalyzer::analyze<std::vector<std::string>>(const std::vector<std::string>&);

// Also instantiate type_description for inner recursion paths we used:
template std::string AdvancedTypeAnalyzer::type_description<int>();
template std::string AdvancedTypeAnalyzer::type_description<double>();
template std::string AdvancedTypeAnalyzer::type_description<std::string>();
template std::string AdvancedTypeAnalyzer::type_description<const char*>();
template std::string AdvancedTypeAnalyzer::type_description<int*>();
template std::string AdvancedTypeAnalyzer::type_description<std::vector<int>>();
template std::string AdvancedTypeAnalyzer::type_description<std::vector<std::string>>();
