cmake_minimum_required(VERSION 2.8.2)

project(TEN)
set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

option(USE_MYMATH "Use provided math implementation" ON)


## to check is system supports pow function
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)

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

