aux_source_directory(. DIR_LIB_SRCS)

## static library
# add_library(mathFunction ${DIR_LIB_SRCS})

## dynamic library
add_library (mathFunction SHARED ${DIR_LIB_SRCS})

## install
install (TARGETS mathFunction DESTINATION lib)
install (FILES mathFunction.h DESTINATION include)

## install directory to dest
# install (DIRECTORY share/man DESTINATION share)


