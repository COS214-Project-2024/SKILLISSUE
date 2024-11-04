cmake_minimum_required (VERSION 3.8)

project ("Mediator Testing")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Locate SFML package
find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

# Enable testing
enable_testing()

# Locate Google Test
find_package(GTest REQUIRED)

# Include the Google Test headers
include_directories(${GTEST_INCLUDE_DIRS})

# Add your test source file
add_executable(MediatorExe 
                            MediatorTestMain.cpp 
                            ../Tile.cpp ../City.cpp 
                            ../CityMediator.cpp 
                            ../AnimationHandler.cpp 
                            ../DistributePopulation.cpp
                            ../SatisfactionCalculator.cpp
                            ../SCReceiver.cpp
                            ../CreateAndDistributeGoods.cpp
                            ../CDReceiver.cpp
                            ../Map.cpp
                            ../LowTax.cpp
                            ../Memento.cpp
                            ../DReceiver.cpp
                            ../TaxPolicy.cpp
                            )

# Link the test executable with Google Test and pthread (required by GTest)
target_link_libraries(MediatorExe ${GTEST_LIBRARIES} pthread)


# Add test
add_test(NAME MediatorExe COMMAND MediatorExe)


# Include SFML headers
include_directories(${SFML_INCLUDE_DIRS})

# Link SFML libraries
target_link_libraries(MediatorExe ${SFML_LIBRARIES})

# Explicitly link each SFML library
target_link_libraries(MediatorExe
    sfml-system
    sfml-window
    sfml-graphics
)