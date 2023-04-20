#include <iostream>

using namespace std;


class centerofGravity {
    private:
        unsigned int n;
        double x0 = 0;
        double y0 = 0;
        double z0 = 0;
        double m0 = 0;
    public:
        centerofGravity(unsigned int n) {
            if (n == 0) {
                cerr<<"shen problema gaq dzma";
                exit(1);
            }
            this -> n = n;
        }

        centerofGravity() {
            cerr<<"shen problema gaq dzma";
            exit(1);
        }
        
        void calculate() {
            for (int i = 0;i < n;i++) {
                double x; 
                double y;
                double z;
                double m;
                cout<<"x"<<i + 1<<"="; 
                if (!(cin >> x)) { // Check if input is valid
                    cerr<<"Invalid input for x"<<i + 1<<endl;
                    exit(1);
                }
                cout<<"y"<<i + 1<<"="; 
                if (!(cin >> y)) { // Check if input is valid
                    cerr<<"Invalid input for y"<<i + 1<<endl;
                    exit(1);
                }
                cout<<"z"<<i + 1<<"="; 
                if (!(cin >> z)) { // Check if input is valid
                    cerr<<"Invalid input for z"<<i + 1<<endl;
                    exit(1);
                }
                cout<<"m"<<i + 1<<"="; 
                if (!(cin >> m) || m <= 0) { // Check if input is valid and positive
                    cerr<<"Invalid input for m"<<i + 1<<endl;
                    exit(1);
                }
                x0 += x * m;
                y0 += y * m;
                z0 += z * m;
                m0 += m;
            }

            x0 /= m0;
            y0 /= m0;
            z0 /= m0;

            cout<<"result:";
            cout<<"x0="<<x0<<endl;
            cout<<"       "<<"y0="<<y0<<endl;
            cout<<"       "<<"z0="<<z0<<endl;
            cout<<"       "<<"m0="<<m0<<endl;
        }
};

int main() {
    centerofGravity c(2);
    c.calculate();
}