#include "Result.hpp"

// Template definitions
template <class T, class E>
Result<T, E> Result<T, E>::Ok(const T& value) {
    return Result<T, E>(std::variant<T, E>(value));
}

template <class T, class E>
Result<T, E> Result<T, E>::Err(const E& error) {
    return Result<T, E>(std::variant<T, E>(error));
}

template <class T, class E>
bool Result<T, E>::is_ok() const noexcept {
    return std::holds_alternative<T>(data_);
}

template <class T, class E>
bool Result<T, E>::is_err() const noexcept {
    return std::holds_alternative<E>(data_);
}

template <class T, class E>
T Result<T, E>::unwrap() const {
    if (std::holds_alternative<T>(data_))
        return std::get<T>(data_);
    throw std::runtime_error("Tried to unwrap an error result");
}

template <class T, class E>
E Result<T, E>::unwrap_err() const {
    if (std::holds_alternative<E>(data_))
        return std::get<E>(data_);
    throw std::runtime_error("Tried to unwrap an ok result");
}

// Explicit template instantiations
template class Result<int, std::string>;
template class Result<std::string, std::string>;
