set(NET_SOURCES Net.cpp Net.h)

add_library(Net ${NET_SOURCES})
target_include_directories(Net PRIVATE ${SDL2_INCLUDE_DIRS})
