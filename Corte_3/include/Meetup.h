#ifndef MEETUP_H
#define MEETUP_H

#include <string>

class Meetup {
public:
    int day(int month, int year, const std::string& week, const std::string& weekday);
};

#endif