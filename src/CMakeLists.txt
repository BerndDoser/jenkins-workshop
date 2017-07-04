include_directories(
  ${CMAKE_SOURCE_DIR}/include
)

add_library(
  GalaxyLib
  STATIC
  Galaxy.cpp
)
    
install(
  TARGETS GalaxyLib
  ARCHIVE DESTINATION lib
)
