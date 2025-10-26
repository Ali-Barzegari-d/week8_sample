#ifndef RESULT_HPP
#define RESULT_HPP

#include <variant>
#include <stdexcept>
#include <string>

template <class T, class E>
class Result {
public:
    // Construct success value
    static Result<T, E> Ok(const T& value) {
        // TODO: Create a Result holding a success value (store `value` in `data_`)
    }

    // Construct error value
    static Result<T, E> Err(const E& error) {
        // TODO: Create a Result holding an error value (store `error` in `data_`)
    }

    // Check whether the result is success or error
    bool is_ok() const noexcept {
        // TODO: Return true if `data_` currently holds a success value of type T
    }

    bool is_err() const noexcept {
        // TODO: Return true if `data_` currently holds an error value of type E
    }

    // Get success value; throw if this holds an error
    T unwrap() const {
        // TODO: Return the success value; throw std::runtime_error if this is an error
    }

    // Get error value; throw if this holds success
    E unwrap_err() const {
        // TODO: Return the error value; throw std::runtime_error if this is a success
    }

private:
    std::variant<T, E> data_;  // Holds either success or error value

    // Private constructor used by factory functions
    explicit Result(const std::variant<T, E>& v) : data_(v) {
        // TODO: Store the variant in `data_`
    }
};

#endif // RESULT_HPP
