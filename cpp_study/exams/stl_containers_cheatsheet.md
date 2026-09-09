# STL 容器常用函数速查手册

> 按考试出现频率排序：`vector` → `map` → `set` → `stack/queue` → `list/deque` → `priority_queue`

---

## 一、`vector<T>` —— 动态数组 ⭐⭐⭐⭐⭐

> 需要 `#include <vector>`

```cpp
vector<int> v;              // 空
vector<int> v(5);           // 5 个 0
vector<int> v(5, 10);       // 5 个 10
vector<int> v = {1,2,3};    // 初始化列表
vector<int> v2(v);          // 拷贝
```

### 容量
```cpp
v.size()       // 元素个数
v.empty()      // 是否为空
v.capacity()   // 已分配容量
v.resize(10)   // 调整大小，多出来的填 0
v.resize(10,5) // 调整大小，多出来的填 5
v.reserve(100) // 预分配空间（避免反复扩容，重要！）
```

### 访问
```cpp
v[i]           // 不检查越界
v.at(i)        // 检查越界，抛异常
v.front()      // 第一个元素
v.back()       // 最后一个元素
v.data()       // 返回底层 T* 指针（传 C API 用）
```

### 增删
```cpp
v.push_back(x)      // 末尾添加（最常用）
v.emplace_back(...) // 末尾原地构造（比 push_back 少一次拷贝）
v.pop_back()        // 末尾删除
v.insert(v.begin()+i, x)  // 在迭代器位置插入
v.erase(v.begin()+i)      // 删除迭代器位置的元素
v.clear()                 // 清空
```

### 遍历
```cpp
// 范围 for（最推荐）
for (int x : v)        cout << x;
for (int& x : v)       x *= 2;        // 修改

// 索引
for (size_t i = 0; i < v.size(); ++i)  cout << v[i];

// 迭代器
for (auto it = v.begin(); it != v.end(); ++it)  cout << *it;
```

### 考试重点：删除元素（erase-remove 惯用法）

```cpp
// 删除所有值为 target 的元素
v.erase(remove(v.begin(), v.end(), target), v.end());

// 删除所有满足条件的元素
v.erase(remove_if(v.begin(), v.end(),
    [](int x) { return x < 0; }), v.end());
```

### 易错提醒

| 陷阱 | 说明 |
|------|------|
| `v[i]` 越界 | 不会抛异常，悄无声息地错 |
| `push_back` 导致扩容 | 所有迭代器/指针/引用**失效** |
| `v.data()` | 扩容后失效 |
| `v.reserve(n)` 后 `push_back` | size 没变，不能用 `v[i]` 赋值！ |

---

## 二、`map<K,V>` —— 有序键值对（红黑树）⭐⭐⭐⭐⭐

> 需要 `#include <map>`
> key 唯一，自动按 key 升序排列，查找 O(log n)

```cpp
map<string, int> m;

// 插入（三种方式）
m["alice"] = 95;              // 最简单。⚠️ key 不存在时会自动创建！
m.insert({"bob", 87});        // key 已存在则忽略
m.emplace("charlie", 92);     // 原地构造，推荐

// 查找
if (m.count("alice")) { }         // 存在返回 1，不存在返回 0
if (m.find("alice") != m.end()){} // 标准查找方式
auto it = m.find("bob");          // 返回迭代器，没找到返回 end()
int score = m["alice"];           // ⚠️ 不存在时创建默认值并返回！

// 用 find 安全访问（不会意外插入）
auto it = m.find("key");
if (it != m.end()) cout << it->second;

// 遍历（按 key 升序）
for (const auto& [key, value] : m)    // C++17 结构化绑定
    cout << key << " → " << value;

for (const auto& p : m)               // C++11
    cout << p.first << " → " << p.second;

// 删除
m.erase("alice");               // 按 key 删
m.erase(it);                    // 按迭代器删
m.clear();
```

### 常用场景
| 场景 | 写法 |
|------|------|
| 频率统计 | `m[s]++` |
| 是否存在 | `m.count(key) > 0` |
| 安全查找 | `m.find(key) != m.end()` |
| 按 key 排序输出 | 直接遍历，已有序 |
| 按 value 排序输出 | 拷贝到 `vector<pair>` 再用 `sort` + lambda |

