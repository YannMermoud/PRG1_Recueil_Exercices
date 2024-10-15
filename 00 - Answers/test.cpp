#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

float Q_rsqrt(float number);

using int8 = int8_t;

class unl_int {
   private:
   public:
    std::vector<int> array;
    unl_int(auto arg);
    ~unl_int();
};

unl_int::unl_int(auto arg) {
    for (size_t i = 1; i < sizeof(arg) / sizeof(int); i++) {
        array.push_back((arg / (i * sizeof(int))) % sizeof(int));
    }
}

unl_int::~unl_int() { }

std::ostream& operator<<(std::ostream& os, const unl_int& val) {
    for (size_t i = 0; i < sizeof(unl_int) / sizeof(int); ++i) {
        os << std::to_string(val.array[(sizeof(unl_int) / sizeof(int)) - i]);
    }
    return os;
}

int main() {
    unl_int test(3);
    std::cout << test;
    return EXIT_SUCCESS;
}

float Q_rsqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y;             // evil floating point bit level hacking
    i = 0x5f3759df - (i >> 1);  // what the fuck?
    y = *(float*)&i;
    y = y * (threehalfs - (x2 * y * y));  // 1st iteration
    y = y * (threehalfs - (x2 * y * y));  // 2nd iteration, this can
    // be removed

    return y;
}