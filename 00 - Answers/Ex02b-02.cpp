#include <iostream>
using namespace std;
void permutation(double &x, double &y, double &z) {
    double temp = 0;
    temp = x;
    x = y;
    y = z;
    z = temp;
}
void permutation_without_temp(double &x, double &y, double &z) {
    x = y + x;
    y = x - y;
    x = x - y;

    y = y + z;
    z = y - z;
    y = y - z;
}
int main() {
    double x, y, z;

    cout << "Entrez x, y puis z :";
    cin >> x >> y >> z;

    permutation(x, y, z);

    cout << "\nx = " << x << "\ny = " << y << "\nz = " << z << endl;

    permutation_without_temp(x, y, z);

    cout << "\nx = " << x << "\ny = " << y << "\nz = " << z;
    return 0;
}