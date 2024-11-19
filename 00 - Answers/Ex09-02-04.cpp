#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

void rotate_right(vector<int>& vec);
ostream& operator<<(ostream& os, vector<int> vec);

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << vec << endl;
    rotate_right(vec);
    cout << vec;
    return EXIT_SUCCESS;
}

void rotate_right(vector<int>& vec) {
    int temp = vec[vec.size() - 1];
    for (size_t i(1); i < vec.size(); ++i) {
        vec[i] = vec[i - 1];
    }
    vec[0] = temp;
}
ostream& operator<<(ostream& os, vector<int> vec) {
    os << "[";
    for (size_t i(0); i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) os << ", ";
    }
    return os << "]";
}