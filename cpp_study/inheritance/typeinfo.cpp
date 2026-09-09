/* C++ | inheritance: typeinfo. */
#include <iostream>
#include <string>
#include <typeinfo> // 处理 dynamic_cast 引用的 bad_cast 异常

// 1. 抽象类与接口思想
class Animal {
public:
    // 纯虚函数：强制派生类必须实现
    virtual void eat() = 0; 
    
    // 2. 虚析构函数：保证多态下安全释放子类内存
    virtual ~Animal() {
        std::cout << "Animal 基类被销毁\n";
    }
};

// 派生类 A
class Cat : public Animal {
public:
    void eat() override {
        std::cout << "小猫吃鱼！\n";
    }
    
    // 3. final 修饰函数：此方法在此终结，后续子类不可重写
    virtual void meow() final {
        std::cout << "喵喵喵！\n";
    }
    
    ~Cat() override {
        std::cout << "Cat 被销毁\n";
    }
};

// 4. final 修饰类：禁止 Dog 产生下一代子类 c
class Dog final : public Animal { 
public:
    void eat() override {
        std::cout << "小狗吃骨头！\n";
    }
    ~Dog() override {
        std::cout << "Dog 被销毁\n";
    }
};

int main() {
    // 【多态核心体现】使用基类指针统一管理
    Animal* animal1 = new Cat();
    Animal* animal2 = new Dog();

    // 发送相同的 eat 指令，在运行时会查询虚函数表（VTABLE）表现出不同行为
    animal1->eat(); // 运行 Cat::eat()
    animal2->eat(); // 运行 Dog::eat()

    std::cout << "-----------------------\n";

    // 5. 【RTTI 指针转型】: dynamic_cast 
    // 安全地将 Animal 指针转换为 Cat 指针
    Cat* myCat = dynamic_cast<Cat*>(animal1); 
    if (myCat != nullptr) { // 转换失败会返回 nullptr，所以这里判断很安全
        std::cout << "指针转型成功: ";
        myCat->meow();
    }

    // 6. 【RTTI 引用转型】
    try {
        // 如果我们硬要把指向猫的 animal1 强转成狗的引用，必然失败
        Dog& badDog = dynamic_cast<Dog&>(*animal1); 
    } catch (const std::bad_cast& e) {
        std::cout << "引用转型失败，已捕获异常: " << e.what() << '\n';
    }

    std::cout << "-----------------------\n";

    // 7. 测试虚析构
    // 若 Animal 没有 virtual ~Animal()，这里将产生内存泄露！
    delete animal1; 
    delete animal2;

    return 0;
}