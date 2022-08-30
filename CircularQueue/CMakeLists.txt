cmake_minimum_required(VERSION 3.22)
project(TestingCircularQueue)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.c)
add_executable(CircularQueue_run ${SOURCE_FILES})

include_directories(CircularQueue_lib)
add_subdirectory(CircularQueue_lib)

target_link_libraries(CircularQueue_run CircularQueue_lib)

add_subdirectory(Google_tests)
