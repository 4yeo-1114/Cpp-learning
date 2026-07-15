#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#define pi 3.14
using namespace std;
class Shape{
    public:
        virtual double getArea()=0;
};
class Circle:public Shape{
     private:
        double r;
    public:
     Circle(double _r){
        r = _r;
     }
     double getArea(){
        return pi*r*r;
     }

};
class Rectangle:public Shape{
    private:
        double l;
        double w;
    public:
         Rectangle(double _l,double _w){
            l = _l;
            w = _w;
         }
         double getArea(){
            return l*w;
         }

};

int main() {
    int T;
    cin >> T; // 读取测试组数

    while (T--) {
        char type;
        cin >> type;

        Shape* s = nullptr;
        if (type == 'C') {
            double r;
            cin >> r;
            s = new Circle(r);
        } else if (type == 'R') {
            double l, w;
            cin >> l >> w;
            s = new Rectangle(l, w);
        }

        if (s != nullptr) {
            // 输出面积，保留2位小数
            cout << fixed << setprecision(2) << s->getArea() << endl;
            delete s;
        }
    }
    return 0;
}