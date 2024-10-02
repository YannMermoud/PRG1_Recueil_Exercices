#include <iostream>

using namespace std;

void deposit(double& solde, double take_out);

int main() {
    double solde(0);
    deposit(solde, 300);
    deposit(solde, 300);
}

void deposit(double& solde, double take_out) {
    if (solde < take_out) {
        take_out = solde;
        solde = 0;
    } else {
        solde -= take_out;
    }

    cout << "Retrait de : " << take_out << " solde : " << solde << endl;
}
