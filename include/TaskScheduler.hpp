#ifndef TASK_SCHEDULER_HPP
#define TASK_SCHEDULER_HPP

#include <functional>
#include <vector>
#include <string>

class TaskScheduler {
public:
    // Add a new task to the scheduler
    void add_task(const std::function<void()>& task);

    // Execute all tasks in order
    void run_all();

    // Return a vector of error messages (if any)
    std::vector<std::string> get_errors() const;

private:
    std::vector<std::function<void()>> tasks_;
    std::vector<std::string> errors_;
};

#endif // TASK_SCHEDULER_HPP
