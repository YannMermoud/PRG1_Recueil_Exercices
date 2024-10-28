#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
// F = D * (1 + CAGR)^A

// double epsilon = std::numeric_limits<double>::epsilon();
double epsilon = 1e-09;

double calculate_CAGR(double F, double D, double A);
bool areAlmostEqual(double a, double b);

int main() {
    double F, D, A;

    while (1) {
        std::cout << "Entrez F : ";
        std::cin >> F;
        std::cout << "Entrez D : ";
        std::cin >> D;
        std::cout << "Entrez A : ";
        std::cin >> A;
        std::cout << std::setprecision(3) << std::endl
                  << "CAGR = " << calculate_CAGR(F, D, A) * 100 << "%"
                  << std::endl
                  << std::endl;
    }
}

double calculate_CAGR(double F, double D, double A) {
    double higher_bound(10.);
    double lower_bound(0.);
    double CAGR = higher_bound;

    while (true) {
        double gain = D * pow(1 + CAGR, A);
        if (areAlmostEqual(F, gain)) return CAGR;
        if (F > gain) lower_bound = CAGR;
        if (F < gain) higher_bound = CAGR;

        CAGR = (lower_bound + higher_bound) / 2.;
    }
}

bool areAlmostEqual(double a, double b) { return std::fabs(a - b) < epsilon; }
