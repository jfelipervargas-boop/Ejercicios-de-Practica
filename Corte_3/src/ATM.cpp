#include "ATM.h"
#include <vector>
#include <algorithm>

ATM::ATM() = default;

void ATM::deposit(std::vector<int> banknotesCount) {
    for (int i = 0; i < 5; ++i) {
        count[i] += banknotesCount[i];
    }
}

std::vector<int> ATM::withdraw(int amount) {
    std::vector<int> result(5, 0);
    long long remaining = amount;

    for (int i = 4; i >= 0; --i) {
        if (remaining == 0) break;
        long long canTake = remaining / notes[i];
        long long take = std::min(canTake, count[i]);
        result[i] = static_cast<int>(take);
        remaining -= take * notes[i];
    }

    if (remaining != 0) {
        return {-1};
    }

    for (int i = 0; i < 5; ++i) {
        count[i] -= result[i];
    }
    return result;
}