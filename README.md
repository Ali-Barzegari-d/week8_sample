# CSI2372 — Week 8 Lab Handout

**Topic:** Exception Safety • RAII • Templates • Concepts • File I/O • Resource Management  
**Course:** Advanced Programming Concepts with C++ (Fall 2025, uOttawa)

---

## 1. Overview

In this lab, you will integrate your understanding of C++ exception safety, RAII, templates, and compile-time type analysis.  
You will implement multiple modular components that demonstrate resource management, template-based abstractions, and concept-driven constraints.

The lab consists of five graded tasks:

- **ConfigManager** – file-based configuration management with exception safety.  
- **Result<T, E>** – header-only generic result type; you will implement the methods using TODO hints.  
- **TaskScheduler** – task execution pipeline with exception handling.  
- **Advanced ResourceLogger** – RAII-based logging system with timestamps and move semantics.  
- **AdvancedTypeAnalyzer** – compile-time type classification using C++20 concepts.  

All work is autograded via CI/CTest.  
When the GitHub Actions build is green, you earn full marks.

---

## 2. Learning Objectives

By the end of this lab, you should be able to:

- Apply RAII for safe resource lifetime management.  
- Use C++ templates and concepts to write type-safe generic code.  
- Manage error handling using exceptions, std::optional, and std::variant.  
- Implement strong and basic exception safety guarantees.  
- Detect and classify types at compile time using type traits.  
- Build modular C++ code that passes automated tests.

---

## 3. Task A — ConfigManager

You are given a class **ConfigManager** that loads, edits, and saves key–value pairs from a configuration file.

### Required Behavior
- Constructor receives a file path. If file cannot be opened, throw `std::runtime_error("File not found")`.  
- Store configuration as `std::map<std::string, std::string>`.  
- Implement:
  - `std::optional<std::string> get(const std::string& key) const;`
  - `void set(const std::string& key, const std::string& value);`
  - `void save() const;` – overwrite file contents with current data.  
- Handle malformed or empty lines safely.  
- Guarantee basic exception safety.  
- Manage file resources using RAII (automatic close on scope exit).

### Concepts Covered
Exception safety, RAII, file I/O, std::optional, resource management.

---

## 4. Task B — Result<T, E>

You are given a **header-only template class** `Result<T, E>` similar to Rust’s Result. **No `.cpp` file is used; all implementations must be written in `Result.hpp`.**

### Required Behavior
- Represents either a success (`T`) or an error (`E`).  
- The header file `Result.hpp` contains **TODO comments** explaining what to implement.  
- Implement all methods yourself:
  - `static Result<T, E> Ok(const T& value);` — create a success result.  
  - `static Result<T, E> Err(const E& error);` — create an error result.  
  - `bool is_ok() const noexcept;` — check if the result is success.  
  - `bool is_err() const noexcept;` — check if the result is an error.  
  - `T unwrap() const;` — return success value; throw `std::runtime_error` if this is an error.  
  - `E unwrap_err() const;` — return error value; throw `std::runtime_error` if this is a success.  
- Internally, use `std::variant<T, E>` to store the value.  
- Ensure exception safety when accessing variants.

### Concepts Covered
Class templates, std::variant, error modeling, safe value access, exception propagation.

---

## 5. Task C — TaskScheduler

You are given a class **TaskScheduler** that manages and executes tasks safely.

### Required Behavior
- Hold a collection of `std::function<void()>` tasks.  
- Provide:
  - `void add_task(const std::function<void()>& task);`
  - `void run_all();` — executes each task sequentially.
  - `std::vector<std::string> get_errors() const;` — returns messages of failed tasks.  
- During `run_all()`, if a task throws an exception, catch it, store its message, and continue with remaining tasks.  
- Use RAII and guarantee no resource leaks.

### Concepts Covered
Function objects, task management, exception handling, safe sequential execution.

---

## 6. Task D — Advanced ResourceLogger

You are given a class **ResourceLogger** that logs messages with timestamps and levels.

### Required Behavior
- On construction, open a log file (append mode). If failed, throw `std::runtime_error("Cannot open log file")`.  
- Support log levels via `enum class Level { INFO, WARNING, ERROR };`.  
- Implement:
  - `void write(Level level, const std::string& message);`  
  - Write lines in format `[YYYY-MM-DD HH:MM:SS] [LEVEL] message`.  
- If writing fails, throw `std::runtime_error("Failed to write log")`.  
- Manage file automatically (RAII).  
- Support move semantics; forbid copying.  
- Destructor closes file and never throws.  
- Guarantee basic and strong exception safety where applicable.

### Concepts Covered
RAII, file handling, timestamps (`std::chrono`), move semantics, exception safety guarantees.

---

## 7. Task E — AdvancedTypeAnalyzer

You are given a class **AdvancedTypeAnalyzer** that analyzes types at compile time using C++20 concepts.

### Required Behavior
- Classify types into:
  - numeric types (`int`, `double`, etc.)  
  - string-like types (`std::string`, `const char*`)  
  - pointers (`T*`)  
  - containers (`std::vector<T>`, etc.)  
- Print descriptions such as:
  - `numeric type detected`
  - `pointer to numeric type detected`
  - `container of string-like type detected`
- Support nested containers (e.g., `std::vector<std::vector<int>>`).  
- Unsupported types should cause a compile-time error (no generic fallback).  
- Use recursion and type traits for nested detection.

### Concepts Covered
Concepts, type traits, template recursion, compile-time reasoning, SFINAE and constraint design.

---

## 8. Building and Running

Recommended workflow:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```
CI/CTest runs automatically when you push.
All tests must pass for full credit.

## 9. Grading
100% autograded: your score = proportion of passing tests.

No manual grading.