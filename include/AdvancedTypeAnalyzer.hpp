#ifndef ADVANCED_TYPE_ANALYZER_HPP
#define ADVANCED_TYPE_ANALYZER_HPP

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

// ---------- Concepts ----------

// Numeric type
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

// String-like type
template <typename T>
concept StringLike =
    std::is_same_v<std::remove_cv_t<T>, std::string> ||
    std::is_same_v<std::remove_cv_t<T>, const char*>;

// Pointer type
template <typename T>
concept Pointer = std::is_pointer_v<T>;

// Container type (must have value_type and begin()/end())
template <typename T>
concept Container =
requires(T a) {
    typename T::value_type;
    a.begin();
    a.end();
};

// ---------- Analyzer class ----------

class AdvancedTypeAnalyzer {
public:
    template <typename T>
    static void analyze(const T& value);

private:
    // Helper overloads for specific categories
    template <Numeric T>
    static void analyze_impl(const T&);

    template <StringLike T>
    static void analyze_impl(const T&);

    template <Pointer T>
    static void analyze_impl(const T&);

    template <Container T>
    static void analyze_impl(const T&);

    // TODO: unsupported types should cause compile-time error (no fallback)
};

#endif // ADVANCED_TYPE_ANALYZER_HPP
