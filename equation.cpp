#include <iostream>

using namespace std;

class equation {
    private:
        unsigned int n;
        double* data;

        double D(double a,double b,double c) {
            return b * b - 4 * a * c;
        }

        void setN(unsigned int n) {
            if (n == 0) {
                exit(1);
            }
            this -> n = n;
        }
    public:
        equation(unsigned int n = 0) {
            setN(n);
            data = new double[n];
        }


        unsigned int getN() {
            return n;
        }

        void input() {
            for (int i = 0;i < getN();i++) {
                double a;
                double b;
                double c;
                cout<<"a"<<i + 1<<"="; cin>>a;
                cout<<"b"<<i + 1<<"="; cin>>b;
                cout<<"c"<<i + 1<<"="; cin>>c;
                data[i] = D(a,b,c);
            }
        }


        double maxD() {
            double max = data[0];
            for (int i = 1;i < getN();i++) {
                if (max < data[i]) {
                    max = data[i];
                }
            }

            return max;
        }

        
};

int main() {
    equation r(5);
    r.input();
    return 0;
}