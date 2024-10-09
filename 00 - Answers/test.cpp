#include <iostream>

using namespace std;

int main() {
    int valeur(0);
    int nbErreurs(0);

    cout << "Entrsdfez un entier < 100: ";
    cin >> valeur;

    while (valeur >= 100) {
        nbErreurs++;
        cerr << "Erreur : saisie incorrecte ";
        cin >> valeur;
    }
}