#include "Clock.h"
#include <iomanip>
#include <sstream>

void Clock::normalize() {
    minutes = (minutes % 1440 + 1440) % 1440;
}

Clock::Clock(int hours, int minutes) : minutes(hours * 60 + minutes) {
    normalize();
}

Clock Clock::operator+(int m) const {
    Clock c = *this;
    c.minutes += m;
    c.normalize();
    return c;
}

Clock Clock::operator-(int m) const {
    Clock c = *this;
    c.minutes -= m;
    c.normalize();
    return c;
}

bool Clock::operator==(const Clock& other) const {
    return minutes == other.minutes;
}

std::string Clock::toString() const {
    int h = minutes / 60;
    int m = minutes % 60;
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << h << ":"
        << std::setfill('0') << std::setw(2) << m;
    return oss.str();
}