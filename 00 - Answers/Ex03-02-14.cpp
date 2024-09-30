#include <iostream>

using namespace std;

int main() {
    int n(10);
    int depart(0);

    for (int i = depart; i < n; ++i) {
        cout << i << " ";
    }
    int i(depart);

    cout << endl;

    while (i < n) {
        cout << i++ << " ";
    }
    i = depart;

    cout << endl;

    if (i < n) {
        do {
            cout << i++ << " ";
        } while (i < n);
    }
}