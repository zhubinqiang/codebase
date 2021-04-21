cmake_minimum_required(VERSION 2.8.2)

project(SEVEN)

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

## test
enable_testing()

add_test (test_run ${PROJECT_NAME} 5 2)

add_test (test_usage ${PROJECT_NAME})
set_tests_properties (test_usage
    PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

add_test(test_5_2 ${PROJECT_NAME} 5 2)
set_tests_properties (test_5_2
    PROPERTIES PASS_REGULAR_EXPRESSION "is 25")

add_test (test_10_5 ${PROJECT_NAME} 10 5)
set_tests_properties(test_10_5
    PROPERTIES PASS_REGULAR_EXPRESSION "is 100000")

add_test (test_2_10 ${PROJECT_NAME} 2 10)
set_tests_properties(test_2_10
    PROPERTIES PASS_REGULAR_EXPRESSION "is 1024")

### define a macro to test
macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} ${PROJECT_NAME} ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test(2 3 "is 8")
do_test(2 4 "is 16")
do_test(2 5 "is 32")