---

## 三、`set<T>` —— 有序集合（红黑树）⭐⭐⭐⭐

> 需要 `#include <set>`
> 元素唯一、自动升序，查找 O(log n)

```cpp
set<int> s = {3, 1, 4, 1, 5};  // {1, 3, 4, 5} 自动去重排序

// 插入删除
s.insert(x);                 // 插入。返回 pair<迭代器,是否成功>
s.erase(x);                  // 删除
s.erase(it);                 // 按迭代器删
s.clear();

// 查找
if (s.count(x)) { }          // 存在？
if (s.find(x) != s.end()){}  // 标准查找
auto it = s.find(x);         // 返回迭代器

// 遍历（自动升序）
for (int x : s) cout << x;
```

### 考试常用
```cpp
// 去重 + 排序
vector<int> v = {3,1,4,1,5,9,2,6};
set<int> s(v.begin(), v.end());   // 一步完成去重排序

// 求交集 / 差集
// 用 set_intersection / set_difference 算法
```

---

## 四、`unordered_map` / `unordered_set` —— 哈希版 ⭐⭐⭐

> 需要 `#include <unordered_map>` / `<unordered_set>`
> **无序**，查找 O(1) 平均，O(n) 最坏

```cpp
unordered_map<string, int> um;
um["a"] = 1;                 // 用法同 map，不赘述

unordered_set<int> us;
us.insert(3);
```

### 什么时候用哪个？

| | `map` / `set` | `unordered_map` / `unordered_set` |
|---|---|---|
| 内部实现 | 红黑树 | 哈希表 |
| 有序性 | ✅ 自动排序 | ❌ 无序 |
| 查找 | O(log n) | O(1) 平均 |
| 需要有序输出时 | ✅ | ❌ |
| 只查不遍历 | 后者更快 |

---

## 五、`stack<T>` —— 栈 ⭐⭐⭐⭐

> 需要 `#include <stack>`，LIFO

```cpp
stack<int> stk;

stk.push(x);      // 入栈
stk.pop();        // 出栈（不返回值！）
stk.top();        // 取栈顶
stk.empty();      // 判空
stk.size();       // 大小

// ⚠️ pop() 不返回被弹出的值！先 top() 再 pop()
int x = stk.top();
stk.pop();
```

### 经典应用
- 括号匹配
- 表达式求值
- DFS 非递归实现
- 单调栈（找下一个更大元素）

---

## 六、`queue<T>` —— 队列 ⭐⭐⭐⭐

> 需要 `#include <queue>`，FIFO

```cpp
queue<int> q;

q.push(x);      // 入队
q.pop();        // 出队（同样不返回值！）
q.front();      // 取队首（最先进入的）
q.back();       // 取队尾（最后进入的）
q.empty();
q.size();

// ⚠️ 同样：pop() 不返回，先 front() 再 pop()
int x = q.front();
q.pop();
```

### 经典应用
- BFS 层级遍历
- 生产者-消费者模型
- 二叉树层序遍历

---

## 七、`priority_queue<T>` —— 优先队列（堆）⭐⭐⭐

> 需要 `#include <queue>`，默认大顶堆

```cpp
// 默认大顶堆（最大在队首）
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> min_pq; // 小顶堆

pq.push(x);       // 入堆，O(log n)
pq.pop();         // 出堆，O(log n)
pq.top();         // 取堆顶，O(1)
pq.empty();
pq.size();
```

### 自定义比较（考试重点！）

```cpp
// 方法 1: 自定义比较函数对象
struct cmp {
    bool operator()(int a, int b) { return a > b; }  // 小顶堆
};
priority_queue<int, vector<int>, cmp> pq;

// 方法 2: lambda (C++17)
auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
```

### 经典应用
- Top K 问题
- 第 K 大/小元素
- 合并 K 个有序链表
- Dijkstra 最短路

---

## 八、`deque<T>` —— 双端队列 ⭐⭐

> 需要 `#include <deque>`

```cpp
deque<int> dq;

// 头尾都能操作
dq.push_back(x);       dq.push_front(x);
dq.pop_back();         dq.pop_front();
dq.front();            dq.back();
d[i];                  // 支持随机访问！
```

