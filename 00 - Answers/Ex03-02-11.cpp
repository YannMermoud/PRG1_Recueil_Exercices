#include <cstdint>
#include <iostream>

using namespace std;

constexpr char foreground = '-';
constexpr char background = '+';

int main() {
    uint64_t hauteur = 0;

    do {
        cout << "Hauteur du triangle (h > 0) : ";
        if (cin >> hauteur and hauteur != 0) {
            break;
        }
    } while (true);

    cout << endl;

    for (unsigned long x(0); x < hauteur; ++x) {
        for (unsigned long y(0); y < 2 * hauteur - 1; ++y) {
            if ((y < hauteur - 1 - x) or
                (y > hauteur - 1 + x)) {
                cout << background;
            } else {
                cout << foreground;
            }
        }
        cout << "\n";
    }
}
