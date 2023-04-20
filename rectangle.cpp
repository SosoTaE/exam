#include <iostream>
#include <cmath>

using namespace std;

class dot {
    private:
        double X;
        double Y;
    public:
        dot(double x,double y) {
            this -> X = x;
            this -> Y = y;
        }

        dot() {

        }

        void setxFromConsole() {
            double x;
            if (!(cin>>x)) {
                cerr<<"invalid input for double x"<<endl;
                exit(1);
            }
            this -> X = x;
        }

        void setyFromConsole() {
            double y;
            if (!(cin>>y)) {
                cerr<<"invalid input for double y"<<endl;
                exit(1);
            }
            this -> Y = y;
        }

        double x() {
            return X;
        }

        double y() {
            return Y;
        }

        double length(dot &a, dot &b) {
            return sqrt(pow(b.X - a.X,2) + pow(b.Y - a.Y,2));
        }
};

class rectangle {
    private:
        double sides[4];
        dot dots[4];
    public:
        rectangle() {
            for (int i = 0;i < 4;i++) {
                dots[i] = dot();
                cout<<"dot["<<i + 1<<"].X=";
                dots[i].setxFromConsole();
                cout<<"dot["<<i + 1<<"].Y=";
                dots[i].setyFromConsole();
            }
        }        


        void calculateSides() {
            for (int i = 1;i < 4;i++) {
                sides[i - 1] = dots[i].length(dots[i - 1],dots[i]);
            }

            sides[3] = dots[0].length(dots[0],dots[3]);
        }


        void printArray() {
            cout<<"[";
            for (int i = 0;i < 3;i++) {
                cout<<sides[i]<<",";   
            }

            cout<<sides[3]<<"]"<<endl;
        }

        double Perimeter() {
            double sum = 0;
            for (int i = 0;i < 4;i++) {
                sum += sides[i];
            }

            return sum;
        }

        double area() {
            double p = Perimeter()/2;
            double m = 1;
            for (int i = 0;i < 4;i++) {
                m *= (p - sides[i]);
            }
            return sqrt(m);
        }
    
};

int main() {
    rectangle a;
    a.calculateSides();
    a.printArray();
    cout<<"Perimeter:"<<a.Perimeter()<<endl;
    cout<<"Area:"<<a.area()<<endl;
}