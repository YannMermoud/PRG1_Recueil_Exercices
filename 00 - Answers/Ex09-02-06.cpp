#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, vector<int> vec);
void supprimer_valeur(vector<int>& vec, int value);
void supprimer_unique_valeur(vector<int>& vec, int index);

int main() {
    for (vector<int> v : initializer_list<vector<int>>{{},
                                                       {2},
                                                       {1, 2, 2, 2, 3, 1, 2, 4},
                                                       {2, 3, 4, 3, 2, 1},
                                                       {2, 2, 2},
                                                       {5, 4, 3, 2, 1, 2}}) {
        cout << v << " -> ";
        supprimer_valeur(v, 2);
        cout << v << endl;
    }
}

ostream& operator<<(ostream& os, vector<int> vec) {
    os << "[";
    for (size_t i(0); i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) os << ", ";
    }
    return os << "]";
}
void supprimer_valeur(vector<int>& vec, int value) {
    for (size_t i(0); i < vec.size(); ++i) {
        while (vec[i] == value) {
            supprimer_unique_valeur(vec, i);
            if (i >= vec.size()) return;
        }
    }
    return;
}
void supprimer_unique_valeur(vector<int>& vec, int index) {
    for (size_t i(index); i < vec.size() - 1; ++i) {
        vec[i] = vec[i + 1];
    }
    vec.pop_back();
    return;
}