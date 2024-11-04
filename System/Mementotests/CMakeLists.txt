cmake_minimum_required(VERSION 3.8)

# Project name
project(MementoTests)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Locate Google Test
find_package(GTest REQUIRED)

# Locate SFML (only include the necessary components)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Include directories
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../)  # Include parent directory if headers are there

# Define the executable and link all required source files
add_executable(MementoTestExe
    MementoTests.cpp
    ../Memento.cpp
    ../Caretaker.cpp
    ../City.cpp
    ../Map.cpp
    ../CityMediator.cpp
    ../DReceiver.cpp
    ../DistributeResources.cpp
    ../TaxPolicy.cpp
    ../Tile.cpp
    ../AnimationHandler.cpp
    ../CDReceiver.cpp 
)

# Link the executable with Google Test, pthread, and SFML libraries
target_link_libraries(MementoTestExe ${GTEST_LIBRARIES} pthread sfml-system sfml-window sfml-graphics)

# Register the test
add_test(NAME MementoTestExe COMMAND MementoTestExe)
