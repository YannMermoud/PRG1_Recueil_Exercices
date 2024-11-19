#include <array>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using Vec3d = array<double, 3>;

string to_string(const Vec3d& vec);
Vec3d produit(Vec3d vec_1, double a);
double produit_scalaire(const Vec3d& vec_1, const Vec3d& vec_2);
Vec3d produit_vectoriel(const Vec3d& vec_1, const Vec3d& vec_2);

int main() {
    Vec3d a{1., 2., 3.};
    Vec3d b{2., 4., 3.};
    cout << "a = " << to_string(a) << endl << "b = " << to_string(b) << endl;

    Vec3d c = produit(a, 2.);
    cout << "c = a*2 = " << to_string(c) << endl;

    cout << "a.b = " << produit_scalaire(a, b)
         << ", a.c = " << produit_scalaire(a, c)
         << ", b.c = " << produit_scalaire(b, c) << endl;

    Vec3d d = produit_vectoriel(a, b);
    cout << "d = a^b = " << to_string(d) << endl;
    cout << "a.d = " << produit_scalaire(a, d)
         << ", b.d = " << produit_scalaire(b, d) << endl;

    Vec3d e = produit_vectoriel(a, a);
    cout << "e = a^a = " << to_string(e) << endl;
}

string to_string(const Vec3d& vec) {
    ostringstream os;
    os << "(";
    for (size_t i(0); i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) os << ",";
    }
    os << ")";
    return os.str();
}

double produit_scalaire(const Vec3d& vec_1, const Vec3d& vec_2) {
    double scal = 0;
    for (size_t i(0); i < vec_1.size(); ++i) {
        scal += vec_1[i] * vec_2[i];
    }
    return scal;
}

Vec3d produit_vectoriel(const Vec3d& vec_1, const Vec3d& vec_2) {
    Vec3d temp;
    temp[0] = vec_1[1] * vec_2[2] - vec_1[2] * vec_2[1];
    temp[1] = vec_1[2] * vec_2[0] - vec_1[0] * vec_2[2];
    temp[2] = vec_1[0] * vec_2[1] - vec_1[1] * vec_2[0];
    return temp;
}

Vec3d produit(Vec3d vec_1, double a) {
    for (size_t i(0); i < vec_1.size(); i++) {
        vec_1[i] *= a;
    }
    return vec_1;
}