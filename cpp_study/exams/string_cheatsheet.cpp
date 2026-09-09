/* C++ | exams: string cheatsheet. */
/*
 * ============================================================
 *  std::string 常考函数速查 + 例题
 * ============================================================
 *
 *  按考试出现频率排列，★ 越多越常考
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// ==============================================================
// 一、构造函数  ★★
// ==============================================================
void demo_constructor() {
    string s1;                    // 空串
    string s2("hello");           // C 风格字符串
    string s3 = "world";          // 同上，赋值写法
    string s4(5, 'x');            // "xxxxx"（n 个字符）
    string s5(s2);                // 拷贝构造
    string s6(s2, 1, 3);          // "ell"（从 pos=1 取 3 个）
    string s7(s2.begin(), s2.end()-1); // 迭代器范围: "hell"
}

// ==============================================================
// 二、元素访问  ★★★★★
// ==============================================================
void demo_access() {
    string s = "hello";

    s[0];          // 'h'  ← 不检查越界！速度快
    s.at(1);       // 'e'  ← 越界抛 out_of_range，安全
    s.front();     // 'h'  ← 首字符（C++11）
    s.back();      // 'o'  ← 尾字符（C++11）
}

// ==============================================================
// 三、容量 / 大小  ★★★★★
// ==============================================================
void demo_capacity() {
    string s = "abc";

    s.size();      // 3    长度（推荐用这个）
    s.length();    // 3    同上，完全等价
    s.empty();     // false  判空（比 s.size()==0 更语义化）
    s.clear();     // 清空，变成 ""
    s.resize(10);  // 扩展到 10 个字符（后面补 '\0'）
    s.resize(5, 'x'); // 扩展到 5，多出的部分填充 'x'
    s.capacity();  // 当前分配的容量（>= size()）
    s.reserve(100);// 预分配空间，避免反复重分配
    s.shrink_to_fit(); // 把 capacity 收缩到 size（C++11）
}

// ==============================================================
// 四、修改操作  ★★★★★
// ==============================================================
void demo_modify() {
    string s = "hello";

    s += " world";         // "hello world"  最常用拼接
    s.push_back('!');      // "hello world!"  追加单个字符
    s.pop_back();          // "hello world"   删除最后一个（C++11）
    s.append("!!");        // "hello world!!" 追加字符串 
    s.append(3, '?');      // "hello world!!???" 

    s.insert(0, "say ");   // "say hello world!!???"  在 pos 处插入
    s.insert(0, 3, '!');   // 插入 3 个 '!' 到开头
    s.insert(s.begin(), '#');  // 迭代器版本

    s.erase(0, 4);         // 从 pos=0 删 4 个 → "hello world!!???"
    s.erase(s.begin());    // 迭代器删一个字符 
    s.erase(s.begin(), s.begin()+3); // 迭代器删一段

    s.replace(0, 5, "hi"); // 从 pos=0 开始，把 5 个字符替换为 "hi"

    string r = "hello";
    string t = "world";
    r.swap(t);             // r="world", t="hello" （常数时间）
}

// ==============================================================
// 五、查找 —— 最常考！ ★★★★★
// ==============================================================
void demo_find() {
    string s = "hello world hello";

    // --- find: 正向找子串/字符 ---
    s.find("hello");        // 0    第一个 "hello" 的位置
    s.find("hello", 1);     // 12   从 pos=1 开始找
    s.find('o');            // 4    第一个 'o'
    s.find("xyz");          // string::npos  ← 没找到返回 npos

    // --- rfind: 反向找 ---
    s.rfind("hello");       // 12   最后一个 "hello"
    s.rfind('o');           // 17   最后一个 'o'

    // --- find_first_of: 找"任意一个"匹配字符 ---
    s.find_first_of("aeiou");   // 1  第一个元音字母 'e'

    // --- find_last_of: 从后往前找"任意一个"匹配字符 ---
    s.find_last_of("aeiou");    // 17 最后一个元音字母 'o'

    // --- find_first_not_of: 找"第一个不匹配"的字符 ---
    s.find_first_not_of("helo "); // 6  'w' (不是 h,e,l,o,空格)

    // 重点：npos 是 size_t 类型的最大值，表示"未找到"
    // if (s.find("x") == string::npos) cout << "没找到";
}

// ==============================================================
// 六、子串  ★★★★★
// ==============================================================
void demo_substr() {
    string s = "hello world";

    s.substr(0, 5);    // "hello"  从 0 开始取 5 个 
    s.substr(6);       // "world"  从 6 取到末尾
    s.substr(6, 100);  // "world"  超出长度自动截断，不报错！

    // 常用技巧：分割字符串
    string csv = "alice,bob,charlie";
    size_t pos = 0;
    while ((pos = csv.find(',')) != string::npos) {
        string token = csv.substr(0, pos);  // 取出逗号前的部分
        csv.erase(0, pos + 1);              // 删掉已取的部分 + 逗号
    }
}

// ==============================================================
// 七、比较  ★★★
// ==============================================================
void demo_compare() {
    string a = "abc", b = "abd";

    a == b;           // false
    a != b;           // true
    a < b;            // true  按字典序比较
    a.compare(b);     // <0    a < b 时返回负数
    a.compare(0, 2, b, 0, 2); // 比较 a[0..1] vs b[0..1] → 0 (相等)
}

// ==============================================================
// 八、数值转换  ★★★★  （重点！atoi 不会抛异常，stoi 会）
// ==============================================================
void demo_convert() {
    // string → 数字
    int    n = stoi("42");          // 42
    long   l = stol("1000");        // 1000
    double d = stod("3.14");        // 3.14
    float  f = stof("2.5");         // 2.5

    // stoi 还可指定进制
    stoi("1010", nullptr, 2);       // 10  (二进制)

    // 数字 → string
    string s1 = to_string(42);      // "42"
    string s2 = to_string(3.14);    // "3.140000"  ← 注意精度！
}

// ==============================================================
// 九、C 风格接口  ★★★
// ==============================================================
void demo_c_api() {
    string s = "hello";
    s.c_str();     // const char*  ← 传 C 接口用这个
    s.data();      // const char* (C++17前) / char* (C++17后)

    // 注意：c_str() 返回的指针在 s 修改后可能失效！
    // 不要长期持有它，用的时候现取
}

// ==============================================================
// 十、遍历  ★★★★★
// ==============================================================
void demo_iterate() {
    string s = "abc";

    // 方式 1: 索引
    for (size_t i = 0; i < s.size(); ++i)
        s[i] = toupper(s[i]); //toupper

    // 方式 2: 范围 for（最推荐！）
    for (char& c : s) c = tolower(c); //tolower

    // 方式 3: 迭代器
    for (auto it = s.begin(); it != s.end(); ++it)
        *it = toupper(*it);

    // 方式 4: 反向遍历
    for (auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it;
}

// ==============================================================
//
//  例题：字符串压缩
//
// ==============================================================
//
// 题目描述：
//   对只含大小写字母的字符串进行"基本压缩"：
//   统计连续相同字符的个数，将"字符+次数"拼接输出。
//   - 如果压缩后不比原串短，则返回原串
//   - 次数用数字拼接即可（如 aab → a2b1，比 aab 长 → 返回 aab）
//
// 示例 1:
//   输入: "aabcccccaaa"
//   输出: "a2b1c5a3"
//
// 示例 2:
//   输入: "abc"
//   输出: "abc"  （a1b1c1 比原串长，返回原串）
//
// 示例 3:
//   输入: "aaAAbb"
//   输出: "a2A2b2"
//
// 要求：
//   1. 用 string 的 +=、push_back、to_string 实现（不要用 sprintf）
//   2. 时间复杂度 O(n)，空间 O(n)
//   3. 写出至少 3 个边界测试用例
//
// 请在 compress() 函数中完成你的代码：

string compress(const string& s) {
    // ── 你的代码 ──

    // TODO: 在这里实现压缩逻辑

    return "";  // 占位，写完删掉这行
    // ──────────────
}

// ==============================================================
// main() 测试
// ==============================================================

int main() {
    // 法一：逐个运行上面的 demo，理解每个函数
    // （已经用函数封装好了，可直接调用查看效果）

    // 法二：测试你的 compress
    cout << "========== 例题测试 ==========\n";

    auto test = [](const string& input, const string& expected) {
        string result = compress(input);
        bool pass = (result == expected);
        cout << (pass ? "✅ " : "❌ ")
             << "输入: \"" << input << "\""
             << " → 输出: \"" << result << "\""
             << " (期望: \"" << expected << "\")\n";
    };

    test("aabcccccaaa", "a2b1c5a3");
    test("abc",         "abc");
    test("aaAAbb",      "a2A2b2");

    // 你自己的边界测试：
    test("",   "");      // 空串 → ？
    test("a",  "a");     // 单字符 → ？
    test("aa", "aa");    // a2 == aa 长度相同 → ？

    return 0;
}


/*
 * ============================================================
 *  参考答案（做完再看！）
 * ============================================================
 *
 * string compress(const string& s) {
 *     if (s.empty()) return s;
 *
 *     string result;
 *     int count = 1;
 *
 *     for (size_t i = 1; i <= s.size(); ++i) {
 *         if (i < s.size() && s[i] == s[i - 1]) {
 *             ++count;
 *         } else {
 *             result += s[i - 1];           // 拼接字符
 *             result += to_string(count);   // 拼接次数
 *             count = 1;
 *         }
 *     }
 *
 *     return result.size() < s.size() ? result : s;
 * }
 *
 * 考点：
 *   - s.size(), s.empty()    容量判断
 *   - s[i]                   元素访问
 *   - result += char         字符串拼接
 *   - to_string(int)         数字转字符串
 *   - 循环边界 i <= s.size() 处理最后一组
 */
