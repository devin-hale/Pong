add_subdirectory(Ball)

add_library(PongLib INTERFACE)

target_link_libraries(PongLib INTERFACE
	Ball
)

target_include_directories(Engine INTERFACE 
	${PROJECT_SOURCE_DIR}/Ball
)
