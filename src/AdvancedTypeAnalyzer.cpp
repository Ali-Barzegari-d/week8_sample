#include "AdvancedTypeAnalyzer.hpp"

// TODO:
// Implement the main analyze() template:
//   - Print the type category based on which concept matches.
//   - For containers, recursively analyze the contained type (T::value_type).
//   - For pointers, analyze the pointed-to type (using std::remove_pointer_t).
//   - Use if constexpr or concept overload resolution.


// Example logic inside analyze_impl() functions:
//
// analyze_impl(Numeric)   -> "numeric type detected"
// analyze_impl(StringLike) -> "string-like type detected"
// analyze_impl(Pointer)    -> "pointer to [inner type description]"
// analyze_impl(Container)  -> "container of [inner type description]"
//
// Hints:
// - Use std::cout for output.
// - Use recursive call: analyze(inner_value_type{}) for nested templates.
// - Use decltype and std::remove_pointer_t / typename T::value_type as needed.
//
// No fallback: unsupported types should trigger compile-time error.
