cmake_minimum_required(VERSION 3.20)

project(stlio)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

option(STLIO_BUILD_TESTING "Enable testing for stlio" ON)

add_subdirectory(src)

if (STLIO_BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
