#include "Result.hpp"

// Static factory methods
template <class T, class E>
Result<T, E> Result<T, E>::Ok(const T& value) {
    // TODO: Return a Result holding a success value
    // Hint: Use std::variant to store T
    return Result<T, E>(std::variant<T, E>{});
}

template <class T, class E>
Result<T, E> Result<T, E>::Err(const E& error) {
    // TODO: Return a Result holding an error value
    return Result<T, E>(std::variant<T, E>{});
}

template <class T, class E>
bool Result<T, E>::is_ok() const noexcept {
    // TODO: Return true if data_ holds T, false otherwise
    return false;
}

template <class T, class E>
bool Result<T, E>::is_err() const noexcept {
    // TODO: Return true if data_ holds E
    return false;
}

template <class T, class E>
T Result<T, E>::unwrap() const {
    // TODO:
    // If it holds a T, return it.
    // Otherwise, throw std::runtime_error("Tried to unwrap an error result")
    throw std::runtime_error("not implemented");
}

template <class T, class E>
E Result<T, E>::unwrap_err() const {
    // TODO:
    // If it holds an E, return it.
    // Otherwise, throw std::runtime_error("Tried to unwrap an ok result")
    throw std::runtime_error("not implemented");
}

// Explicit template instantiation (to avoid linker issues for this exercise)
template class Result<int, std::string>;
template class Result<std::string, std::string>;
