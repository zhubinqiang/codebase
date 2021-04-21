cmake_minimum_required(VERSION 2.8.2)

project(eleven)
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

include (InstallRequiredSystemLibraries)
## generate tar package
# set (CPACK_RESOURCE_FILE_LICENSE
# 	"${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
# set (CPACK_PACKAGE_VERSION_MAJOR "${Demo_VERSION_MAJOR}")
# set (CPACK_PACKAGE_VERSION_MINOR "${Demo_VERSION_MINOR}")
# include (CPack)


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


