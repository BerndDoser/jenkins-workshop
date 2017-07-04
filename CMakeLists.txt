cmake_minimum_required(VERSION 3.0)
project(jenkins_workshop VERSION 1.0.0 LANGUAGES CXX)
message("${PROJECT_NAME} version ${PROJECT_VERSION}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic-errors")

find_package (Threads)

add_subdirectory(src)

find_package(GTest)
if(GTEST_FOUND)
  ENABLE_TESTING()
  add_subdirectory(test)
endif()

SET(CPACK_GENERATOR "DEB;ZIP")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Bernd Doser")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include(CPack)
