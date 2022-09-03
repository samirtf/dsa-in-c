project(SingleLinkedList)

set(HEADER_FILES SingleLinkedList.h)
set(SOURCE_FILES SingleLinkedList.c)

add_library(SingleLinkedList_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})