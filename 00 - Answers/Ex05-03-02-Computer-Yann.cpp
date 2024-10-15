#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

double geomean(double a, double b);
void afficher(string name, int age, double math_result, double PRG_result);

int main() {
    string name;
    int age;
    double math_result;
    double PRG_result;

    cout << "Entrez le nom de l'etudiant : ";
    getline(cin, name);
    cout << endl << "Entrez son age : ";
    cin >> age;
    cout << endl << "Entrez sa note de math : ";
    cin >> math_result;
    cout << endl << "Entrez sa note de PRG : ";
    cin >> PRG_result;

    afficher(name, age, math_result, PRG_result);
    return EXIT_SUCCESS;
}

double geomean(double a, double b) { return (a + b) / 2.0; }

void afficher(string name, int age, double math_result, double PRG_result) {
    int width_col_1 = 18;
    int width_col_2 = 3;
    int width_col_3 = 11;
    int width_col_4 = 14;
    int width_col_5 = 9;
    int width_total =
        width_col_1 + width_col_2 + width_col_3 + width_col_4 + width_col_5;
    cout << left << setw(width_col_1) << "NOM" << right << setw(width_col_2)
         << "AGE" << setw(width_col_3) << "Note Math" << setw(width_col_4)
         << "Note PRG" << setw(width_col_5) << "Admis" << endl;

    cout << right << setw(width_total) << setfill('-') << "" << "\n";

    double moyenne = geomean(math_result, PRG_result);

    cout << setfill(' ') << left << setw(width_col_1) << name << right
         << setw(width_col_2) << age << setw(width_col_3) << math_result
         << setw(width_col_4) << PRG_result << setw(width_col_5)
         << (moyenne > 3.8 ? "Oui" : "Non") << endl;

    cout << right << setw(width_total) << setfill('-') << "" << "\n";
    cout << "Moyenne : " << moyenne << endl;
    cout << "Resultat : " << (moyenne > 3.8 ? "Admis" : "Pas Admis");
}