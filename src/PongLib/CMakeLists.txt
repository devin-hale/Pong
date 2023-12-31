find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Now SDL2_TTF_INCLUDE_DIR contains the path to the include directory
message("SDL2_ttf include directory: ${_sdl2ttf_incdir}")
message("SDL2 include directory: ${SDL2_INCLUDE_DIRS}")
add_subdirectory(PlayerScore)

add_library(PongLib INTERFACE)

target_link_libraries(PongLib INTERFACE
	SDL2::SDL2
	SDL2::SDL2main
	SDL2_ttf::SDL2_ttf
	Ball
	Net
	Paddle
	PlayerScore
)

target_include_directories(PongLib INTERFACE 
	${PROJECT_SOURCE_DIR}/Ball
	${PROJECT_SOURCE_DIR}/Net
	${PROJECT_SOURCE_DIR}/Paddle
	${PROJECT_SOURCE_DIR}/PlayerScore
	${SDL2_INCLUDE_DIR}
	${SDL2_ttf_INCLUDE_DIRS}
)

