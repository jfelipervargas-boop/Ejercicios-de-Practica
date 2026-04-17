#include "Meetup.h"
#include <string>
#include <vector>
#include <ctime>

int Meetup::day(int month, int year, const std::string& week, const std::string& weekday) {
    std::tm time_in = {};
    time_in.tm_year = year - 1900;
    time_in.tm_mon = month - 1;
    time_in.tm_mday = 1;
    std::mktime(&time_in);

    int targetWday = 0;
    std::vector<std::string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < 7; ++i) {
        if (days[i] == weekday) {
            targetWday = i;
            break;
        }
    }

    if (week == "teenth") {
        for (int d = 13; d <= 19; ++d) {
            std::tm t = time_in;
            t.tm_mday = d;
            std::mktime(&t);
            if (t.tm_wday == targetWday) return d;
        }
    }

    int occurrence = 0;
    if (week == "first") occurrence = 1;
    else if (week == "second") occurrence = 2;
    else if (week == "third") occurrence = 3;
    else if (week == "fourth") occurrence = 4;
    else if (week == "last") occurrence = -1;

    int count = 0;
    int lastDay = 0;
    for (int d = 1; d <= 31; ++d) {
        std::tm t = time_in;
        t.tm_mday = d;
        if (std::mktime(&t) == -1) break;
        if (t.tm_mon != month - 1) break;

        if (t.tm_wday == targetWday) {
            count++;
            lastDay = d;
            if (occurrence > 0 && count == occurrence) return d;
        }
    }
    if (occurrence == -1) return lastDay;
    return 0; // fallback
}