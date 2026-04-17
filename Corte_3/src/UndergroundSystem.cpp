#include "UndergroundSystem.h"
#include <unordered_map>
#include <string>
#include <utility>

UndergroundSystem::UndergroundSystem() = default;

void UndergroundSystem::checkIn(int id, std::string stationName, int t) {
    checkIns[id] = {stationName, t};
}

void UndergroundSystem::checkOut(int id, std::string stationName, int t) {
    auto it = checkIns.find(id);
    if (it == checkIns.end()) return;

    auto [startStation, startTime] = it->second;
    std::string key = startStation + "-" + stationName;
    long long travelTime = t - startTime;

    auto& stats = routeStats[key];
    stats.first += travelTime;
    stats.second++;

    checkIns.erase(it);
}

double UndergroundSystem::getAverageTime(std::string startStation, std::string endStation) {
    std::string key = startStation + "-" + endStation;
    auto it = routeStats.find(key);
    if (it == routeStats.end() || it->second.second == 0) return 0.0;
    return static_cast<double>(it->second.first) / it->second.second;
}