/* C++ | inheritance: virtual functions. */
#include <iostream>
#include <vector>

using namespace std;

// 定义常量 PI
const double PI = 3.14159;

// 1. 定义抽象基类 Shape
class Shape {
public:
    // 纯虚函数：输出名称和成员数据
    virtual void printName() = 0; 
    // 纯虚函数：计算面积并返回（用于累加总面积）
    virtual double printArea() = 0;
    // 虚析构函数，确保派生类对象安全释放
    virtual ~Shape() {}
};

// 2. 派生类：圆形 Circle
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void printName() override {
        cout << "圆:半径=" << radius << ", ";
    }
    double printArea() override {
        double area = PI * radius * radius;
        cout << "面积:" << area << endl;
        return area;
    }
};


// 3. 派生类：正方形 Square
class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    void printName() override {
        cout << "正方形:边长=" << side << ", ";
    }
    double printArea() override {
        double area = side * side;
        cout << "面积:" << area << endl;
        return area;
    }
};

// 4. 派生类：长方形 Rectangle
class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void printName() override {
        cout << "长方形:长=" << length << ",宽=" << width << ", ";
    }
    double printArea() override {
        double area = length * width;
        cout << "面积:" << area << endl;
        return area;
    }
};

// 5. 派生类：梯形 Trapezoid
class Trapezoid : public Shape {
    double top, bottom, height;
public:
    Trapezoid(double t, double b, double h) : top(t), bottom(b), height(h) {}
    void printName() override {
        cout << "梯形:上底=" << top << ",下底=" << bottom << ",高=" << height << ", ";
    }
    double printArea() override {
        double area = (top + bottom) * height / 2.0;
        cout << "面积:" << area << endl;
        return area;
    }
};

// 6. 派生类：三角形 Triangle
class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    void printName() override {
        cout << "三角形:底边=" << base << ",高=" << height << ", ";
    }
    double printArea() override {
        double area = base * height / 2.0;
        cout << "面积:" << area << endl;
        return area;
    }
};

int main() {
    double r, s, l, w, t_top, t_bottom, t_h, tri_b, tri_h;

    // 读取输入数据
    cin >> r >> s >> l >> w >> t_top >> t_bottom >> t_h >> tri_b >> tri_h;

    // 定义基类指针数组并动态产生派生类对象
    Shape* shapes[5];
    shapes[0] = new Circle(r);
    shapes[1] = new Square(s);
    shapes[2] = new Rectangle(l, w);
    shapes[3] = new Trapezoid(t_top, t_bottom, t_h);
    shapes[4] = new Triangle(tri_b, tri_h);

    double totalArea = 0;
    // 遍历数组，调用虚函数显示属性及面积
    for (int i = 0; i < 5; ++i) {
        shapes[i]->printName();
        totalArea += shapes[i]->printArea(); // 动态绑定：根据实际类型执行
        delete shapes[i]; // 释放动态生成的内存
    }

    // 输出总面积
    cout << "总面积:" << totalArea << endl;

    return 0;
}