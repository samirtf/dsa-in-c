cmake_minimum_required(VERSION 3.22)
project(TestingRegularQueue)

#set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.c)
add_executable(RegularQueue_run ${SOURCE_FILES})

include_directories(RegularQueue_lib)
add_subdirectory(RegularQueue_lib)

target_link_libraries(RegularQueue_run RegularQueue_lib)

add_subdirectory(Google_tests)