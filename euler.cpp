#include <iostream>
#include <cmath>

using namespace std;


class eulerComplex {
    private:
        unsigned int n;
        void insert(unsigned int n) {
            this -> n = n;
        }
    public:
        eulerComplex(unsigned int n) {
            if (n == 0) {
                cerr<<"nuli tu unda chagewera ragas mawuxeb?";
                exit(1);
            }

            insert(n);
        }

        eulerComplex() {
            exit(1);
        }

        double calculateX(double r,double f) {
            return r * cos(f * M_PI / 180);
        }

        double calculateY(double r, double f) {
            return r * sin(f * M_PI / 180);
        }

        void calculateAvgUsingEulerFormComplexNumber() {
            double x0 = 0;
            double y0 = 0;
            for (int i = 0;i < n;i++) {
                double r;
                double f;
                cout<<"r"<<i + 1<<"=";
                if (!(cin >> r) || r <= 0 || r >= 90) {
                    cerr<<"Invalid input for double r"<<endl;
                    exit(1);
                }

                cout<<"f"<<i + 1<<"=";

                if (!(cin >> f) || f <= 0) {
                    cerr<<"Invalid input for double f"<<endl;
                    exit(1);
                }

                x0 += calculateX(r,f);
                y0 += calculateY(r,f);
            }

                
                x0 /= n;
                y0 /= n;


                convertToEuler(x0,y0);
        }

        void calculateAvgUsingAlgFormComplexNumber() {
            double x0 = 0;
            double y0 = 0;
            for (int i = 0;i < n;i++) {
                double x;
                double y;
                cout<<"x"<<i + 1<<"=";
                if (!(cin >> x)) {
                    cerr<<"Invalid input for double x"<<endl;
                    exit(1);
                }

                cout<<"y"<<i + 1<<"=";

                if (!(cin >> y)) {
                    cerr<<"Invalid input for double y"<<endl;
                    exit(1);
                }

                x0 += x;
                y0 += y;
            }

                x0 /= n;
                y0 /= n;

                convertToEuler(x0,y0);
        }

        void convertToEuler(double x, double y) {
            double r = sqrt(pow(x,2) + pow(y,2));
            double f = atan(y/x);
            cout<<r<<"*"<<exp(1)<<"^"<<f * 180 / M_PI<<"I"<<endl;
        }

        void convertToAlg(double r, double f) {
            cout<<calculateX(r,f)<<"+"<<calculateY(r,f)<<"I";
        }
        
};


int main() {
    eulerComplex euler(3);
    euler.calculateAvgUsingAlgFormComplexNumber();
}