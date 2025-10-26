#include "TaskScheduler.hpp"
#include <iostream>
#include <stdexcept>

void TaskScheduler::add_task(const std::function<void()>& task)
{
    tasks_.push_back(task);
}

void TaskScheduler::run_all()
{
    errors_.clear();

    for (auto& task : tasks_) {
        try {
            task();  // Execute the current task
        }
        catch (const std::exception& e) {
            errors_.push_back(e.what());  // Store the error message
        }
        catch (...) {
            errors_.push_back("Unknown exception"); // Catch-all safety
        }
    }

    // RAII ensures tasks_ and errors_ clean up automatically when out of scope
}

std::vector<std::string> TaskScheduler::get_errors() const
{
    return errors_;
}
