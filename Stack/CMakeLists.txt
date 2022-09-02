cmake_minimum_required(VERSION 3.22)
project(TestingStack)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.c)
add_executable(Stack_run ${SOURCE_FILES})

include_directories(Stack_lib)
add_subdirectory(Stack_lib)

target_link_libraries(Stack_run Stack_lib)

add_subdirectory(Google_tests)
