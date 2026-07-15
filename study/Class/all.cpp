#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

// ====== 1. 基类 Employee ======
class Employee {
protected: // 使用 protected，让子类可以直接访问 
    string name;
    double baseSalary;

public:
    // 基类构造函数
    Employee(string n, double s) : name(n), baseSalary(s) {
        cout << "[构造] Employee " << name << " 诞生" << endl;
    }
    
    // 基类析构函数
    ~Employee() {
        cout << "[析构] Employee " << name << " 销毁" << endl;
    }

    // 基类的普通方法
    void show() {
        cout << "姓名: " << name << " | 基本工资: " << baseSalary;
    }
};

// ====== 2. 派生类 Manager ======
class Manager : public Employee {
private:
    double bonus;

public:
    // 子类构造函数：必须使用初始化列表，先诞生父类部分 
    Manager(string n, double s, double b) : Employee(n, s), bonus(b) {
        cout << "[构造] Manager " << name << " 诞生" << endl;
    }

    // 子类析构函数
    ~Manager() {
        cout << "[析构] Manager " << name << " 销毁" << endl;
    }

    // 重写并复用父类方法 [cite: 52]
    void show() {
        Employee::show(); // 明确调用父类的方法，防止死循环 
        cout << " | 奖金: " << bonus << " | 总计: " << (baseSalary + bonus) << endl;
    }

    // 声明友元函数，赋予其访问 private 数据的特权
    friend double calculateTotal(Manager& m1, Manager& m2);
};

// ====== 3. 友元函数的实现 ======
double calculateTotal(Manager& m1, Manager& m2) {
    // 友元特权：可以直接访问 m1.bonus (private) 
    // 继承特权：可以直接访问 m1.baseSalary (protected)
    return (m1.baseSalary + m1.bonus) + (m2.baseSalary + m2.bonus);
}

// ====== 4. 主函数 ======
int main() {
    system("chcp 65001");
    // 2. 在 main 函数的第一行加入这句话，修改控制台编码为 UTF-8
    // 开启全局的保留两位小数状态 [cite: 31, 32]
    cout << fixed << setprecision(2); 


    cout << "--- 开始实例化对象 ---" << endl;
    // 方式一：栈内存实例化（系统自动管理）
    Manager m1("Alice", 8000.0, 3000.0);
    
    // 方式二：堆内存动态实例化（需手动 delete）
    Manager* m2 = new Manager("Bob", 9000.0, 4000.0);

    cout << "\n--- 输出数据 ---" << endl;
    m1.show();
    m2->show(); // 注意指针调用方法用 ->

    cout << "\n--- 友元函数计算 ---" << endl;
    cout << "两位经理的总薪资成本: " << calculateTotal(m1, *m2) << endl;

    cout << "\n--- 开始释放内存 ---" << endl;
    delete m2; // 手动销毁 Bob，会立刻触发析构函数

    return 0; 
    // main 函数结束，栈上的 Alice 会在此处被系统自动销毁
}