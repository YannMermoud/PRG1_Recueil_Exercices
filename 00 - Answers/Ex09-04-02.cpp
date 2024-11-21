#include <iostream>
#include <ostream>
#include <span>
#include <vector>

using namespace std;

using Matrice = vector<vector<char>>;

ostream& operator<<(ostream& os, const Matrice& m);
Matrice creer();

int main() {
    Matrice m = creer();
    cout << m;
    return EXIT_SUCCESS;
}

ostream& operator<<(ostream& os, const Matrice& m) {
    for (auto e : m) {
        for (auto f : e) os << f;
        os << endl;
    }
    return os;
}
Matrice creer() {
    Matrice m;
    for (int i(0); i < 26; ++i) {
        m.push_back({});
        for (char e = 'a'; e < char('a' + 26 - i); ++e) {
            m[i].push_back(e);
        }
    }
    return m;
}