/* C++ | templates: final 2017. */
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;
template<typename T>
double dist(T a, T b){
    return abs(b - a);
}


class point{
    private:
        double x;
        double y;
        double z;
    public:
        point(double _x1,double _y1,double _z1){
            x = _x1;
            y = _y1;
            z = _z1;
        }
        double operator-(const point&p){
            double px = this->x - p.x;
            double py = this->y - p.y;
            double pz = this->z - p.z;
            return sqrt(px*px+py*py+pz*pz);
        }

};

int main(){
    int n;
    cin>>n;
    while(n!=0){
        if(n==1){
            int a,b;
            cin>>a>>b;
            cout<<dist(a,b)<<endl;
        }
        else if(n==2){
            double a,b;
            cin>>a>>b;
            cout<<dist(a,b)<<endl;
        }
        else if(n==3){
            double x1,y1,z1,x2,y2,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            point a(x1,y1,z1);
            point b(x2,y2,z2);
            cout<<dist(a,b)<<endl;

        }
        cin>>n;
    }

    return 0;
}