find_package(Catch2 3 QUIET)

if (NOT Catch2_FOUND)
	message("Catch2 not found. Using FetchContent to make Catch2 available locally.")
	
	Include(FetchContent)

	FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG        v3.2.1 # or a later release
	)

	FetchContent_MakeAvailable(Catch2)
endif()

add_executable(stlio_tests
	src/utils.h src/utils.cpp
	src/asserts.h src/asserts.cpp
	src/geometry.h src/geometry.cpp
	src/StlInMock.h
	src/StlOutMock.h
	src/main.cpp
	src/test_ReadStl.cpp
	src/test_WriteStl.cpp
)

set(TEST_DATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)

target_compile_definitions(stlio_tests
	PRIVATE
	TEST_DATA_DIR=R"\(${TEST_DATA_DIR}\)"
	CATCH_CONFIG_FAST_COMPILE DO_NOT_USE_WMAIN)

target_link_libraries(stlio_tests Catch2::Catch2 stlio)

set_property(TARGET stlio_tests PROPERTY FOLDER "Tests")

enable_testing()

add_test(stlio_tests stlio_tests ${CATCH_EXTRA_ARGS})
