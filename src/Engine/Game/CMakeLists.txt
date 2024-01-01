set(GAME_SOURCES Game.cpp Game.h)

add_library(Game ${GAME_SOURCES})

target_include_directories(Game PRIVATE ${SDL2_INCLUDE_DIRS} ${_sdl2ttf_incdir})

target_link_libraries(Game PRIVATE SDL2::SDL2 SDL2::SDL2main)
