#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double P, r, n, t, A;

    cout << "P: ";
    cin >> P;

    cout << "r: ";
    cin >> r;

    cout << "n: ";
    cin >> n;

    cout << "t: ";
    cin >> t;

    A = P * pow((1 + r / n), n * t);

    cout << "A: " << A << endl;

    return 0;
}
