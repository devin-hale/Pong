find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_subdirectory(Game)
add_subdirectory(Vec2D)
add_subdirectory(Renderer)
add_subdirectory(Window)
add_subdirectory(Entity)
add_subdirectory(Random)
add_subdirectory(Text)

add_library(Engine INTERFACE)

target_link_libraries(Engine INTERFACE
	SDL2::SDL2
	SDL2::SDL2main
	SDL2_ttf::SDL2_ttf
	Game
	Vec2D
	Renderer
	Window
	Entity
	Random
	Text
)

target_include_directories(Engine INTERFACE 
	${PROJECT_SOURCE_DIR}/Game
	${PROJECT_SOURCE_DIR}/Window
	${PROJECT_SOURCE_DIR}/Renderer
	${PROJECT_SOURCE_DIR}/Vec2D
	${PROJECT_SOURCE_DIR}/Entity
	${PROJECT_SOURCE_DIR}/Random
	${PROJECT_SOURCE_DIR}/Text
	${SDL_INCLUDE_DIR}
	${_sdl2ttf_incdir}
)
