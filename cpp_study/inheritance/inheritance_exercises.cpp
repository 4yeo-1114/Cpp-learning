/* C++ | inheritance: inheritance exercises. */
#include <iostream>
using namespace std;

class Person{
    public:
        virtual void bellRing()  =0;
        virtual ~Person(){};
};
class Student: public Person{
    public:
        void bellRing () override{
            cout<<"I am a student learning in classroom."<<endl;
        }
        ~Student(){
            cout<<"A student object destroyed."<<endl;
        }

};
class Teacher: public Person{
    public:
        void bellRing () override{
            cout<<"I am a teacher teaching in classroom."<<endl;
        }
        ~Teacher(){
            cout<<"A teacher object destroyed."<<endl;
        }

};
class Principal: public Person{
    public:
        void bellRing () override{
            cout<<"I am the principal inspecting in campus."<<endl;
        }
        ~Principal(){
            cout<<"A principal object destroyed."<<endl;
        }

};

int main() {
    cout << "School bell rings..." << endl;
    Person* persons[3] = {new Student(),new Teacher(),new Principal()};
    persons[0]->bellRing();
    persons[1]->bellRing();
    persons[2]->bellRing();
    for (auto i=0;i<3;i++)
        delete persons[i];
    return 0;
}

//虚继承
// SaleManager::SaleManager(string xnum,string xname,double xbasicSalary,double xprize,double xdeductRate,double xpersonAmount,double xtotalDeductRate,double xtotalAmount)
// :Employee(xnum,xname,xbasicSalary,xprize), Saleman(xnum,xname,xbasicSalary,xprize,xdeductRate,xpersonAmount),Manager(xnum,xname,xbasicSalary,xprize,xtotalDeductRate,xtotalAmount){}
// void SaleManager::Show()
//     {
//         Employee::Show();

//     cout<<"销售员提成比例："<<deductRate<<" ";
//     cout<<"个人销售额："<<personAmount<<endl;

//     cout<<"经理提成比例："<<totalDeductRate<<" ";
//     cout<<"总销售额："<<totalAmount<<endl;
        
//     }
// void SaleManager:: ShowSalary() 
//     {
//         cout<<"销售经理实发工资：";
//         cout<<basicSalary + prize + totalDeductRate * totalAmount+personAmount * deductRate<<endl<<endl;
//     }



//类模板
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void bubbleSort(T arr[],int n){
    for(int i= 0 ;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template <typename T>
int binarySearch(T arr[],int n,T key){
    int l = -1;
    int r = n;
    while(l+1<r){
        int mid = l +(r-l)/2;
        if(arr[mid]>=key){
            r = mid;
        }
        else{
            l  = mid;
        }
    }
    // 不能直接写 return arr[r]==key?r:-1;因为r可能还是n会越界
    if(r>=n) return -1;
    else return arr[r] == key ? r : -1;
}

template <typename T>
class Stack{
    private:
        int top;
        T arr[100000];
    public:
        Stack(){
            top  = 0;
        }
        void push(T item){
            arr[top++] = item;
        }
        T pop(){
            top--;
            return arr[top];
        }
        bool isEmpty(){
            return top==0;
        }
        int size(){
            return top;
        }

};


int main() {
    std::cout << "=== int 测试 ===" << std::endl;
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(intArr) / sizeof(intArr[0]);
    std::cout << "排序前: ";
    printArray(intArr, n1);
    bubbleSort(intArr, n1);
    std::cout << "排序后: ";
    printArray(intArr, n1);
    int idx = binarySearch(intArr, n1, 25);
    std::cout << "查找 25: index = " << idx << std::endl;
    
    std::cout << "\n=== double 测试 ===" << std::endl;
    double dblArr[] = {3.14, 1.41, 2.72, 1.73, 2.24};
    int n2 = sizeof(dblArr) / sizeof(dblArr[0]);
    std::cout << "排序前: ";
    printArray(dblArr, n2);
    bubbleSort(dblArr, n2);
    std::cout << "排序后: ";
    printArray(dblArr, n2);
    idx = binarySearch(dblArr, n2, 2.72);
    std::cout << "查找 2.72: index = " << idx << std::endl;
    
    std::cout << "\n=== string 栈测试 ===" << std::endl;
    Stack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("C++");
    
    std::cout << "栈大小: " << strStack.size() << std::endl;
    while (!strStack.isEmpty()) {
        std::cout << "弹出: " << strStack.pop() << std::endl;
    }
    std::cout << "栈为空: " << (strStack.isEmpty() ? "是" : "否") << std::endl;
    
    return 0;
}










#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const {
        std::cout << "Shape";
    }
    virtual ~Shape() {}
};

class Circle:public Shape{
    public:
        double r;
        Circle(double _r):r(_r){}
        double area() const{
            return 3.1415*r*r;
        }
        double perimeter()  const{
            return 2*3.1415*r;
        }
        void print()  const{
            std::cout<<"Circle";
        }

};

class Rectangle:public Shape{
    public:
        double l,w;
        Rectangle(double _l,double _w):l(_l),w(_w){}
        double area() const{
            return l*w;
        }
        double perimeter()  const{
            return (l+w)*2;
        }
        void print() const{
            std::cout<<"Rectangle";
        }

};

class Triangle:public Shape{
    public:
     double a,b,c;
     Triangle(double _a,double _b,double _c){
        a = _a;
        b = _b;
        c = _c;
     }
     double area() const{
        double s =(a+b+c)/2.0;
        return std::sqrt(s*(s-a)*(s-b)*(s-c)); 
     }
     double perimeter() const{
        return a+b+c;
     }
     void print() const{
        std::cout<<"Triangle";
     }


};

class Square:public Rectangle{
    public:
        Square(double _a):Rectangle(_a,_a){
           
        }
        void print() const{
        std::cout<<"Square";
     }
};

int main() {
    Shape* shapes[] = {
        new Circle(5.0),
        new Rectangle(4.0, 6.0),
        new Triangle(3.0, 4.0, 5.0),
        new Square(3.0)
    };
    
    int n = sizeof(shapes) / sizeof(shapes[0]);
    
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < n; i++) {
        shapes[i]->print();
        std::cout << ": area = " << shapes[i]->area() 
                  << ", perimeter = " << shapes[i]->perimeter() << std::endl;
    }
    
    for (int i = 0; i < n; i++) {
        delete shapes[i];
    }
    
    return 0;
}