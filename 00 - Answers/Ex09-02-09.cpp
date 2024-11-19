#include <array>
#include <cstdint>
#include <iostream>
#include <ostream>

using namespace std;

struct Date {
    uint8_t jour;
    uint8_t mois;
    uint16_t annee;
};

struct Personne {
    string prenom;
    string nom;
    Date date;
};
ostream& operator<<(ostream& os, const Date& date);
int main() {
    array carnet{Personne{"Jean"s, "Veuxplus"s, Date{7, 4, 1975}},
                 Personne{"Alain"s, "Verse"s, Date{21, 12, 2018}},
                 Personne{"Justin"s, "Ptipeu"s, Date{1, 8, 2023}},
                 Personne{"Rémi"s, "Fasol"s, Date{17, 5, 1957}}};

    Personne* ptr = &carnet[0];
    Personne& ref = carnet.at(0);
    cout << ref.date << endl;
    cout << ptr->date << endl;
    ref.date.annee = 1976;
    ptr->date.annee = 1976;
    cout << (&ref + 1)->nom[0] << (&ref + 1)->prenom[0] << endl;
    cout << (ptr + 1)->nom[0] << (ptr + 1)->prenom[0] << endl;
    cout << sizeof ptr->nom;
    return EXIT_SUCCESS;
}

ostream& operator<<(ostream& os, const Date& date) {
    return os << static_cast<unsigned int>(date.jour) << " / "
              << static_cast<unsigned int>(date.mois) << " / " << date.annee;
}