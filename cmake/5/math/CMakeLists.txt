aux_source_directory(. DIR_LIB_SRCS)

## static library
# add_library(mathFunction ${DIR_LIB_SRCS})

## dynamic library
add_library (mathFunction SHARED ${DIR_LIB_SRCS})


