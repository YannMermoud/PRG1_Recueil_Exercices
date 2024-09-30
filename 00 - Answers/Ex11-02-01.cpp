#include <iostream>

using namespace std;

class Point {
   public:
    double x, y;
    void afficher() {
        cout << "(" << x << "," << y << ")" << endl;
    };
    void deplacer(double a, double b) {
        x += a;
        y += b;
    };
};

int main() {
    Point centre{};
    centre.afficher();

    Point p{1.2, 2.4};
    p.afficher();
    p.deplacer(0.8, 0.6);
    p.afficher();

    p.x = 5.5;
    p.y = 10.3;
    cout << p.x << " -- " << p.y << endl;
}