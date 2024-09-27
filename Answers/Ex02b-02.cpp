#include <iostream>
using namespace std;
void permutation(double &x, double &y, double &z) {
    double temp = 0;
    temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    double x, y, z;

    cout << "Entrez x, y puis z :";
    cin >> x >> y >> z;

    permutation(x, y, z);

    cout << "\nx = " << x << "\ny = " << y << "\nz = " << z;
    return 0;
}