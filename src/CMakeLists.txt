set(SOURCES main.cpp main.h)

add_subdirectory(Engine)
add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
		Engine
)

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

configure_file(version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/version.h
)

target_sources(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}/version.h
)
