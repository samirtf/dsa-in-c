cmake_minimum_required(VERSION 3.22)
project(TestingSingleLinkedList)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.c)
add_executable(SingleLinkedList_run ${SOURCE_FILES})

include_directories(SingleLinkedList_lib)
add_subdirectory(SingleLinkedList_lib)

target_link_libraries(SingleLinkedList_run SingleLinkedList_lib)

add_subdirectory(Google_tests)
