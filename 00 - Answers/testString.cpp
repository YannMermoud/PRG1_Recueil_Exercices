#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "ABC";
    string s2 = "123";
    s1.insert(3, "123", 2);
    cout << "|" << s1 << "|" << endl;
    cout << "|" << s2 << "|" << endl;
    return EXIT_SUCCESS;
}