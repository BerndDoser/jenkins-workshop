cmake_minimum_required(VERSION 3.0)
project(jenkins-workshop VERSION 1.0.0 LANGUAGES CXX)
message("${PROJECT_NAME} version ${PROJECT_VERSION}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic-errors")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(src)

find_package(GTest)
if(GTEST_FOUND)
  enable_testing()
  add_subdirectory(test)
endif()

find_package(Doxygen)
if(DOXYGEN_FOUND)
  set(doxyfile_in ${PROJECT_SOURCE_DIR}/doxygen/Doxyfile)
  set(doxyfile ${PROJECT_BINARY_DIR}/doxygen/Doxyfile)
  configure_file(${doxyfile_in} ${doxyfile} @ONLY)
  add_custom_target(doc
    COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/doxygen
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
  )
  install(DIRECTORY ${PROJECT_BINARY_DIR}/doxygen/html DESTINATION share/doc)
endif()

set(CPACK_GENERATOR "DEB;ZIP")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Bernd Doser")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include(CPack)
