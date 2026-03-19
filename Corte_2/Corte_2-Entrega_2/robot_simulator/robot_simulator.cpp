#include "robot_simulator.h"

namespace robot_simulator {

Robot::Robot(Bearing bearing, Position position)
    : bearing_(bearing), position_(position) {}

Bearing Robot::get_bearing() const {
    return bearing_;
}

Position Robot::get_position() const {
    return position_;
}

void Robot::turn_left() {
    switch(bearing_) {
        case Bearing::NORTH: bearing_ = Bearing::WEST; break;
        case Bearing::WEST: bearing_ = Bearing::SOUTH; break;
        case Bearing::SOUTH: bearing_ = Bearing::EAST; break;
        case Bearing::EAST: bearing_ = Bearing::NORTH; break;
    }
}

void Robot::turn_right() {
    switch(bearing_) {
        case Bearing::NORTH: bearing_ = Bearing::EAST; break;
        case Bearing::EAST: bearing_ = Bearing::SOUTH; break;
        case Bearing::SOUTH: bearing_ = Bearing::WEST; break;
        case Bearing::WEST: bearing_ = Bearing::NORTH; break;
    }
}

void Robot::advance() {
    switch(bearing_) {
        case Bearing::NORTH: position_.y++; break;
        case Bearing::SOUTH: position_.y--; break;
        case Bearing::EAST: position_.x++; break;
        case Bearing::WEST: position_.x--; break;
    }
}

void Robot::execute_sequence(const std::string& instructions) {
    for(char c : instructions) {
        if(c == 'L') turn_left();
        else if(c == 'R') turn_right();
        else if(c == 'A') advance();
    }
}

}