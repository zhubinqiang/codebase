cmake_minimum_required(VERSION 2.8.2)

project(Demo)
set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)

## enable gdb to debug
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

## STATUS WARNING FATAL_ERROR
message(STATUS "##### add subdirectory ...")
############################################


add_subdirectory(cat)
add_subdirectory(pwd)
add_subdirectory(pow)
add_subdirectory(multiplication-table)


## generate RPM/DEB
# refer to https://cmake.org/cmake/help/v2.8.10/cpack.html#variable:CPACK_RPM_PACKAGE_LICENSE
set(VERSION "${Demo_VERSION_MAJOR}.${Demo_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_GENERATOR "RPM")
# set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME} )
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "zbq")
set(CPACK_PACKAGE_VENDOR "My Company")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")

# configure_file("${CMAKE_CURRENT_SOURCE_DIR}/my_project.spec.in" "${CMAKE_CURRENT_BINARY_DIR}/my_project.spec" @ONLY IMMEDIATE)
# set(CPACK_RPM_USER_BINARY_SPECFILE "${CMAKE_CURRENT_BINARY_DIR}/my_project.spec")
include(CPack)


