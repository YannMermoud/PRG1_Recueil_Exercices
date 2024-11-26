#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

template <typename T>
using Ligne = vector<T>;

template <typename T>
using Matrice = vector<Ligne<T>>;

template <typename T>
ostream& operator<<(ostream& os, Ligne<T> l) {
    os << "[" << ((l.size() != 0) ? ("") : ("]"));
    for (size_t i = 0; i < l.size(); ++i)
        os << l[i] << ((i == l.size() - 1) ? ("]") : (", "));
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, Matrice<T> m) {
    os << "[" << ((m.size() != 0) ? ("") : ("]"));
    for (size_t i(0); i < m.size(); ++i)
        os << setw(2 * (i != 0)) << m[i]
           << ((i == m.size() - 1) ? ("]") : (",\n"));

    return os;
}

int main() {
    Matrice<int> m{};

    cout << m;
}