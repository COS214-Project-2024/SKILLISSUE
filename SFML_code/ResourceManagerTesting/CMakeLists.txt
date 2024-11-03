cmake_minimum_required (VERSION 3.8)

project ("ResourceManager Testing")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Enable testing
enable_testing()

# Locate Google Test
find_package(GTest REQUIRED)

# Include the Google Test headers
include_directories(${GTEST_INCLUDE_DIRS})

# Add your test source file
add_executable(ResourceManagerExe ResourceManagerTestMain.cpp ../ResourceManager.cpp ../Resources.cpp)

# Link the test executable with Google Test and pthread (required by GTest)
target_link_libraries(ResourceManagerExe ${GTEST_LIBRARIES} pthread)

# Add test
add_test(NAME ResourceManagerExe COMMAND ResourceManagerExe)