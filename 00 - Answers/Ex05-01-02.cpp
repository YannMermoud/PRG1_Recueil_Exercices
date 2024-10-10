#include <fstream>
#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    wofstream O_file;
    wifstream I_file;
    string path;

    wcout << L"Entrez le nom du fichier à lire :\n";
    cin >> path;

    I_file.open(path, ios::in);
    if (!I_file.is_open()) {
        wcerr << L"Erreur : Impossible d'ouvrir le fichier " << L" en lecture."
              << endl;
        return EXIT_FAILURE;
    }

    wcout << L"Contenu actuel du fichier " << endl;
    wstring line;
    while (getline(I_file, line)) {
        wcout << line << endl;
    }
    I_file.close();
    wcout << L"Entrez le texte à ajouter :\n";

    O_file.open(path, ios::app);
    if (!O_file) {
        wcerr << L"Erreur : Impossible d'ouvrir le fichier " << L" en écriture."
              << endl;
        return EXIT_FAILURE;
    }

    wstring buffer = L"";
    while (getline(wcin, buffer)) {
        if (buffer == L"#exit#") break;
        O_file << buffer << endl;
    }
    O_file.close();

    wcout << L"Le texte a été ajouté avec succès au fichier." << endl;
    return EXIT_SUCCESS;
}
