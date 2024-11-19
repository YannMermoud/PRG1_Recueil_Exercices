#include <cstring>
#include <iostream>
#include <span>
#include <unordered_map>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const char* str) {
    return os.write(str, strlen(str));
}

template <typename Range>
ostream& operator<<(ostream& os, const Range& table) {
    for (auto it = begin(table); it != end(table); ++it) {
        os << *it;
        if (next(it) != end(table)) {
            os << ", ";
        }
    }
    return os;
}

unsigned long long fib(unsigned long long n) {
    static unordered_map<unsigned long long, unsigned long long> cache;
    if (n <= 1) return 1;

    // Check if the value is already cached
    if (cache.find(n) != cache.end()) return cache[n];

    // Otherwise, compute it and store in the cache
    cache[n] = fib(n - 1) + fib(n - 2);
    return cache[n];
}

int main() {
    unsigned long long n(0);
    while (true) {
        cout << fib(n++) << endl;
    }

    return EXIT_SUCCESS;
}
