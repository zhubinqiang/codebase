cmake_minimum_required(VERSION 2.8.2)

project(FOUR)

aux_source_directory(. DIR_SRCS)

add_subdirectory(math)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

## link to libmathFunction.so or libmathFunction.a
## library under math/ forder
target_link_libraries(${PROJECT_NAME} mathFunction)


