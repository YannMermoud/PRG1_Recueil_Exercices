#include <cstdlib>
#include <iostream>
#include <numbers>

using namespace std;
using namespace numbers;

constexpr double CM3_TO_LITER = 1000;

int main() {
    double rayon_cylindre_1 = 0;
    double rayon_cylindre_2 = 0;
    double hauteur_cylindre_1 = 0;
    double hauteur_cylindre_2 = 0;
    double hauteur_cone = 0;

    double volume = 0;

    cout << "Entrez le rayon du cylindre 1 [cm]\n";
    while (!(cin >> rayon_cylindre_1));
    cout << "Entrez le rayon du cylindre 2 [cm]\n";
    while (!(cin >> rayon_cylindre_2));
    cout << "Entrez la hauteur du cylindre 1 [cm]\n";
    while (!(cin >> hauteur_cylindre_1));
    cout << "Entrez la hauteur du cylindre 2 [cm]\n";
    while (!(cin >> hauteur_cylindre_2));
    cout << "Entrez la hauteur du cone [cm]\n";
    while (!(cin >> hauteur_cone));

    volume = pi * rayon_cylindre_1 * rayon_cylindre_1 * hauteur_cylindre_1 +
             pi * rayon_cylindre_2 * rayon_cylindre_2 * hauteur_cylindre_2 +
             hauteur_cone * pi / 3 *
                 (rayon_cylindre_1 * rayon_cylindre_1 +
                  rayon_cylindre_2 * rayon_cylindre_2 +
                  rayon_cylindre_1 * rayon_cylindre_2);

    cout << "la contenance de la bouteille est de "
         << volume / CM3_TO_LITER
         << " litre"
         << (volume < 2 ? ("") : ("s"))
         << ".";

    return EXIT_SUCCESS;
}