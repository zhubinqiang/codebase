include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../include
)

aux_source_directory(. DIR_SRCS)

add_executable(cat ${DIR_SRCS})

install(TARGETS cat DESTINATION bin)

