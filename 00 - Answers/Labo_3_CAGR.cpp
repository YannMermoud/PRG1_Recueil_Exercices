#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
// F = D * (1 + CAGR)^A

// double epsilon = std::numeric_limits<double>::epsilon();
static constexpr double precision = 5.;

double calculate_CAGR(double F, double D, double A);
bool areAlmostEqual(double a, double b, double ulp);

int main() {
    double F, D, A;

    while (1) {
        std::cout << "Entrez F : ";
        std::cin >> F;
        std::cout << "Entrez D : ";
        std::cin >> D;
        std::cout << "Entrez A : ";
        std::cin >> A;
        std::cout << std::fixed << std::setprecision(3) << std::endl
                  << "CAGR = " << calculate_CAGR(F, D, A) * 100 << "%"
                  << std::endl
                  << std::endl;
    }

    return EXIT_SUCCESS;
}

double calculate_CAGR(double F, double D, double A) {
    double higher_bound = F;
    double lower_bound = 0.;
    double CAGR = higher_bound;

    while (true) {
        double gain = D * pow(1 + CAGR, A);
        if (areAlmostEqual(F, gain, precision)) return CAGR;
        if (F > gain) lower_bound = CAGR;
        if (F < gain) higher_bound = CAGR;
        CAGR = (lower_bound + higher_bound) / 2.;
    }
}

bool areAlmostEqual(double a, double b, double ulp) {
    return std::fabs(a - b) <= (std::numeric_limits<double>::epsilon() *
                                std::fabs(a + b) * ulp) or
           std::fabs(a - b) < std::numeric_limits<double>::min();
}
