find_package(SDL2 REQUIRED)
add_subdirectory(Ball)
add_subdirectory(Net)

add_library(PongLib INTERFACE)

target_link_libraries(PongLib INTERFACE
	SDL2::SDL2
	SDL2::SDL2main
	Ball
	Net
)

target_include_directories(PongLib INTERFACE 
	${PROJECT_SOURCE_DIR}/Ball
	${PROJECT_SOURCE_DIR}/Net
	${SDL_INCLUDE_DIR}
)
