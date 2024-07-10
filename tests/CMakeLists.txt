cmake_minimum_required(VERSION 3.16)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add test executable
add_executable(unit_tests
  test_main.cpp
  network_tests.cpp
)

# Link test executable against gtest
target_link_libraries(unit_tests
  gtest
  gtest_main
)

# Add dependency on zdoom
add_dependencies(unit_tests zdoom)

# Add tests to be run
add_test(NAME unit_tests COMMAND unit_tests)

# Add network tests script
configure_file(run_network_tests.sh ${CMAKE_CURRENT_BINARY_DIR}/run_network_tests.sh COPYONLY)
