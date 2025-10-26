#ifndef TYPE_ANALYZER_HPP
#define TYPE_ANALYZER_HPP

#include <iostream>
#include <string>
#include <type_traits>

// Concept: numeric type (int, float, double, etc.)
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

// Concept: string-like (std::string or const char*)
template <typename T>
concept StringLike =
    std::is_same_v<std::remove_cv_t<T>, std::string> ||
    std::is_same_v<std::remove_cv_t<T>, const char*>;

// Main class
class TypeAnalyzer {
public:
    // Analyze numeric types
    template <Numeric T>
    static void analyze(const T& value);

    // Analyze string-like types
    template <StringLike T>
    static void analyze(const T& value);

    // TODO: no fallback — other types should cause compile-time error
};

#endif // TYPE_ANALYZER_HPP
