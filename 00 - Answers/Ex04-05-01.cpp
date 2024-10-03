#include <iostream>

using namespace std;

unsigned int factorielle(unsigned int a);

int main() {
    cout << "0! = " << factorielle(0) << endl;
    cout << "1! = " << factorielle(1) << endl;
    cout << "2! = " << factorielle(2) << endl;
    cout << "3! = " << factorielle(3) << endl;
    cout << "4! = " << factorielle(4) << endl;
    cout << "5! = " << factorielle(5) << endl;
    cout << "6! = " << factorielle(6) << endl;
    cout << "7! = " << factorielle(7) << endl;
    cout << "8! = " << factorielle(8) << endl;
    cout << "9! = " << factorielle(9) << endl;
    return 0;
}

unsigned int factorielle(unsigned int a) {
    if (a <= 2) return a;

    return a * factorielle(a - 1);
}