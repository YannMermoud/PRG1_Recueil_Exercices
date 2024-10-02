#include <cstdlib>
#include <iostream>

using namespace std;

double calculate_base(double side);
double calculate_volume(double base_area, double height);

int main() {
    double side(0);
    double height(0);
    do {
        cin >> side;
        cin >> height;
        cout << "la pyramide a un volume de : "
             << calculate_volume(side, height)
             << " cm3\n";

    } while (true);

    return EXIT_SUCCESS;
}

double calculate_base(double side) {
    return side * side;
}
double calculate_volume(double side, double height) {
    double base_area = calculate_base(side);
    return (1. / 3 * base_area * height);
}