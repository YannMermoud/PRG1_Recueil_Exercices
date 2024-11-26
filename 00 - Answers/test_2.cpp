#include <iostream>
#include <vector>

class Matrice {
   public:
    std::string label;
    std::vector<std::vector<int>> table;

    // Constructeur
    Matrice(std::string lbl, std::vector<std::vector<int>> tbl)
        : label(std::move(lbl)), table(std::move(tbl)) {}

    // Accès lecture-écriture
    std::vector<int>& operator[](size_t i) { return table[i]; }

    // Accès lecture seule (pour const Matrice)
    const std::vector<int>& operator[](size_t i) const { return table[i]; }

    // Renvoie le nombre de lignes
    size_t size() const { return table.size(); }
};

bool est_un_carre_latin(const Matrice& table) {
    std::vector<int> counter(table.size(), 0);  // Compteur pour les éléments

    for (size_t i = 0; i < table.size(); ++i) {
        if (table.size() != table[i].size()) return false;

        for (size_t j = 0; j < table.size(); ++j) {
            if (size_t(table[j][i]) >= table.size() or
                size_t(table[i][j]) >= table.size())
                return false;
            counter[table[j][i]]++;
            counter[table[i][j]]++;
        }

        for (size_t count : counter) {
            if (count != 2 * (i + 1)) return false;
        }
    }

    return true;
}

int main() {
    Matrice m("m", {
                       {0, 1, 2, 3},
                       {1, 2, 3, 0},
                       {2, 3, 0, 1},
                       {3, 0, 1, 2},
                   });

    std::cout << m.label << " "
              << (est_un_carre_latin(m) ? "est un carre latin"
                                        : "n'est pas un carre latin")
              << std::endl;

    return 0;
}
