#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private:
        double x, y;
    public:
    double xVal, yVal;  
        Point (){
            x = 0;
            y = 0;
        }

        Point (double xVal, double yVal){
            x = xVal;
            y = yVal;
        }
        
        void dist2orig()
        {
            cout << sqrt (pow(x, 2) + pow(y, 2)) << endl;
        }

        ~Point (){}

        void display(){
            cout << "Khoang cach tu diem (" << x << ", " << y << ") den goc toa do la: ";
            dist2orig();
        }
    };

int main (){
    Point p1; 
    Point p2 (3, 4);
    Point p3 (5, 5);

    p1.display();
    p2.display();
    p3.display();
    return 0;

}