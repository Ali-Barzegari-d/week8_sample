#ifndef RESULT_HPP
#define RESULT_HPP

#include <variant>
#include <stdexcept>
#include <string>

template <class T, class E>
class Result {
public:
    // Construct success value
    static Result<T, E> Ok(const T& value);

    // Construct error value
    static Result<T, E> Err(const E& error);

    // Check whether the result is success or error
    bool is_ok() const noexcept;
    bool is_err() const noexcept;

    // Get success value; throw if this holds an error
    T unwrap() const;

    // Get error value; throw if this holds success
    E unwrap_err() const;

private:
    std::variant<T, E> data_;

    // Private constructor used by factory functions
    explicit Result(const std::variant<T, E>& v) : data_(v) {}

    // TODO: You may add helper methods if needed.
};

#endif // RESULT_HPP
