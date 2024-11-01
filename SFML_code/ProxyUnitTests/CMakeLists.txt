cmake_minimum_required (VERSION 3.8)

project ("Proxy Testing")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Enable testing
enable_testing()

# Locate Google Test
find_package(GTest REQUIRED)

# Include the Google Test headers
include_directories(${GTEST_INCLUDE_DIRS})

# Add your test source file
add_executable(proxyExe ProxyTestMain.cpp ../ResourceManager.cpp )

# Link the test executable with Google Test and pthread (required by GTest)
target_link_libraries(proxyExe ${GTEST_LIBRARIES} pthread)

# Add test
add_test(NAME proxyExe COMMAND proxyExe)