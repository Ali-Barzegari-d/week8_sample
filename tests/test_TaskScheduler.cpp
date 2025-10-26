#include "TaskScheduler.hpp"
#include <iostream>
#include <cassert>

int main() {
    TaskScheduler scheduler;

    int executed = 0;

    scheduler.add_task([&]() { executed++; }); // ok
    scheduler.add_task([&]() { throw std::runtime_error("task failed"); });
    scheduler.add_task([&]() { executed++; }); // ok

    scheduler.run_all();

    // After running, both valid tasks should have executed
    assert(executed == 2);

    // One error should be recorded
    auto errors = scheduler.get_errors();
    assert(errors.size() == 1);
    assert(errors[0] == "task failed");

    std::cout << "All tests passed ✅\n";
    return 0;
}
