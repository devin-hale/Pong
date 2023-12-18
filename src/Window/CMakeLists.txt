set(WINDOW_SOURCES Window.cpp Window.h)

add_library(Window ${WINDOW_SOURCES})

target_include_directories(Window PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(Window PRIVATE SDL2::SDL2 SDL2::SDL2main)
