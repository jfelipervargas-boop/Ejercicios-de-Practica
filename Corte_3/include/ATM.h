#ifndef ATM_H
#define ATM_H

#include <vector>

class ATM {
public:
    ATM();
    void deposit(std::vector<int> banknotesCount);
    std::vector<int> withdraw(int amount);

private:
    std::vector<long long> notes = {20, 50, 100, 200, 500};
    std::vector<long long> count = {0, 0, 0, 0, 0};
};

#endif