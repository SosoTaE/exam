#include <iostream>
#include <cmath>

using namespace std;


class rhombus {
    private:
        double side;
        double angle;
        double _angle;
        double d1;
        double d2;
        double height;
        double theta;

        double calculateSide(double angle) {
            return sqrt(pow(side,2) + pow(side,2) - 2 * pow(side,2) * cos(angle * M_PI / 180));
        }

    public:
        rhombus(double side, double angle) {
            if (side == 0 || angle == 0 || angle == 180) {
                exit(1);
            }
            this -> side = side;
            this -> angle = angle;
            this -> _angle = 180 - angle;
            d1 = calculateSide(angle);
            d2 = calculateSide(_angle);
            theta = 180 - angle/2 - _angle/2;
            height = (d1 * d2)/(2 * cos(theta * M_PI / 180));
        }

        double Area() {
            return (d1 * d2) / 2;
        }

        double Perimeter() {yyyyyyyyyyyy
            return 4 * side;
        }

        double getHeight() {
            return height;
        }

        double getD1() {
            return d1;
        }

        double getD2() {
            return d2;
        }

        double getArea() {
            return side * height;
        }

};

int main() {
    rhombus r(5,60);
    cout<<"area:"<<r.Area()<<endl;
    cout<<"area:"<<r.getArea()<<endl;
    cout<<"perimeter:"<<r.Perimeter()<<endl;
    cout<<"height:"<<r.getHeight()<<endl;
    cout<<"diagonal 1:"<<r.getD1()<<endl;
    cout<<"diagonal 2:"<<r.getD2()<<endl;
}