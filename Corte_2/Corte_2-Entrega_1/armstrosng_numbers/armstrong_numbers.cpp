#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {

bool is_armstrong_number(int number) {
    int temp = number;
    int digits = 0;

    while(temp > 0){
        temp /= 10;
        digits++;
    }

    temp = number;
    int sum = 0;

    while(temp > 0){
        int d = temp % 10;
        sum += std::pow(d, digits);
        temp /= 10;
    }

    return sum == number;
}

}
