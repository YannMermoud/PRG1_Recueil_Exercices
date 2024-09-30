#include <cstdlib>

#include "Ex06-01_Saisie/Ex06-01_Saisie.hpp"

int main() {
    int i = saisir("votre saisie", 0, 10);
    afficher("votre saisie", i);

    return EXIT_SUCCESS;
}