set(RENDERER_SOURCES Renderer.cpp Renderer.h)

add_library(Renderer ${RENDERER_SOURCES})

target_include_directories(Renderer PRIVATE ${SDL_INCLUDE_DIRS})

target_link_libraries(Renderer PRIVATE SDL2::SDL2 SDL2::SDL2main)
