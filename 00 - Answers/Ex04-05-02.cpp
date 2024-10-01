#include <iostream>

using namespace std;

int fibo(int index);

int main() {
    unsigned int index;
    do {
        cout << "Entrez l'indexe : ";
    } while (!(cin >> index or index != 0));

    cout << "La suite de Fibonnacci jusqu'a l'indexe choisi est ";

    for (unsigned int i(0); i < index; ++i) {
        cout << fibo(i) << " ";
    }

    return 0;
}

int fibo(int index) {
    if (index == 0 or index == 1) {
        return index;
    }
    return fibo(index - 1) + fibo(index - 2);
}