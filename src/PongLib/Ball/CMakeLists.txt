set(BALL_SOURCES Ball.cpp Ball.h)

add_library(Ball ${BALL_SOURCES})
target_include_directories(Ball PRIVATE ${SDL2_INCLUDE_DIR} ${_sdl2ttf_incdir})
