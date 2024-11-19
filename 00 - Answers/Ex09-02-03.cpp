#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

using vec_i = vector<int>;

string to_string(vec_i vec);

int main() {
    const vector<int> v = {1, 2, 3, 4, 5, 6};
    cout << to_string(v);  // [1, 2, 3, 4, 5, 6];
    return EXIT_SUCCESS;
}

string to_string(vec_i vec) {
    ostringstream os;
    os << "[";
    for (size_t i(0); i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) os << ", ";
    }
    os << "]";
    return os.str();
}