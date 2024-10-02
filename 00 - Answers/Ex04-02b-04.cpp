#include <iostream>

using namespace std;

bool operation(double a, char op, double b, double& result);

int main() {
    double a, b, result;

    cout << "Entrez 2 nombres >= 0 : ";
    cin >> a >> b;
    cout << boolalpha
         << operation(a, '+', b, result) << ": "
         << "a + b = " << result << endl
         << operation(a, '-', b, result) << ": "
         << "a - b = " << result << endl
         << operation(a, '*', b, result) << ": "
         << "a * b = " << result << endl
         << operation(a, '/', b, result) << ": "
         << "a / b = " << result << endl;
    return 0;
}

bool operation(double a, char op, double b, double& result) {
    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            return false;
    }
    return true;
}