#include <iostream>

using namespace std;

int pow(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    int temp = pow(base * base, exponent / 2);
    if (exponent % 2 == 0) {
        return temp;
    } else {
        return base * temp;
    }
}

int main() {
    int base = 2, exponent = 10;
    int result = pow(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;
    return 0;
}

