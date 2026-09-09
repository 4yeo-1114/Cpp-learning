/* C++ | inheritance: periodical. */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 基类：期刊
class Periodical {
protected:
    string title;
public:
    Periodical(string name) {
        title = name;
    }
    // 纯虚函数：要求子类必须实现打印收费的逻辑
    virtual void display() = 0;
    
    // 基类的析构函数最好写成虚函数，防止 delete 时内存泄漏
    virtual ~Periodical() {} 
};

// 派生类：杂志
class Magazine : public Periodical {
public:
    float price;   // 每期价格
    float periods; // 订阅期数
    
    Magazine(string name, float pr, float pe) : Periodical(name) {
        price = pr;
        periods = pe;
    }
    
    // 重写纯虚函数
    void display() override {
        // 杂志收费 = 每期价格 * 期数
        cout << title << " " << fixed << setprecision(1) << price * periods << endl;
    }
};

// 派生类：报纸
class Newspaper : public Periodical {
public:
    float price; // 每份价格
    float weeks; // 订阅周数
    float count; // 每周出版次数
    
    Newspaper(string name, float pr, float w, float c) : Periodical(name) {
        price = pr;
        weeks = w;
        count = c;
    }
    
    // 重写纯虚函数
    void display() override {
        // 报纸收费 = 每份价格 * 订阅周数 * 每周出版次数
        cout << title << " " << fixed << setprecision(1) << price * weeks * count << endl;
    }
};

int main() {
    Periodical *pp[10]; // 基类指针数组
    int n;
    cin >> n;
    int i = 0; // 记录实际存入了几个期刊
    
    // 循环读取输入信息
    while (n != 0) {
        if (n == 1) {
            string name;
            float price, periods;
            cin >> name >> price >> periods;
            pp[i] = new Magazine(name, price, periods);
            i++;
        }
        else if (n == 2) {
            string name;
            float price, weeks, count;
            cin >> name >> price >> weeks >> count;
            pp[i] = new Newspaper(name, price, weeks, count);
            i++;
        }
        cin >> n;
    }

    // 集中输出并释放内存
    for (int j = 0; j < i; j++) {
        // 动态绑定：如果是杂志就调用杂志的 display，是报纸就调用报纸的 display
        pp[j]->display(); 
        
        // 释放动态分配的内存
        delete pp[j]; 
    }

    return 0;
}