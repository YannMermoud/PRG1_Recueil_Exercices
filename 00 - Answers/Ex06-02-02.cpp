#include <cmath>
#include <iomanip>
#include <iostream>
#include <locale>

class custom_numpunct : public std::numpunct<char> {
   protected:
    virtual char do_thousands_sep() const override {
        return '\'';  // Single quote as thousands separator
    }

    virtual std::string do_grouping() const override {
        return "\3";  // Groups of 3 digits
    }
};

int main() {
    int b = 0;
    while (true) {
        if ((pow(2, b) + 1) != int(float(pow(2, b) + 1))) {
            std::cout.imbue(
                std::locale(std::cout.getloc(), new custom_numpunct));
            std::cout << std::fixed << std::setprecision(0) << pow(2, b) + 1;
            break;
        }
        b++;
    }
    return EXIT_SUCCESS;
}