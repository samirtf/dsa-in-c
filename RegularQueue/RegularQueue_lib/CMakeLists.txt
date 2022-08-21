project(RegularQueue)

set(HEADER_FILES RegularQueue.h)
set(SOURCE_FILES RegularQueue.c)

add_library(RegularQueue_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})