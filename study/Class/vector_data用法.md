# `vector::data()` 详解

## 一句话总结

返回 vector 底层数组的**裸指针**，类型是 `T*`。

## 函数签名

```cpp
T* data() noexcept;                    // 可修改版本
const T* data() const noexcept;       // 只读版本
```

## 它返回什么

`vector` 在堆上维护一块连续内存。`data()` 直接返回指向这块内存**首地址**的指针。

```cpp
vector<int> v = {1, 2, 3, 4, 5};

v.data();   // 返回 int*，指向 v[0] 的位置
            // 等价于 &v[0]，但不要求 vector 非空

// 验证：data() 和 &v[0] 是同一个地址
cout << v.data() << endl;   // 某个堆地址
cout << &v[0] << endl;      // 同一个地址
```

## 和 `&v[0]` 的区别

| | `data()` | `&v[0]` |
|---|---|---|
| 空 vector | 返回非空指针（野指针，不能解引用） | **未定义行为**（`operator[]` 不做边界检查） |
| 可读性 | 意图清晰："我要底层指针" | 绕了个弯："取第一个元素的地址" |
| 推荐程度 | **推荐** | 不推荐 |

```cpp
vector<int> v;           // 空 vector
auto p = v.data();       // 安全，返回某个指针（不能解引用）
auto q = &v[0];          // 未定义行为！v[0] 越界
```

## 数据是连续存储的

C++11 起标准保证 `vector` 内存连续，所以 `data()` 返回的指针可以像数组一样用：

```cpp
vector<int> v = {10, 20, 30, 40, 50};
int* p = v.data();

p[0] = 100;   // 等价于 v[0] = 100
p[3] = 400;   // 等价于 v[3] = 400

for (int i = 0; i < v.size(); i++)
    cout << p[i] << " ";   // 可以像数组一样遍历
```

## 常见用途

### 1. 传给接收 `T*` 的 C 风格 API

```cpp
void legacy_sort(int* arr, size_t n);   // 古老的 C 函数

vector<int> v = {3, 1, 4, 1, 5};
legacy_sort(v.data(), v.size());        // 传底层指针 + 长度
```

### 2. 传给接收 `T[]` 参数的函数

这就是你代码里的场景：

```cpp
static double sumofarea(Container* c[], int n);

vector<Container*> c;
c.push_back(new Cube(3));
c.push_back(new Cylinder(2, 5));

// c.data() 的类型是 Container**  ← 指向 Base* 的指针
// 函数参数 Container* c[] 会退化为 Container**  ← 完全匹配
sumofarea(c.data(), c.size());
```

注意这里的类型推导：
- `vector<Container*>` → `data()` 返回 `Container**`
- 函数参数 `Container* c[]` 等价于 `Container**`
- 所以恰好匹配

### 3. 和指针区间一起使用

```cpp
vector<int> v = {1, 2, 3, 4, 5};
// 把底层数组当作一个区间
sort(v.data(), v.data() + v.size());
//   ↑ begin         ↑ end (尾后)
```

### 4. 零拷贝读写二进制数据

```cpp
vector<char> buf(1024);
ifstream file("data.bin", ios::binary);
file.read(buf.data(), buf.size());           // 直接读到 vector
file.write(buf.data(), bytes_to_write);       // 直接从 vector 写
```

## 常见陷阱

### 陷阱 1：`data()` 返回的指针在扩容后失效

```cpp
vector<int> v = {1, 2, 3};
int* p = v.data();
v.push_back(4);   // 可能触发扩容 → p 变成悬空指针！
cout << p[0];     // 未定义行为
```

### 陷阱 2：空 vector 的 `data()` 不能解引用

```cpp
vector<int> v;
int* p = v.data();   // 没崩，但 p 不指向有效对象
cout << *p;          // 未定义行为
```

### 陷阱 3：`data()` 不等于"vector 本身的地址"

```cpp
vector<int> v = {1, 2, 3};
cout << &v       << endl;  // 栈上 vector 对象自己的地址（三根指针）
cout << v.data() << endl;  // 堆上数据区的地址（1,2,3 存放的地方）
// 这两个地址完全不同
```

## 总结

| 场景 | 写法 |
|---|---|
| 传给需要 `T*` 的 C 接口 | `f(v.data(), v.size())` |
| 传给需要 `T[]` 参数的函数 | `f(v.data())` |
| 获取第一个元素地址 | `v.data()` 而非 `&v[0]` |
| 访问元素 | 直接用 `v[i]` 而非 `v.data()[i]`（本末倒置） |
