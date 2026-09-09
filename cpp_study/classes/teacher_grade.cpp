/* C++ | classes: teacher grade. */
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//班主任类 
class Teacher{
    string m_name;        //姓名 
    string m_telephone;   //电话 
    
public:
    Teacher(string name,string telephone);//构造函数声明 
    void show();  //输出姓名、电话   
    ~Teacher();  //析构函数声明 
};
// Teacher 类的成员函数实现
Teacher::Teacher(string name, string telephone) : m_name(name), m_telephone(telephone) {
    cout << "新进老师！" << endl; 
}

void Teacher::show() {
    cout << "新进老师姓名：" << m_name << endl;      
    cout << "新进老师联系电话：" << m_telephone << endl; 
}

Teacher::~Teacher() {
    cout << "调走老师！" << endl; 
}

// Grade 类的定义
class Grade {
private:
    string m_no;
    Teacher m_teacher;

public:
    // 成员初始化列表，正确初始化对象 要与声明顺序一样
    Grade(string m, string name, string phone) : m_no(m), m_teacher(name, phone) {
        cout << "新创建班级!" << endl; 
    }

    void show() {
        cout << "新班级的班号：" << m_no << endl; 
    }

    // 🌟 致命 Bug 修复处：必须加 '&' 返回引用！避免产生临时对象导致多调一次析构！
    Teacher& getTeacher() {
        return m_teacher;
    }
    
    ~Grade() {
        cout << "撤销班级！" << endl; // 注意：中文全角感叹号
    }
};

int main(int argc, char** argv) {

    Grade g1("20级计算机1班","李明德","13567891234"); //定义类Grade的对象g1 
    g1.show();  //调用g1的show,显示g1的数据 
    g1.getTeacher().show(); //输出新进老师的姓名、联系电话
    return 0;
}