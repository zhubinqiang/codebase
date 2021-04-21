cmake_minimum_required(VERSION 2.8.2)

project(THREE)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})


