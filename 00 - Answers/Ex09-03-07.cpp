#include <array>
#include <iostream>
#include <ostream>
#include <span>
#include <vector>

using namespace std;
ostream& operator<<(ostream& os, span<const int> vec);
bool recherche(span<const int> vec, int value);

int main() {
    for (vector<int> const& v : {vector<int>{1, 2, 3, 5, 7, 11, 13, 17},
                                 {1, 3, 5, 7, 9, 11, 13, 15, 17},
                                 {2, 4, 6, 8, 10, 12, 14, 16, 18},
                                 {5, 10, 15, 20},
                                 {11},
                                 {1},
                                 {}}) {
        for (int e : {3, 11, 15}) {
            cout << v << (recherche(v, e) ? " contient " : " ne contient pas ")
                 << e << endl;
        }
    }
}

ostream& operator<<(ostream& os, span<const int> vec) {
    os << "[";
    for (size_t i(0); i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) os << ", ";
    }
    return os << "]";
}

bool recherche(span<const int> vec, int value) {
    size_t middle = (vec.size()) / 2;
    if (vec.empty()) return false;
    if (vec[middle] == value) return true;

    return (vec[middle] < value) ? (recherche(vec.subspan(middle + 1), value))
                                 : (recherche(vec.subspan(0, middle), value));
}