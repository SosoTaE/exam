#include <iostream>
#include <cmath>

using namespace std;

class dot {
    private:
        double x;
        double y;
        double r;
    double angleToRad(double angle) {
        return angle * M_PI/180;
    }
    public:
        dot(double x,double y) {
            this -> x = x;
            this -> y = y;
            this -> r = sqrt(pow(x,2) + pow(y,2));
        }


        dot() {
            cerr<<"problema gaq dzma"<<endl;
            exit(1);
        }

        void rotate(double angle) {
            this -> x = r * cos(angleToRad(angle));
            this -> y = r * sin(angleToRad(angle));
        }

        void moveacrossX() {
            this -> y = -y;
        }

        void moveacrossY() {
            this -> x = -x;
        }

        void moveacrossBoth() {
            this -> x = -x;
            this -> y = -y;
        }

        void print() {
            cout<<"{"<<endl;
            cout<<" "<<"x:"<<x<<endl;
            cout<<" "<<"y:"<<y<<endl;
            cout<<"}"<<endl;
        }
};

int main() {
    dot point(5,5);
    point.print();
    point.moveacrossX();
    point.print();
    point.moveacrossY();
    point.print();
    point.moveacrossBoth();
    point.print();
    point.rotate(90);
    point.print();
}