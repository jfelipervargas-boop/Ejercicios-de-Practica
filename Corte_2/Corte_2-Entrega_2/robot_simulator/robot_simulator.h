#pragma once
#include <string>

namespace robot_simulator {

enum class Bearing { NORTH, EAST, SOUTH, WEST };

struct Position {
    int x;
    int y;
};

class Robot {
public:
    Robot(Bearing bearing = Bearing::NORTH, Position position = {0,0});

    Bearing get_bearing() const;
    Position get_position() const;

    void turn_left();
    void turn_right();
    void advance();
    void execute_sequence(const std::string& instructions);

private:
    Bearing bearing_;
    Position position_;
};

}