#include "TaskScheduler.hpp"
#include <iostream>
#include <stdexcept>

void TaskScheduler::add_task(const std::function<void()>& task)
{
    // TODO: Add the task to the vector of tasks_
}

void TaskScheduler::run_all()
{
    // TODO:
    // Iterate through all tasks and execute them.
    // If a task throws an exception, catch it and store the message in errors_.
    // Regardless of exceptions, all tasks must be attempted.
}

std::vector<std::string> TaskScheduler::get_errors() const
{
    // TODO: Return the list of error messages.
    return {};
}