### vs vector
| | `vector` | `deque` |
|---|---|---|
| 头插 | O(n) 慢 | O(1) 快 |
| 尾插 | O(1) | O(1) |
| 随机访问 | O(1) | O(1) 但略慢 |
| 内存 | 连续 | 分段连续 |

---

## 九、`list<T>` —— 双向链表 ⭐⭐

> 需要 `#include <list>`

```cpp
list<int> lst;

lst.push_back(x);        lst.push_front(x);
lst.pop_back();          lst.pop_front();
lst.insert(it, x);       lst.erase(it);
lst.size();              lst.clear();

// 自带 sort 和 unique
lst.sort();
lst.unique();            // 删除连续重复元素
```

### 何时用 list
- 频繁在中间插入/删除
- **不支持随机访问**，不能用 `lst[i]`

---

## 十、`<algorithm>` 常用算法 ⭐⭐⭐⭐⭐

> 需要 `#include <algorithm>`

### 排序与查找
```cpp
vector<int> v = {3, 1, 4, 1, 5};

// 排序
sort(v.begin(), v.end());                  // 升序
sort(v.begin(), v.end(), greater<int>());  // 降序
sort(v.begin(), v.end(),                   // 自定义
     [](int a, int b) { return a > b; });

// 二分查找（要求已排序！）
binary_search(v.begin(), v.end(), x);      // 返回 bool
auto it = lower_bound(v.begin(), v.end(), x); // 第一个 >= x
auto it = upper_bound(v.begin(), v.end(), x); // 第一个 > x

// 查找
auto it = find(v.begin(), v.end(), x);         // 线性找值
auto it = find_if(v.begin(), v.end(),          // 条件查找
                  [](int x) { return x < 0; });

// 计数
int n = count(v.begin(), v.end(), x);          // 值出现次数
int n = count_if(v.begin(), v.end(),           // 满足条件次数
                 [](int x) { return x >= 60; });
```

### 修改
```cpp
// 反转
reverse(v.begin(), v.end());

// 去重（先排序！）
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// 填充
fill(v.begin(), v.end(), 0);

// 交换
swap(a, b);                        // 两个元素
iter_swap(it1, it2);              // 两个迭代器指向的元素

// 拷贝
copy(src.begin(), src.end(), dst.begin());
```

### 极值
```cpp
auto it = max_element(v.begin(), v.end());  // 最大元素迭代器
auto it = min_element(v.begin(), v.end());  // 最小元素迭代器
auto [mi, ma] = minmax_element(v.begin(), v.end()); // 同时取 (C++17)

int mx = *max_element(v.begin(), v.end());
int mn = *min_element(v.begin(), v.end());
```

### 全排列
```cpp
sort(v.begin(), v.end());          // 必须先排序
do {
    // 处理当前排列
} while (next_permutation(v.begin(), v.end()));
```

---

## 十一、快速选择指南

| 需求 | 用什么 |
|------|--------|
| 动态数组、随机访问 | `vector` |
| key-value 查找、频率统计 | `map` 或 `unordered_map` |
| 去重 + 自动排序 | `set` |
| LIFO（括号匹配、DFS） | `stack` |
| FIFO（BFS、层序遍历） | `queue` |
| Top K、最值优先 | `priority_queue` |
| 头尾都要快速插入 | `deque` |
| 中间频繁插入删除 | `list` |
| 排序 | `sort()` |
| 二分查找 | `lower_bound()` / `binary_search()` |
| 全排列 | `next_permutation()` |

---

## 十二、易错提醒 Top 5

1. **`stack::pop()` / `queue::pop()` 不返回值** —— 必须先用 `top()` / `front()` 取值再 `pop()`
2. **`map::operator[]` 会插入默认值** —— 只想检查是否存在时用 `find()` 或 `count()`
3. **遍历容器时删除元素** —— 用 `it = v.erase(it)` 接住返回值，否则迭代器失效
4. **`sort` 前要保证可比较** —— 自定义类型需要 `operator<` 或传入 lambda
5. **`lower_bound` 要求有序** —— 对未排序容器用它是未定义行为
