#ifndef RESULT_HPP
#define RESULT_HPP

#include <variant>
#include <stdexcept>
#include <string>

template <class T, class E>
class Result {
public:
    static Result<T, E> Ok(const T& value);
    static Result<T, E> Err(const E& error);

    bool is_ok() const noexcept;
    bool is_err() const noexcept;

    T unwrap() const;
    E unwrap_err() const;

private:
    std::variant<T, E> data_;

    explicit Result(const std::variant<T, E>& v) : data_(v) {}
};

#endif // RESULT_HPP
