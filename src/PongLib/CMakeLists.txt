find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_subdirectory(Ball)
add_subdirectory(Net)
add_subdirectory(Paddle)
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

