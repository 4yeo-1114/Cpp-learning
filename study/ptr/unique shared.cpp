#include <memory>
#include <iostream>

class Node {
public:
    int val;
    Node(int v) : val(v) { std::cout << "节点 " << val << " 诞生了！\n"; }
    ~Node() { std::cout << "节点 " << val << " 被销毁了！\n"; }
};

void testUnique() {
    // 🌟 现代 C++ 推荐用法：用 std::make_unique 来创建
    std::unique_ptr<Node> p1 = std::make_unique<Node>(10);

    std::cout << "当前节点的值是: " << p1->val << "\n";

    // std::unique_ptr<Node> p2 = p1; // ❌ 编译报错！严禁复制！你想抢走我的专属内存？门都没有！

    // 如果非要转移控制权，必须明确使用 std::move (我不要了，送给你)
    std::unique_ptr<Node> p3 = std::move(p1); 
    // 此时 p1 变成了空指针，p3 成为了唯一的真正主人
} 
// 🌟 函数结束，p3 死亡，触发 Node 的析构函数，自动清理内存！没有任何 delete！

void testShared() {
    std::shared_ptr<Node> p1 = std::make_shared<Node>(20); // 计数器 = 1
    {
        std::shared_ptr<Node> p2 = p1; // 允许复制！此时两人共享内存，计数器 = 2
        std::cout << "当前有 " << p1.use_count() << " 个指针共享这块内存\n";
    } 
    // 这个内部大括号结束了，p2 死亡。计数器 -1，变成 1。内存依然存活！

    std::cout << "p2死后，还有 " << p1.use_count() << " 个指针\n";
}
// 函数结束，p1 死亡，计数器变成 0。内存被正式销毁！