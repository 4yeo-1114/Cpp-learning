# std::string 常用函数速查手册

> C++ 考试最高频的 string 操作，每个函数附一行示例。

---

## 一、构造

```cpp
string s1;                         // 空串
string s2("hello");                // 从 C 串构造
string s3 = "world";               // 等价写法
string s4(5, 'x');                 // "xxxxx"
string s5(s2);                     // 拷贝
string s6(s2, 1, 3);              // "ell"  从 s2[1] 取 3 个
string s7(s2.begin(), s2.end());  // 迭代器范围
```

## 二、元素访问

| 写法 | 说明 | 越界？ |
|------|------|--------|
| `s[i]` | 下标访问 | ❌ 不检查，快 |
| `s.at(i)` | 下标访问 | ✅ 抛 `out_of_range` |
| `s.front()` | 首字符 | — |
| `s.back()` | 尾字符 | — |

```cpp
string s = "hello";
char c1 = s[0];        // 'h'
char c2 = s.at(1);     // 'e'
char c3 = s.front();   // 'h'
char c4 = s.back();    // 'o'
```

## 三、容量

```cpp
s.size()         // → 3     长度（推荐用这个）
s.length()       // → 3     同上，完全等价
s.empty()        // → true  判空
s.clear()        // 清空为 ""
s.resize(10)     // 变长，后面补 '\0'
s.resize(5,'x')  // 变长，多出的填 'x'
s.reserve(100)   // 预分配容量，避免反复扩容
s.capacity()     // → 当前已分配容量
```

## 四、修改

### 拼接
```cpp
string s = "hello";
s += " world";           // "hello world"   最常用
s.append("!!");          // "hello world!!"
s.append(3, '?');        // "hello world!!???"
s.push_back('!');        // 末尾加一个字符
```

### 插入
```cpp
s.insert(0, "say ");     // 在位置 0 插入
s.insert(0, 3, '#');     // 在位置 0 插入 3 个 '#'
```

### 删除
```cpp
s.erase(0, 4);           // 从 0 删 4 个字符
s.pop_back();            // 删最后一个字符
```

### 替换
```cpp
s.replace(0, 5, "hi");   // 把 [0,5) 替换为 "hi"
```

### 交换
```cpp
string a = "hello", b = "world";
a.swap(b);               // O(1)，比赋值快
```

## 五、查找 ⭐⭐⭐⭐⭐

> **重中之重**：所有 find 没找到都返回 `string::npos`

```cpp
string s = "hello world hello";

// 正向找子串/字符
s.find("hello");          // → 0
s.find("hello", 1);       // → 12   从 pos=1 开始找
s.find('o');              // → 4
s.find("xyz");            // → string::npos (没找到)

// 反向找
s.rfind("hello");         // → 12   最后一个
s.rfind('o');             // → 17

// 找"任意一个"匹配字符
s.find_first_of("aeiou");    // → 1  ('e')
s.find_last_of("aeiou");     // → 17 ('o')

// 找"第一个不匹配"的字符
s.find_first_not_of("helo ");// → 6  ('w')

// 判断是否存在
if (s.find("key") != string::npos) { /* 找到了 */ }
```

## 六、子串

```cpp
string s = "hello world";

s.substr(0, 5);    // "hello"
s.substr(6);       // "world"   从 6 到末尾
s.substr(6, 100);  // "world"   超出不报错，自动截断
```

### 实用技巧：按分隔符切分

```cpp
string csv = "alice,bob,charlie";
size_t pos = 0;
while ((pos = csv.find(',')) != string::npos) {
    string token = csv.substr(0, pos);  // 取逗号前
    csv.erase(0, pos + 1);              // 删掉已取部分+逗号
    cout << token << " ";
}
// 最后剩下的: cout << csv;
```

## 七、比较

```cpp
string a = "abc", b = "abd";

a == b          // false
a != b          // true
a < b           // true  字典序

a.compare(b)             // <0  (a<b);  0 (相等);  >0 (a>b)
a.compare(0, 2, b, 0, 2) // 比较 a[0..1] vs b[0..1]
```

## 八、数值转换

```cpp
// string → 数字（非法字符串会抛异常）
int    n = stoi("42");         // 42
int    n2 = stoi("1010", nullptr, 2); // 10  (二进制)
long   l = stol("1000");      // 1000
double d = stod("3.14");      // 3.14
float  f = stof("2.5");       // 2.5

// 数字 → string
string s1 = to_string(42);    // "42"
string s2 = to_string(3.14);  // "3.140000"  ← 注意精度
```

## 九、C 风格接口

```cpp
string s = "hello";
const char* p = s.c_str();   // 传给 C API 用这个
// ⚠️ s 被修改后 p 可能失效，不要长期持有！
```

## 十、遍历

```cpp
string s = "abc";

// 方式 1: 范围 for（最推荐）
for (char c : s)      cout << c;
for (char& c : s)     c = toupper(c);   // 修改用引用

// 方式 2: 索引
for (size_t i = 0; i < s.size(); ++i)
    s[i] = toupper(s[i]);

// 方式 3: 迭代器
for (auto it = s.begin(); it != s.end(); ++it)
    cout << *it;

// 方式 4: 反向
for (auto it = s.rbegin(); it != s.rend(); ++it)
    cout << *it;
```

## 十一、大小写转换（非 string 自带）

```cpp
#include <cctype>
string s = "Hello";

// 单个字符
char upper = toupper('a');  // 'A'
char lower = tolower('Z');  // 'z'

// 全转大写
for (char& c : s) c = toupper(c);  // "HELLO"

// 全转小写
for (char& c : s) c = tolower(c);  // "hello"
```

---

## 常见笔试题型

| 题型 | 用到的主要函数 |
|------|--------------|
| 判断回文 | `s[i]`, `s.size()` |
| 反转字符串 | `s[i]` 两头交换，或用 `reverse(s.begin(), s.end())` |
| 统计字符频率 | `s[i]` + `int cnt[256]` 数组 |
| 字符串压缩 | `+= char`, `to_string(int)` |
| 分割单词 | `find()`, `substr()`, `erase()` |
| 查找子串 | `find()`, `npos` |
| 数值与字符串互转 | `stoi()`, `to_string()` |
| 去重/去空格 | `erase()` + `remove_if` |
