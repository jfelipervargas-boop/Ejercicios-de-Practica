#ifndef UNDERGROUND_SYSTEM_H
#define UNDERGROUND_SYSTEM_H

#include <string>

class UndergroundSystem {
public:
    UndergroundSystem();
    void checkIn(int id, std::string stationName, int t);
    void checkOut(int id, std::string stationName, int t);
    double getAverageTime(std::string startStation, std::string endStation);

private:
    std::unordered_map<int, std::pair<std::string, int>> checkIns;
    std::unordered_map<std::string, std::pair<long long, int>> routeStats;
};

#endif