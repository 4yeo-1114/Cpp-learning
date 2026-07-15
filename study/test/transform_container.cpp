/*
 * ============================================================
 *  transformContainer —— STL 函数对象 + transform 算法
 * ============================================================
 *
 *  题目：实现函数模板 transformContainer，对容器每个元素应用指定操作
 *  操作类型：square（平方）、double（翻倍）、negate（取反）
 *
 *  考点：
 *    - std::transform 算法
 *    - 函数对象（multiplies、negate、bind）
 *    - 函数模板
 *    - lambda 表达式
 */

#include <iostream>
#include <vector>
#include <algorithm>   // transform
#include <functional>  // multiplies, negate, bind
#include <string>
using namespace std;

// ==================== 函数模板 transformContainer ====================
// 对容器 v 的每个元素应用 op 操作，结果存回原容器
template<typename Container, typename Operation>
void transformContainer(Container& v, Operation op) {
    transform(v.begin(), v.end(), v.begin(), op);
}

// ==================== main ====================

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    string op;
    cin >> op;

    if (op == "square") {
        // 平方 = 自己乘自己 → bind + multiplies
        transformContainer(v, bind(multiplies<int>(), placeholders::_1, placeholders::_1));
    }
    else if (op == "double") {
        // 翻倍 = 每个元素 × 2 → bind + multiplies
        transformContainer(v, bind(multiplies<int>(), placeholders::_1, 2));
    }
    else if (op == "negate") {
        // 取反 → negate 函数对象
        transformContainer(v, negate<int>());
    }

    // 输出结果
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << endl;

    return 0;
}
