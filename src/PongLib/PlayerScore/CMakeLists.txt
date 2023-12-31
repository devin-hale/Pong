set(PLAYERSCORE_SOURCES PlayerScore.cpp PlayerScore.h)

add_library(PlayerScore ${PLAYERSCORE_SOURCES})
target_include_directories(PlayerScore PRIVATE ${SDL2_INCLUDE_DIR} ${_sdl2ttf_incdir})


