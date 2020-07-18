add_executable(testapp
	"main.cpp"
)

target_include_directories(testapp PUBLIC
	${GMP_INCLUDE_DIR}
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(testapp PUBLIC
	${GMP_LIBRARY}
	gm3p
)