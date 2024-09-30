#include <iostream>

using namespace std;

int main() {
    unsigned long hauteur = 0;

    do {
        cout << "Hauteur du triangle (h > 0) : ";
        // if (cin >> hauteur and hauteur != 0) {
        //  break;
        //}
    } while (true);

    cout << endl;

    for (unsigned long x(0); x < hauteur; ++x) {
        for (unsigned long y(0); y < 2 * hauteur - 1; ++y) {
            if ((y < hauteur - 1 - x) or
                (y > hauteur - 1 + x)) {
                cout << ".";
            } else {
                cout << "*";
            }
        }
        cout << "\n";
    }
}
