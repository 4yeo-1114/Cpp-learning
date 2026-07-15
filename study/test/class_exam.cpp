/*
 * ============================================================
 *  考试复习题 ① —— 类与继承（综合）
 * ============================================================
 *
 * 题目：图书管理系统
 *
 * 要求实现以下类层次结构：
 *
 * ┌─────────────────────────────────────────┐
 * │           Book (抽象基类)                │
 * │  - title : string                       │
 * │  - price : double                       │
 * │  + static int totalBooks (静态成员)      │
 * │  + Book(title, price)                   │
 * │  + virtual ~Book()                      │
 * │  + virtual double getPrice() const = 0  │
 * │  + virtual void display() const = 0     │
 * │  + static int getTotalBooks()           │
 * └────────────┬────────────────────────────┘
 *              │
 *     ┌────────┴────────┐
 *     ▼                 ▼
 * ┌──────────┐   ┌──────────────┐
 * │ EBook    │   │ PrintedBook  │
 * │ - fileMB │   │ - pages      │
 * │          │   │ - weight     │
 * │  按原价  │   │  按 pages*0.02│
 * │  计费    │   │  +weight*0.5 │
 * │          │   │  计费        │
 * └──────────┘   └──────────────┘
 *
 * 你需要完成的任务：
 *
 * 1.【基类设计】补全 Book 抽象基类：
 *   - 静态成员 totalBooks，在构造函数中自增，析构函数中自减
 *   - 纯虚函数 getPrice() 和 display()
 *   - 静态函数 getTotalBooks() 返回当前总书本数
 *
 * 2.【派生类实现】补全 EBook 和 PrintedBook：
 *   - EBook::getPrice() 直接返回 price（电子书无额外费用）
 *   - PrintedBook::getPrice() 返回 price + pages*0.02 + weight*0.5
 *   - 各自的 display() 输出所有信息（含 getPrice() 计算结果）
 *
 * 3.【运算符重载】为 Book 添加 operator< 和 operator== ：
 *   - operator< : 按 getPrice() 比较（价格低的在前）
 *   - operator==: title 相同即视为同一本书
 *   - 提示：这两个运算符应放在基类中，且 operator== 可以是虚函数
 *
 * 4.【深拷贝】补全"购物车"类 BookCart：
 *   - 内部用 Book** items 和 int count 管理动态数组
 *   - 实现拷贝构造（深拷贝，需用 dynamic_cast 判断子类类型并 new 对应对象）
 *   - 实现赋值运算符（注意自我赋值检查、释放旧内存）
 *   - 实现 addBook(Book*) 添加一本
 *   - 实现 totalPrice() 计算购物车总价
 *   - 实现析构函数
 *
 * 5.【多态测试】在 main() 中：
 *   - 创建 3 本不同的书加入购物车
 *   - 用基类指针数组遍历并调用 display()
 *   - 输出购物车总价
 *   - 输出当前总书本数
 *
 * 提示：
 * - BookCart 的拷贝构造需要判断实际的派生类型，可定义一个 virtual Book* clone() const 来简化
 * - 注意释放内存时用 delete（不是 delete[]，因为 items[i] 是单个对象指针）
 * - 思考：为什么 getPrice() 不是虚函数也能在 operator< 中正确调用？
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// ==================== 你的代码从这里开始 ====================

// TODO 1: 补全 Book 抽象基类
class Book {
private:
    string title;
    double price;
    static int totalBooks;  // 静态成员：记录当前 Book 对象总数

public:
    Book(const string& t, double p) : title(t), price(p) {
        totalBooks++;
    }

    virtual ~Book() {
        totalBooks--;
    }

    virtual double getPrice() const  =0;
    virtual void  display() const = 0;

    static int getTotalBooks() {
        return  totalBooks;
    }

    // getter（供派生类和外部使用）
    const string& getTitle() const { return title; }
    double getBasePrice() const { return price; }

    // TODO 3: 运算符重载
    // bool operator<(const Book& other) const { ... }
    bool operator<(const Book& other) const{
        return this->getPrice()< other.getPrice();
    }
    // bool operator==(const Book& other) const { ... }
    bool operator==(const Book&other) const{
        return title == other.title;
    }

    // TODO 4: clone 虚函数，用于 BookCart 深拷贝
    // virtual Book* clone() const = 0;
    virtual Book* clone() const = 0;
};

int Book::totalBooks  = 0;


// TODO 2: 补全 EBook 类
class EBook : public Book {
private:
    double fileMB;  // 文件大小（MB）

public:
    EBook(const string& t, double p, double mb)
        : Book(t, p), fileMB(mb) {}
    // TODO: 实现 getPrice(), display(), clone()
    double getPrice() const override {
        return getBasePrice();
    }
    void display() const override {
        cout << "[EBook] " << getTitle()
             << " | 电子书 | 文件: " << fileMB << "MB"
             << " | 价格: ¥" << getPrice();
    }
    Book* clone() const override {
        return new EBook(getTitle(), getBasePrice(), fileMB);
    }

};


// TODO 2: 补全 PrintedBook 类
class PrintedBook : public Book {
private:
    int pages;
    double weight;  // 重量（kg）

public:
    PrintedBook(const string& t, double p, int pg, double w)
        : Book(t, p), pages(pg), weight(w) {}

    // TODO: 实现 getPrice(), display(), clone()
    double getPrice() const override {
        return getBasePrice() + pages * 0.02 + weight * 0.5;
    }
    void display() const override {
        cout << "[PrintedBook] " << getTitle()
             << " | 纸质书 | " << pages << "页"
             << " | " << weight << "kg"
             << " | 价格: ¥" << getPrice();
    }
    Book* clone() const override {
        return new PrintedBook(getTitle(), getBasePrice(), pages, weight);
    }


};


// TODO 4: 补全 BookCart 类（含深拷贝）
class BookCart {
private:
    Book** items;   // 动态数组，元素是 Book*
    int count;
    int capacity;

    // 辅助：扩容
    void ensureCapacity() {
        if (count >= capacity) {
            capacity = (capacity == 0) ? 4 : capacity * 2;
            Book** newItems = new Book*[capacity];
            for (int i = 0; i < count; ++i)
                newItems[i] = items[i];
            delete[] items;
            items = newItems;
        }
    }

public:
    BookCart() : items(nullptr), count(0), capacity(0) {}

    // TODO: 拷贝构造函数（深拷贝）
    // BookCart(const BookCart& other) { ... }
    BookCart(const BookCart& other){
        capacity = other.capacity;
        count = other.count;
        items = new Book*[capacity];
        for(int i = 0;i<count;i++){
            items[i] = other.items[i]->clone();
        }

    }
    // TODO: 赋值运算符
    // BookCart& operator=(const BookCart& other) { ... }
    BookCart& operator=(const BookCart& other) {
        if (this == &other) return *this;
        // 先释放旧资源
        for (int i = 0; i < count; i++) delete items[i];
        delete[] items;
        // 深拷贝
        capacity = other.capacity;
        count = other.count;
        items = new Book*[capacity];
        for (int i = 0; i < count; i++)
            items[i] = other.items[i]->clone();
        return *this;
    }

    ~BookCart(){
        for(int i = 0;i< count;i++) delete items[i];
        delete[] items;
    }

    void addBook(Book* b) {
        ensureCapacity();
        items[count++] = b;
    }

    // TODO: 计算总价
    // double totalPrice() const { ... }
    double totalPrice() const{
        double ans = 0.0;
        for(int i = 0;i<count;i++){
            ans += items[i]->getPrice();
        }
        return ans;
    }

    void showCart() const {
        cout << "\n===== 购物车 (" << count << " 本书) =====\n";
        for (int i = 0; i < count; ++i) {
            cout << "[" << i + 1 << "] ";
            items[i]->display();
            cout << "\n";
        }
        cout << "总价: ¥" << totalPrice() << "\n";
    }
};


// ==================== main() 测试 ====================

int main() {
    cout << fixed << setprecision(2);

    // 创建书本
    EBook* eb = new EBook("C++ Primer E-dition", 59.9, 15.5);
    PrintedBook* pb1 = new PrintedBook("Design Patterns", 79.0, 420, 0.8);
    PrintedBook* pb2 = new PrintedBook("Effective C++", 55.0, 320, 0.6);

    // 测试多态显示
    cout << "--- 多态 display() 测试 ---\n";
    vector<Book*> shelf = { eb, pb1, pb2 };
    for (Book* b : shelf) {
        b->display();
        cout << "\n------------------\n";
    }

    // 测试总书本数（静态成员）
    cout << "\n当前总书本数: " << Book::getTotalBooks() << "\n";

    // 测试运算符重载
    cout << "\n--- 运算符重载测试 ---\n";
    cout << "eb < pb1 ? " << (*eb < *pb1) << " (eb价格=" << eb->getPrice()
         << ", pb1价格=" << pb1->getPrice() << ")\n";

    EBook* eb2 = new EBook("C++ Primer E-dition", 49.9, 20.0);
    cout << "eb == eb2 ? " << (*eb == *eb2)
         << " (同名书: " << eb->getTitle() << ")\n";
    delete eb2;

    // 测试 BookCart 深拷贝
    cout << "\n--- 购物车测试 ---\n";
    BookCart cart1;
    cart1.addBook(eb);
    cart1.addBook(pb1);
    cart1.addBook(pb2);

    // 拷贝构造
    BookCart cart2 = cart1;  // 深拷贝！
    cout << "cart1:\n";
    cart1.showCart();
    cout << "cart2 (深拷贝自 cart1):\n";
    cart2.showCart();

    // 清理
    // 注意：BookCart 析构时应 delete 每本书

    cout << "\n程序结束，析构函数将自动清理...\n";
    return 0;
}


/*
 * ============================================================
 *  预期输出示例（供参考）
 * ============================================================
 *
 * --- 多态 display() 测试 ---
 * [EBook] C++ Primer E-dition | 电子书 | 文件: 15.50MB | 价格: ¥59.90
 * ------------------
 * [PrintedBook] Design Patterns | 纸质书 | 420页 | 0.80kg | 价格: ¥87.80
 * ------------------
 * [PrintedBook] Effective C++ | 纸质书 | 320页 | 0.60kg | 价格: ¥61.70
 * ------------------
 *
 * 当前总书本数: 3
 *
 * --- 运算符重载测试 ---
 * eb < pb1 ? 1 (eb价格=59.90, pb1价格=87.80)
 * eb == eb2 ? 1 (同名书: C++ Primer E-dition)
 *
 * --- 购物车测试 ---
 * ...
 * 总价: ¥209.40
 *
 * ============================================================
 */
