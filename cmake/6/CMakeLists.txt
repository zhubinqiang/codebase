cmake_minimum_required(VERSION 2.8.2)

project(SIX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

option(USE_MYMATH "Use provided math implementation" ON)

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} mathFunction)
endif(USE_MYMATH)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

## m for libm.so
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS} m)


## install
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
	DESTINATION include)


