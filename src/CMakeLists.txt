add_library(stlio STATIC
  ../include/stlio.h
  stlio.cpp
)

add_library(stlio::stlio ALIAS stlio)

target_include_directories(stlio
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
  INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/stlio>
)
