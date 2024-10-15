#include <iostream>

float Q_rsqrt(float number);

int main() {
    int temp;
    int* p1_temp;
    const int* p2_temp;
    int const* p3_temp;
    int* const p4_temp = &temp;
    const int* const p5_temps = &temp;
    std::cout << Q_rsqrt(4);
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