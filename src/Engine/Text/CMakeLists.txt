set(TEXT_SOURCES Text.cpp Text.h)

add_library(Text ${TEXT_SOURCES})

target_include_directories(Text PRIVATE ${SDL2_INCLUDE_DIRS} ${_sdl2ttf_incdir})
