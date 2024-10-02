#include <iostream>

using namespace std;

bool is_bissextile(int year);

int main() {
    int years[4] = {1900, 2000, 2010, 2020};

    for (int i(0); i < 4; i++) {
        cout << "year : " << years[i] << " was "
             << (is_bissextile(years[i])
                     ? ("bissextile\n")
                     : ("not bissextile\n"));
    };
}

bool is_bissextile(int year) {
    if (year % 4 != 0) {
        return false;
    }
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    return true;
}