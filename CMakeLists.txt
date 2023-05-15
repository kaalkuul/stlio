cmake_minimum_required(VERSION 3.20)

project(stlio VERSION 1.0.0 LANGUAGES CXX)

set(stlio_AUTHOR https://github.com/eboutin/)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STLIO_IS_MAIN_PROJECT FALSE)
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(STLIO_IS_MAIN_PROJECT TRUE)
endif()
message(STATUS "stlio is main project: ${STLIO_IS_MAIN_PROJECT}")

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

option(STLIO_BUILD_TESTS "Enable testing for stlio" ${STLIO_IS_MAIN_PROJECT})
option(STLIO_INSTALL "Install stlio files" ${STLIO_IS_MAIN_PROJECT})

if(STLIO_INSTALL)
  include(GNUInstallDirs)
  set(STLIO_INSTALL_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}/stlio")
  set(STLIO_INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/stlio)
endif()

add_subdirectory(src)

if (STLIO_BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()

if(STLIO_INSTALL)
  #Export the targets to a script
  install(EXPORT stlio-targets
    FILE
      stlio-targets.cmake
    NAMESPACE
      stlio::
    DESTINATION
      ${STLIO_INSTALL_CONFIGDIR}
  )

  #Create a ConfigVersion.cmake file
  include(CMakePackageConfigHelpers)

  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/stlio-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
  )

  configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/stlio-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/stlio-config.cmake
    INSTALL_DESTINATION ${STLIO_INSTALL_CONFIGDIR}
  )

  #Install the config, configversion and custom find modules
  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/stlio-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/stlio-config-version.cmake
    DESTINATION ${STLIO_INSTALL_CONFIGDIR}
  )

  ## Exporting from the build tree
  export(EXPORT stlio-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/stlio-targets.cmake
    NAMESPACE stlio::
  )

  #Register package in the User Package Registry
  export(PACKAGE stlio)
endif()
