set(RANDOM_SOURCES Random.h)
add_library(Random INTERFACE)
target_sources(Random INTERFACE ${RANDOM_SOURCES})
set_target_properties(Random PROPERTIES LINKER_LANGUAGE CXX)
