cmake_minimum_required(VERSION 3.10)

project(CPP_Design_Exercises)

set(CMAKE_CXX_STANDARD 17)

add_library(robot_simulator
    robot_simulator/robot_simulator.cpp
)

add_library(queen_attack
    queen_attack/queen_attack.cpp
)

add_library(design_twitter
    design_twitter/design_twitter.cpp
)

add_library(design_spreadsheet
    design_spreadsheet/design_spreadsheet.cpp
)