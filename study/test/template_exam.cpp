/*
 * ============================================================
 *  考试复习题 ② —— 模板（综合）
 * ============================================================
 *
 * 题目：通用数据处理工具库
 *
 * 你需要实现以下 4 个模板组件：
 *
 * ┌──────────────────────────────────────────────────┐
 * │  1. 函数模板  findMax(iter begin, iter end)      │
 * │     → 返回 [begin, end) 中最大元素的迭代器       │
 * │     → 若区间为空，返回 end                       │
 * │     → 要求：支持任意迭代器类型和任意可比较元素   │
 * ├──────────────────────────────────────────────────┤
 * │  2. 函数模板  bubbleSort(T arr[], int n)         │
 * │     → 冒泡排序（升序），原地排序                 │
 * │     → 要求：T 必须支持 operator< 和 operator=    │
 * ├──────────────────────────────────────────────────┤
 * │  3. 类模板    Pair<K, V>                         │
 * │     → 键值对，含 key(K) 和 value(V)              │
 * │     → operator< : 按 key 比较                    │
 * │     → operator<< : 输出为 "(key, value)" 格式    │
 * │     → 友元形式重载 operator<<                    │
 * ├──────────────────────────────────────────────────┤
 * │  4. 类模板    SimpleSet<T>                       │
 * │     → 用静态数组 T data[100] 实现，记录 size     │
 * │     → insert(T): 元素不存在则插入，返回 bool     │
 * │     → remove(T): 删除元素并前移，返回 bool       │
 * │     → contains(T): 返回是否包含                  │
 * │     → size(): 返回元素个数                       │
 * │     → operator[]: 返回第 i 个元素（const 版本）  │
 * │     → 提示：insert 时用 findMax 的逻辑线性查找   │
 * └──────────────────────────────────────────────────┘
 *
 * 额外挑战（选做）：
 * - 为 Pair 添加模板特化 Pair<string, int>，display 时用特殊格式
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ==================== TODO 1: findMax ====================

// 提示：函数模板，接受两个迭代器，返回最大元素的迭代器
// template <typename Iter>
// Iter findMax(Iter begin, Iter end) { ... }
template <typename Iter>
Iter findMax(Iter begin,Iter end){
    Iter max = begin;
    if(begin==end) return end;
    for(Iter it = begin;it<end;it++){
        if(*it>(*max)){
            max = it;
        }
    }
    return max;
}


// ==================== TODO 2: bubbleSort ====================

// 提示：函数模板，对数组原地冒泡排序
// template <typename T>
// void bubbleSort(T arr[], int n) { ... }
template <typename T>
void bubbleSort(T arr[],int n){
    for(int i = 0;i<n-1;i++){
        for(int j  =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                T temp  = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


// ==================== TODO 3: Pair 类模板 ====================

template <typename K, typename V>
class Pair {
private:
    K key;
    V value;
public:
    Pair(K k = K(), V v = V()) : key(k), value(v) {}

    // 按 key 比较
    bool operator<(const Pair& other) const {
        return key < other.key;
    }

    // 友元：输出 (key, value)
    // ⚠️ 类模板的友元声明要用不同的模板参数名，避免和类模板参数冲突
    template <typename K2, typename V2>
    friend ostream& operator<<(ostream& os, const Pair<K2, V2>& p);
};

// 友元在类外实现
template <typename K, typename V>
ostream& operator<<(ostream& os, const Pair<K, V>& p) {
    os << "(" << p.key << ", " << p.value << ")";
    return os;
}


// ==================== TODO 4: SimpleSet 类模板 ====================

template <typename T>
class SimpleSet {
private:
    T data[100];
    int sz;
public:
    SimpleSet() : sz(0) {}

    // 插入（不存在才插入）
    bool insert(T x) {
        if (contains(x)) return false;    // 已存在
        if (sz >= 100)    return false;    // 满了
        data[sz++] = x;
        return true;
    }

    // 删除（找到后后面的元素全部前移）
    bool remove(T x) {
        for (int i = 0; i < sz; i++) {
            if (data[i] == x) {            // 需要 T 有 operator==
                for (int j = i; j < sz - 1; j++)
                    data[j] = data[j + 1];
                sz--;
                return true;
            }
        }
        return false;
    }

    bool contains(T x) const {
        for (int i = 0; i < sz; i++)
            if (data[i] == x) return true;
        return false;
    }

    int size() const { return sz; }

    const T& operator[](int i) const { return data[i]; }
};


// ==================== 测试用自定义类 ====================

// 三维点类，用于测试模板是否支持自定义类型
class Point3D {
private:
    double x, y, z;
public:
    Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    double length() const {
        return sqrt(x*x + y*y + z*z);
    }

    // 让 Point3D 能用于 SimpleSet 和 findMax，需要 operator== 和 operator<
    bool operator==(const Point3D& p) const {
        return x == p.x && y == p.y && z == p.z;
    }
    bool operator<(const Point3D& p) const {
        return length() < p.length();
    }

    // 用于输出
    friend ostream& operator<<(ostream& os, const Point3D& p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    }
};


// ==================== main() 测试 ====================

int main() {
    cout << boolalpha;  // 让 bool 输出 true/false 而不是 1/0

    // ===== 测试 1: findMax =====
    cout << "========== 测试 findMax ==========\n";

    int iarr[] = {3, 7, 2, 9, 5, 1, 8};
    int n = sizeof(iarr) / sizeof(iarr[0]);
    cout << "int 数组最大值: " << *findMax(iarr, iarr + n) << "\n";

    double darr[] = {3.14, 2.71, 1.41, 1.73, 2.23};
    int dn = sizeof(darr) / sizeof(darr[0]);
    cout << "double 数组最大值: " << *findMax(darr, darr + dn) << "\n";

    cout << "空区间: findMax == end ? "
         << (findMax(iarr, iarr) == iarr) << "\n";

    // ===== 测试 2: bubbleSort =====
    cout << "\n========== 测试 bubbleSort ==========\n";

    int sortArr[] = {5, 2, 8, 1, 9, 3};
    int sn = sizeof(sortArr) / sizeof(sortArr[0]);
    bubbleSort(sortArr, sn);
    cout << "排序后: ";
    for (int i = 0; i < sn; i++) cout << sortArr[i] << " ";
    cout << "\n";

    // ===== 测试 3: Pair =====
    cout << "\n========== 测试 Pair ==========\n";

    Pair<string, int> p1("Alice", 95);
    Pair<string, int> p2("Bob", 87);
    Pair<int, double> p3(42, 3.14159);

    cout << p1 << "\n";                     // (Alice, 95)
    cout << p2 << "\n";                     // (Bob, 87)
    cout << p3 << "\n";                     // (42, 3.14159)
    cout << "p1 < p2 ? " << (p1 < p2) << "\n";  // true

    // ===== 测试 4: SimpleSet =====
    cout << "\n========== 测试 SimpleSet ==========\n";

    SimpleSet<int> si;
    cout << "insert 3: " << si.insert(3) << "\n";
    cout << "insert 1: " << si.insert(1) << "\n";
    cout << "insert 4: " << si.insert(4) << "\n";
    cout << "insert 1: " << si.insert(1) << "\n";   // 重复 → false
    cout << "insert 5: " << si.insert(5) << "\n";
    cout << "size: " << si.size() << "\n";
    cout << "元素: ";
    for (int i = 0; i < si.size(); i++) cout << si[i] << " ";
    cout << "\n";
    cout << "contains(3): " << si.contains(3) << "\n";
    cout << "contains(99): " << si.contains(99) << "\n";
    cout << "remove(1): " << si.remove(1) << "\n";
    cout << "删除 1 后: ";
    for (int i = 0; i < si.size(); i++) cout << si[i] << " ";
    cout << "\n";
    cout << "remove(99): " << si.remove(99) << "\n";

    SimpleSet<string> ss;
    ss.insert("hello");
    ss.insert("world");
    ss.insert("c++");
    cout << "string set 元素: ";
    for (int i = 0; i < ss.size(); i++) cout << ss[i] << " ";
    cout << "\n";

    cout << "\n所有测试完成!\n";
    return 0;
}


/*
 * ============================================================
 *  预期输出示例
 * ============================================================
 *
 * ========== 测试 findMax ==========
 * int 数组最大值: 9
 * double 数组最大值: 3.14
 * 空区间: findMax == end ? true
 *
 * ========== 测试 bubbleSort ==========
 * 排序后: 1 2 3 5 8 9
 *
 * ========== 测试 Pair ==========
 * (Alice, 95)
 * (Bob, 87)
 * (42, 3.14159)
 * p1 < p2 ? true
 *
 * ========== 测试 SimpleSet ==========
 * int set size: 4
 * 元素: 3 1 4 5
 * contains(3): true
 * contains(99): false
 * 删除 1 后: 3 4 5
 * 删除 99 (不存在): false
 *
 * string set 元素: hello world c++
 *
 * 所有测试完成!
 *
 * ============================================================
 */
