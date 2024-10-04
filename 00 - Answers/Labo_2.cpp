// ce code a été généré par chatgpt
#include <iostream>
#include <string>

// Fonction qui convertit un nombre entier en texte (unité et dizaine)
std::string convertirNombreEnTexte(int n) {
    std::string result;

    if (n == 0)
        return "zero";
    else if (n == 1)
        result = "un";
    else if (n == 2)
        result = "deux";
    else if (n == 3)
        result = "trois";
    else if (n == 4)
        result = "quatre";
    else if (n == 5)
        result = "cinq";
    else if (n == 6)
        result = "six";
    else if (n == 7)
        result = "sept";
    else if (n == 8)
        result = "huit";
    else if (n == 9)
        result = "neuf";
    else if (n == 10)
        result = "dix";
    else if (n == 11)
        result = "onze";
    else if (n == 12)
        result = "douze";
    else if (n == 13)
        result = "treize";
    else if (n == 14)
        result = "quatorze";
    else if (n == 15)
        result = "quinze";
    else if (n == 16)
        result = "seize";
    else if (n == 17)
        result = "dix-sept";
    else if (n == 18)
        result = "dix-huit";
    else if (n == 19)
        result = "dix-neuf";
    else if (n >= 20) {
        int dizaine = n / 10;
        int unite = n % 10;

        if (dizaine == 2)
            result = "vingt";
        else if (dizaine == 3)
            result = "trente";
        else if (dizaine == 4)
            result = "quarante";
        else if (dizaine == 5)
            result = "cinquante";
        else if (dizaine == 6)
            result = "soixante";
        else if (dizaine == 7)
            result = "septante";
        else if (dizaine == 8)
            result = "huitante";
        else if (dizaine == 9)
            result = "nonante";

        if (unite > 0) {
            if (dizaine == 7 || dizaine == 9) {
                // Gère le cas des dizaines spéciales
                if (unite == 1)
                    result += "-et-" + convertirNombreEnTexte(11);
                else
                    result += "-" + convertirNombreEnTexte(10 + unite);
            } else if (unite == 1)
                result += "-et-un";
            else
                result += "-" + convertirNombreEnTexte(unite);
        }
    }

    return result;
}

// Fonction qui convertit un nombre en texte complet en prenant en compte les
// centaines, milliers, etc.
std::string convertirGrandNombreEnTexte(long long n) {
    std::string result;

    if (n == 0) return "zéro";

    int milliards = n / 1000000000;
    int millions = (n / 1000000) % 1000;
    int milliers = (n / 1000) % 1000;
    int centaines = n % 1000;

    if (milliards > 0) {
        result += convertirGrandNombreEnTexte(milliards) + "-milliard";
        if (milliards > 1) result += "s";
        result += "-";
    }

    if (millions > 0) {
        result += convertirGrandNombreEnTexte(millions) + "-million";
        if (millions > 1) result += "s";
        result += "-";
    }

    if (milliers > 0) {
        if (milliers == 1)
            result += "mille-";
        else
            result += convertirGrandNombreEnTexte(milliers) + "-mille";
    }

    if (centaines > 0) {
        if (centaines >= 100) {
            int centainePartie = centaines / 100;
            if (centainePartie == 1)
                result += "cent";
            else
                result += convertirNombreEnTexte(centainePartie) + "-cent";

            if ((centaines % 100) == 0)
                result += "s";  // Accorder "cent" si exact
            result += "-";
        }
        int reste = centaines % 100;
        if (reste > 0) result += convertirNombreEnTexte(reste);
    }

    return result;
}

// Fonction principale pour convertir le montant
std::string convertirMontantEnTexte(long double montant) {
    long long partieEntiere = static_cast<long long>(montant);
    int centimes = static_cast<int>((montant - partieEntiere) * 100 + 0.5);

    std::string texte = convertirGrandNombreEnTexte(partieEntiere) + " franc";
    if (partieEntiere > 1) texte += "s";

    if (centimes > 0) {
        texte += " et " + convertirGrandNombreEnTexte(centimes) + " centime";
        if (centimes > 1) texte += "s";
    }

    return texte;
}

int main() {
    long double montant;
    std::cout << "Entrez un montant (0 - 999 999 999 999.99) : ";
    std::cin >> montant;
    std::string texte = convertirMontantEnTexte(montant);
    if (montant < 0) {
        texte = "error : montant négatif";
    }
    if (montant > 999999999999.99) {
        texte = "error : montant trop grand";
    }
    std::cout << montant << " -> " << texte << std::endl;

    return 0;
}
