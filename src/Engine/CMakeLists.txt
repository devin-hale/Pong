find_package(SDL2 REQUIRED)

add_subdirectory(Game)
add_subdirectory(Vec2D)
add_subdirectory(Renderer)
add_subdirectory(Window)
add_subdirectory(Entity)
add_subdirectory(Random)

add_library(Engine INTERFACE)

target_link_libraries(Engine INTERFACE
	SDL2::SDL2
	SDL2::SDL2main
	Game
	Vec2D
	Renderer
	Window
	Entity
	Random
)

target_include_directories(Engine INTERFACE 
	${PROJECT_SOURCE_DIR}/Game
	${PROJECT_SOURCE_DIR}/Window
	${PROJECT_SOURCE_DIR}/Renderer
	${PROJECT_SOURCE_DIR}/Vec2D
	${PROJECT_SOURCE_DIR}/Entity
	${PROJECT_SOURCE_DIR}/Random
	${SDL_INCLUDE_DIR}
)
