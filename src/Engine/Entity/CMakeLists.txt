set(ENTITY_SOURCES Entity.cpp Entity.h)

add_library(Entity ${ENTITY_SOURCES})

target_include_directories(Entity PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(Entity PRIVATE SDL2::SDL2 SDL2::SDL2main)
