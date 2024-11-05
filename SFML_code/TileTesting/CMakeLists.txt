cmake_minimum_required(VERSION 3.14)
project(TaxTesting)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Locate SFML (only include the necessary components)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

enable_testing()

# Add the executable for tests
add_executable(tile_test
  ../Tile.cpp
  ../AnimationHandler.cpp
  ../CityMediator.cpp
  TileTests.cpp      
)

# Link GTest and SFML libraries
target_link_libraries(
  tile_test
  GTest::gtest_main
  pthread
  sfml-system
  sfml-window
  sfml-graphics
)

# Add each test case explicitly
add_test(NAME SatisfactionManagement COMMAND tile_test --gtest_filter=TileTest.SatisfactionManagement)
add_test(NAME ProduceResource COMMAND tile_test --gtest_filter=TileTest.ProduceResource)
add_test(NAME SetMaxResource COMMAND tile_test --gtest_filter=TileTest.SetMaxResource)
add_test(NAME GetCost COMMAND tile_test --gtest_filter=TileTest.GetCost)
add_test(NAME Clone COMMAND tile_test --gtest_filter=TileTest.Clone)
