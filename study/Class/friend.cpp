#include<iostream>
using namespace std; 
class Faction{
  public:
        int x;
        int y;
    Faction(int _x = 0,int _y = 0){
        x = _x;
        y = _y;
    }
    void display() const{
        cout<<x<<"/"<<y<<endl;
    }
    Faction operator+(const Faction&f){
        return Faction(x*f.y+f.x*y,y*f.y);
    }
    Faction operator+(const int &num){
        return Faction(x+num*y,y);
    }
    //友元函数 相当于全局函数 所以要传两个参数才能实现+ 就当基础的add函数用
    friend Faction operator+(const int &num,const Faction&f){
        return Faction(f.x+num*f.y,f.y);
    }
};

int main() {
    int factor1, factor2;
    cin >> factor1 >> factor2;
    Faction f1(factor1, factor2); // 第一个分数

    cin >> factor1 >> factor2;
    Faction f2(factor1, factor2); // 第二个分数

    int num; // 一个整数
    cin >> num;

    (f1 + f2).display(); // 分数和分数相加
    (f1 + num).display(); // 分数和整数相加
    (num + f1).display(); // 整数和分数相加

    return 0;
}

//用友元函数实现>>和<<的重载

#include <iostream>
using namespace std;
class Vector2D{
    private:
    double x, y;

public:
    // 构造函数
    Vector2D(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    // 重载 + 运算符：向量加法
    Vector2D operator+(const Vector2D& v) const {
        return Vector2D(x + v.x, y + v.y);
    }

    // 重载 - 运算符：向量减法
    Vector2D operator-(const Vector2D& v) const {
        return Vector2D(x - v.x, y - v.y);
    }
    friend istream& operator>>(std::istream& in, Vector2D& v){
        char ch;
        in>>ch>>v.x>>ch>>v.y>>ch;
        return in;
    }
    friend ostream& operator<<(std::ostream& out ,Vector2D& v){
        out<<"("<<v.x<<","<<v.y<<")";
        return out;
    }
    
};