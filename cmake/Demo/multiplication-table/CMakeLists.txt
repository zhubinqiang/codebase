PROJECT(multiplication-table)
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../include
)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

