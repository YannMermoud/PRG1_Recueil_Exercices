#include <iostream>

using namespace std;

int main() {
    unsigned int a, b;

    cout << "Entrez vos entiers positifs : \n";

    while (!(cin >> a));
    while (!(cin >> b));

    unsigned int k = 1;

    while ((a * k) % b != 0) {
        k++;
    }

    cout << "Le PPMC est : " << a * k;
}
