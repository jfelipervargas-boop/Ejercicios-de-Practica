#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double P, r, n, t, A;

    cin >> P;

    cin >> r;

    cin >> n;

    cin >> t;

    A = P * pow((1 + r / n), n * t);

    cout << A << endl;

    return 0;
}
