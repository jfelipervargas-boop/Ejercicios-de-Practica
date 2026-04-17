#ifndef CLOCK_H
#define CLOCK_H

#include <string>

class Clock {
private:
    int minutes;
    void normalize();

public:
    Clock(int hours, int minutes = 0);
    Clock operator+(int m) const;
    Clock operator-(int m) const;
    bool operator==(const Clock& other) const;
    std::string toString() const;
};

#endif