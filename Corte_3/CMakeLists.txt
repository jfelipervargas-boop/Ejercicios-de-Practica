cmake_minimum_required(VERSION 3.14)
project(DesignProblems LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(DesignLib
    src/UndergroundSystem.cpp
    src/ATM.cpp
    src/AuctionSystem.cpp
    src/Meetup.cpp
    src/Clock.cpp
)

add_executable(test_design src/main_test.cpp)  # crea main_test.cpp si quieres pruebas
target_link_libraries(test_design PRIVATE DesignLib)