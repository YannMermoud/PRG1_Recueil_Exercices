#include <iostream>

int main() {
    int temp ;
    int* p1_temp;
    const int* p2_temp;
    int const* p3_temp;
    int* const p4_temp = &temp;
    const int* const p5_temps = &temp;
    return EXIT_SUCCESS;
}