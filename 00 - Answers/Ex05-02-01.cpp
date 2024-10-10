#include <fstream>
#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    wofstream O_file;
    wifstream I_file;
    string I_path;
    string O_path;

    wcout << L"Entrez le nom du fichier à lire :\n";
    cin >> I_path;

    I_file.open(I_path, ios::in);
    if (!I_file.is_open()) {
        wcerr << L"Erreur : Impossible d'ouvrir le fichier " << L" en lecture."
              << endl;
        return EXIT_FAILURE;
    }
    wcout << L"Entrez le nom du fichier à modifier :\n";
    cin >> O_path;
    O_file.open(O_path, ios::app);
    if (!O_file) {
        wcerr << L"Erreur : Impossible d'ouvrir le fichier " << L" en écriture."
              << endl;
        return EXIT_FAILURE;
    }

    wstring line;
    while (getline(I_file, line)) {
        O_file << line << endl;
    }
    I_file.close();
    O_file.close();

    wcout << L"Le texte a été ajouté avec succès au fichier." << endl;
    return EXIT_SUCCESS;
}
