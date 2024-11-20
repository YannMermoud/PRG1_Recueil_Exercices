#include <cmath>
#include <iostream>

using namespace std;

double mantisse(double a, int& exposant, int base);

int main() {
    double val;
    int exposant;
    do {
        cout << "Entrez une valeure reelle : ";
        cin.clear();
        fflush(stdin);
    } while (!(cin >> val));
    cout << val << " = " << mantisse(val, exposant, 10) << " * 10^" << exposant
         << endl;
    cout << val << " = " << mantisse(val, exposant, 2) << " * 2^" << exposant;
    return EXIT_SUCCESS;
}

double mantisse(double a, int& exposant, int base) {
    exposant = 0;
    while (abs(a) > base) {
        a = a / base;
        exposant++;
    }
    while (abs(a) < 1) {
        a = a * base;
        exposant--;
    }

    return a;
}