#ifndef RESULT_HPP
#define RESULT_HPP

#include <variant>
#include <stdexcept>
#include <string>
#include <type_traits>

// Struct tags برای تفکیک T و E حتی وقتی یکسان هستن
struct OkTag {};
struct ErrTag {};

template <class T, class E>
class Result {
public:
    // Factory methods
    static Result<T, E> Ok(const T& value) {
        return Result<T, E>(OkTag{}, value);
    }

    static Result<T, E> Err(const E& error) {
        return Result<T, E>(ErrTag{}, error);
    }

    // State checkers
    bool is_ok() const noexcept {
        return std::holds_alternative<OkWrapper>(data_);
    }

    bool is_err() const noexcept {
        return std::holds_alternative<ErrWrapper>(data_);
    }

    // Accessors
    T unwrap() const {
        if (is_ok()) {
            return std::get<OkWrapper>(data_).value;
        } else {
            throw std::runtime_error("Tried to unwrap an error result");
        }
    }

    E unwrap_err() const {
        if (is_err()) {
            return std::get<ErrWrapper>(data_).value;
        } else {
            throw std::runtime_error("Tried to unwrap an ok result");
        }
    }

private:
    // Wrapper برای تفکیک T و E
    struct OkWrapper { T value; };
    struct ErrWrapper { E value; };

    std::variant<OkWrapper, ErrWrapper> data_;

    // Constructors
    Result(OkTag, const T& value) : data_(OkWrapper{value}) {}
    Result(ErrTag, const E& value) : data_(ErrWrapper{value}) {}
};

#endif // RESULT_HPP
