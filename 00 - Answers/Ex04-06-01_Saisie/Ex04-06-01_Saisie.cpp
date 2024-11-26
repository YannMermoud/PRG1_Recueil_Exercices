#include "Ex04-06-01_Saisie.hpp"



int saisir(const std::string& msg, int min, int max) {
    int saisie;
    do {
        std::cout << msg << " [" << min << ".." << max << "] : ";
        std::cin >> saisie;
    } while (saisie < min or saisie > max);
    return saisie;
}

void afficher(const std::string& msg, int valeur) {
    std::cout << msg << " : " << valeur;
}