project(CircularQueue)

set(HEADER_FILES CircularQueue.h)
set(SOURCE_FILES CircularQueue.c)

add_library(CircularQueue_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})