find_package(SDL2 REQUIRED)

set(SOURCES main.cpp main.h)
add_subdirectory(Game)

add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
	SDL2::SDL2
	SDL2::SDL2main
	Game
)

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	${PROJECT_SOURCE_DIR}/Game
)

configure_file(version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/version.h
)

target_sources(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}/version.h
)
