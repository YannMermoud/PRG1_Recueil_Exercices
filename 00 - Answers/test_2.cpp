#include <iostream>
#include <vector>

using Matrice = std::vector<std::vector<int>>;

bool est_un_carre_latin(const Matrice& table) {
    std::vector<int> counter_ligne;
    std::vector<int> counter_colonne;
    for (auto e : table) counter_ligne.push_back(0);
    for (auto e : table) counter_colonne.push_back(0);

    for (size_t i(0); i < table.size(); ++i) {
        if (table.size() != table[i].size()) return false;
        for (size_t j(0); j < table[i].size(); ++j) {
            if (size_t(table[j][i]) >= table.size()) return false;
            counter_colonne[table[j][i]]++;
            counter_ligne[table[i][j]]++;
        }
        for (size_t e : counter_ligne)
            if (e != i + 1) return false;

        for (size_t e : counter_colonne)
            if (e != i + 1) return false;
    }

    return true;
}

int main() {
    Matrice m = {
        {0, 1, 2, 3},
        {1, 2, 3, 0},
        {2, 3, 0, 1},
        {3, 0, 1, 2},
    };
    std::cout << est_un_carre_latin(m);
}