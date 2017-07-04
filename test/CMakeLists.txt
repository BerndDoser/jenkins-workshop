include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${GTEST_INCLUDE_DIR}
)

add_executable(
  GalaxyTest
  main.cpp
  Galaxy.cpp
)

target_link_libraries(
  GalaxyTest
  GalaxyLib
  ${GTEST_BOTH_LIBRARIES}
  pthread
)

install(
  TARGETS GalaxyTest
  RUNTIME DESTINATION bin
)

ADD_TEST(
  GalaxyTest
  ${CMAKE_BINARY_DIR}/bin/GalaxyTest
  --gtest_output=xml:${CMAKE_BINARY_DIR}/Testing/GalaxyTest.xml
)
