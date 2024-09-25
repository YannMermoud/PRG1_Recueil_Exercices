#include <iostream>
#include <numbers>
using namespace std;
using namespace numbers;

constexpr double CM3_TO_LITER = 1 / 1000;

int main() {
    double rayon_cylindre_1 = 0;
    double rayon_cylindre_2 = 0;
    double hauteur_cylindre_1 = 0;
    double hauteur_cylindre_2 = 0;
    double hauteur_cone = 0;

    double volume = 0;

    cout << "Entrez le rayon du cylindre 1 [cm]\n";
    cin >> rayon_cylindre_1;
    cout << "Entrez le rayon du cylindre 2 [cm]\n";
    cin >> rayon_cylindre_2;
    cout << "Entrez la hauteur du cylindre 1 [cm]\n";
    cin >> hauteur_cylindre_1;
    cout << "Entrez la hauteur du cylindre 2 [cm]\n";
    cin >> hauteur_cylindre_2;
    cout << "Entrez la hauteur du cone [cm]\n";
    cin >> hauteur_cone;

    volume = pi * rayon_cylindre_1 * rayon_cylindre_1 * hauteur_cylindre_1 + pi * rayon_cylindre_2 * rayon_cylindre_2 * hauteur_cylindre_2 + hauteur_cone * pi / 3 * (rayon_cylindre_1 * rayon_cylindre_1 + rayon_cylindre_2 * rayon_cylindre_2 + rayon_cylindre_1 * rayon_cylindre_2);

    string plural(volume < 2) ? ('\n') : ('s\n');
    cout << "la contenance de la bouteille est de "
         << volume * CM3_TO_LITER
         << " litre"
         << plural;

    return 0;
}