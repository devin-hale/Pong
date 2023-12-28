set(RANDOM_SOURCES Random.h)
add_library(Random ${RANDOM_SOURCES})
set_target_properties(Random PROPERTIES LINKER_LANGUAGE CXX)
