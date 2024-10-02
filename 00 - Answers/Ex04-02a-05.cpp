#include <iostream>

using namespace std;

bool afficher(char letter_1, char letter_2);

int main() {
    cout << boolalpha
         << afficher('A', 'A') << endl
         << afficher('A', 'C') << endl
         << afficher('B', 'A') << endl
         << afficher('0', '9') << endl
         << afficher(65, 127) << endl;
    return 0;
}

bool afficher(char letter_1, char letter_2) {
    if (letter_2 <= letter_1) {
        return false;
    }

    int nbr_char_to_show = letter_2 - letter_1 + 1;

    for (int i(0); i <= nbr_char_to_show; ++i) {
        cout << letter_1++;
    }
    cout << " ";
    return true;
}