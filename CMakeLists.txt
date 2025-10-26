cmake_minimum_required(VERSION 3.15)
project(csi2372_week6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

# --- Task 1: ConfigManager ---
add_library(ConfigManager src/ConfigManager.cpp)
target_include_directories(ConfigManager PUBLIC include)

add_executable(ConfigManager_tests tests/test_ConfigManager.cpp)
target_link_libraries(ConfigManager_tests PRIVATE ConfigManager)
add_test(NAME ConfigManager_tests COMMAND $<TARGET_FILE:ConfigManager_tests>)

# --- Task 2: Result ---
add_library(Result src/Result.cpp)
target_include_directories(Result PUBLIC include)

add_executable(Result_tests tests/test_Result.cpp)
target_link_libraries(Result_tests PRIVATE Result)
add_test(NAME Result_tests COMMAND $<TARGET_FILE:Result_tests>)

# --- Task 3: ResourceLogger ---
add_library(ResourceLogger src/ResourceLogger.cpp)
target_include_directories(ResourceLogger PUBLIC include)

add_executable(ResourceLogger_tests tests/test_ResourceLogger.cpp)
target_link_libraries(ResourceLogger_tests PRIVATE ResourceLogger)
add_test(NAME ResourceLogger_tests COMMAND $<TARGET_FILE:ResourceLogger_tests>)

# --- Task 4: TaskScheduler ---
add_library(TaskScheduler src/TaskScheduler.cpp)
target_include_directories(TaskScheduler PUBLIC include)

add_executable(TaskScheduler_tests tests/test_TaskScheduler.cpp)
target_link_libraries(TaskScheduler_tests PRIVATE TaskScheduler)
add_test(NAME TaskScheduler_tests COMMAND $<TARGET_FILE:TaskScheduler_tests>)

