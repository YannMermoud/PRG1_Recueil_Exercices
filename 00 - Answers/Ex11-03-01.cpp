#include <cstdlib>
#include <iostream>
#include <utility>
using namespace std;

class Point {
   private:
    double x, y;

   public:
    Point() {
        x = 0.0;
        y = 0.0;
    };
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    };
    void afficher() { cout << "(" << x << "," << y << ")" << endl; };
    void deplacer(double a, double b) {
        x += a;
        y += b;
    };
    double getX() { return x; };
    double getY() { return y; };
    void setX(double x);
    void setY(double y);
};

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

int main() {
    Point centre;
    centre.afficher();

    Point p(1.2, 2.4);
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}