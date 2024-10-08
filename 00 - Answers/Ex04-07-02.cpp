#include <iostream>

using namespace std;

void compteur() {
    static int counter(0);
    cout << "Appel No : " << ++counter << endl;
}
void compteur(int& counter) { cout << "Appel No : " << ++counter << endl; }

int main() {
    int counter(0);
    compteur();
    compteur();
    compteur();

    compteur(counter);
    compteur(counter);
    compteur(counter);

    return 0;
}