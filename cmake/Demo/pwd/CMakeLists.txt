include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/../include
)

aux_source_directory(. DIR_SRCS)

add_executable(pwd ${DIR_SRCS})

install(TARGETS pwd DESTINATION bin)

