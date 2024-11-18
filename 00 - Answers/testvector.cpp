#include <cstring>
#include <iostream>
#include <span>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const char* str) {
    return os.write(str, strlen(str));
}

template <typename Range>
ostream& operator<<(ostream& os, const Range& table) {
    os << "[";
    for (auto it = begin(table); it != end(table); ++it) {
        os << *it;
        if (next(it) != end(table)) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main() {
    vector v(2, 3.f);

    span<float> v1(v);

    cout << v << endl;
    cout << v1;

    return EXIT_SUCCESS;
}
