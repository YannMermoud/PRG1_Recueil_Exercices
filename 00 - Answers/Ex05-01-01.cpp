#include <fstream>
#include <iostream>

int main() {
    std::string path_to_file;

    std::cout << "Entrez le nom du fichier à écrire :\n";
    std::getline(std::cin, path_to_file);

    std::ofstream myfile;

    myfile.open(path_to_file, std::ios::app);

    std::string buffer = "";
    std::cout << "entrez le text a enregistrer : \n";
    while (std::getline(std::cin, buffer)) {
        if (buffer == "#exit#") break;
        myfile << buffer << std::endl;
    }
    myfile.close();
    return 0;
}