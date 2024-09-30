#include <iostream>

using namespace std;

void compteur() {
    static int counter(0);
    cout << ++counter << endl;
}

int main() {
    compteur();
    compteur();
    compteur();
    return 0;
}