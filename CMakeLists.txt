cmake_minimum_required (VERSION 3.8)

project ("gm3p" CXX)

set(GMP_INCLUDE_DIR "" CACHE PATH "Path to the directory containing 'gmp.h'")

if(CMAKE_BUILD_TYPE EQUAL "DEBUG")
	set(GMP_LIBRARY "" CACHE FILEPATH "Path to the gmp library")
else(CMAKE_BUILD_TYPE EQUAL "RELEASE")
	set(GMP_LIBRARY "" CACHE FILEPATH "Path to the gmpDebug library")
endif()

set(ENABLE_TEST_PROJ FALSE CACHE BOOL "Enable the testing project (usually not needed)")

add_library(gm3p STATIC
	"include/gm3p_int.hpp" "src/gm3p_int.cpp"
)

target_include_directories(gm3p PUBLIC
	include
	${GMP_INCLUDE_DIR}
)

target_link_libraries(gm3p PUBLIC
	${GMP_LIBRARY}
)

# Include sub-projects.
if(ENABLE_TEST_PROJ)
	add_subdirectory(testapp)
endif()

install(TARGETS gm3p DESTINATION lib)
install(DIRECTORY include DESTINATION .)