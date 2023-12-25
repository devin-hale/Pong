set(PADDLE_SOURCES Paddle.cpp Paddle.h)

add_library(Paddle ${PADDLE_SOURCES})
target_include_directories(Paddle PRIVATE ${SDL2_INCLUDE_DIRS})
