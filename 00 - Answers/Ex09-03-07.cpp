#include <algorithm>  // for std::copy
#include <array>
#include <iostream>
#include <iterator>  // for std::ostream_iterator
#include <ostream>
#include <span>
#include <vector>

using namespace std;
ostream& operator<<(ostream& os, const span<const int>& vec);
bool recherche(const span<const int>& vec, int value);

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

std::ostream& operator<<(std::ostream& os, const std::span<const int>& vec) {
    os << "[";
    if (!vec.empty()) {
        // Use ostream_iterator to handle formatting
        std::copy(vec.begin(), vec.end() - 1,
                  std::ostream_iterator<int>(os, ", "));
        os << vec.back();  // Print the last element without a trailing comma
    }
    return os << "]";
}

bool recherche(const span<const int>& vec, int value) {
    size_t middle = (vec.size()) / 2;
    if (vec.empty()) return false;
    if (vec[middle] == value) return true;

    return (vec[middle] < value) ? (recherche(vec.subspan(middle + 1), value))
                                 : (recherche(vec.first(middle), value));
}