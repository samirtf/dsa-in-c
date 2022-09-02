project(Stack)

set(HEADER_FILES Stack.h)
set(SOURCE_FILES Stack.c)

add_library(Stack_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})