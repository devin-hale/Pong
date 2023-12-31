set(SOURCES main.cpp main.h)

add_subdirectory(Engine)
add_subdirectory(PongLib)
add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
	Engine
	PongLib
)

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	${PROJECT_SOURCE_DIR}/Engine
	${PROJECT_SOURCE_DIR}/PongLib
)

configure_file(version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/version.h
)
target_sources(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}/version.h
)

