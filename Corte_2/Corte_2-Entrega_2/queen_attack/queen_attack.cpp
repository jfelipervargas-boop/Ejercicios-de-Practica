#include "queen_attack.h"
#include <stdexcept>
#include <cmath>

namespace queen_attack {

chess_board::chess_board(std::pair<int,int> white, std::pair<int,int> black)
    : white_(white), black_(black) {
    if(white_ == black_) throw std::domain_error("same position");
}

std::pair<int,int> chess_board::white() const {
    return white_;
}

std::pair<int,int> chess_board::black() const {
    return black_;
}

bool chess_board::can_attack() const {
    if(white_.first == black_.first) return true;
    if(white_.second == black_.second) return true;
    if(std::abs(white_.first - black_.first) == std::abs(white_.second - black_.second)) return true;
    return false;
}

}