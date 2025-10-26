#ifndef ADVANCED_TYPE_ANALYZER_HPP
#define ADVANCED_TYPE_ANALYZER_HPP

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

// ---------- Concepts ----------

// Use decayed types so arrays/refs are handled naturally

template <typename T>
using dec_t = std::remove_cv_t<std::remove_reference_t<T>>;

// Numeric type
template <typename T>
concept Numeric = std::is_arithmetic_v<dec_t<T>>;

// String-like type: std::string or const char* (including string literals)
template <typename T>
concept StringLike =
    std::is_same_v<std::decay_t<T>, std::string> ||
    std::is_same_v<std::decay_t<T>, const char*>;

// Pointer type (after decay)
template <typename T>
concept Pointer = std::is_pointer_v<std::decay_t<T>>;

// Container type: has nested value_type (we detect by presence of value_type)
template <typename T>
concept Container = requires {
    typename std::decay_t<T>::value_type;
};

// ---------- Analyzer class ----------

class AdvancedTypeAnalyzer {
public:
    // Entry point: deduce T from the passed value and print a description.
    template <typename T>
    static void analyze(const T& /*value*/);

private:
    // Produce a textual description for a type T (decayed)
    template <typename T>
    static std::string type_description();

    // No fallback overloads are provided intentionally so unsupported types
    // will cause a compile-time error.
};

#endif // ADVANCED_TYPE_ANALYZER_HPP
