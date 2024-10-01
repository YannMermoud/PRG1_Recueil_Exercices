#include <iostream>

using namespace std;

int fibo(int index);

int main() {
    unsigned int index;
    do {
        cout << "Entrez l'indexe : ";
    } while (!(cin >> index or index != 0));

    cout << "La suite de Fibonnacci jusqu'a l'indexe choisi est :\n";

    for (unsigned int i(1); i <= index; ++i) {
        cout << fibo(i - 1) << " ";
        if (i % 10 == 0) {
            cout << endl;
        }
    }

    return 0;
}

int fibo(int index) {
    if (index == 0 or index == 1) {
        return index;
    }
    return fibo(index - 1) + fibo(index - 2);
}