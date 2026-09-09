/* C++ | exams: stl exam. */
/*
 * ============================================================
 *  考试复习题 ③ —— STL 容器与算法（综合）
 * ============================================================
 *
 * 题目：单词统计与成绩管理系统
 *
 * 本题目分为两个独立任务，分别考察 map/set 和 vector/algorithm。
 *
 * ┌─────────────────────────────────────────────────────────┐
 * │  任务 A：单词频率统计（map + set）                       │
 * │                                                         │
 * │  输入：一段英文文本（string）                            │
 * │  要求：                                                  │
 * │  1. 用 map<string, int> 统计每个单词出现的次数          │
 * │  2. 用 set<string> 收集"只出现一次"的单词（hapax词）    │
 * │  3. 输出频率最高的 3 个单词及其出现次数                  │
 * │  4. 输出所有 hapax 词（按字母顺序排列）                  │
 * │                                                         │
 * │  提示：文本预处理 —— 转小写、去标点                     │
 * ├─────────────────────────────────────────────────────────┤
 * │  任务 B：学生成绩管理（vector + algorithm）              │
 * │                                                         │
 * │  定义一个 Student 结构体：                               │
 * │    struct Student {                                      │
 * │        string name;                                      │
 * │        int id;                                           │
 * │        double score;                                     │
 * │    };                                                    │
 * │                                                         │
 * │  要求实现以下功能：                                      │
 * │  1. 用 sort() 按分数降序排序（分数相同按名字升序）       │
 * │  2. 用 find_if() 查找第一个不及格的学生（< 60）          │
 * │  3. 用 count_if() 统计优秀学生人数（>= 90）              │
 * │  4. 用 transform() 或 for_each() 给所有学生加 5 分       │
 * │     （加分后不能超过 100 分）                            │
 * │  5. 用 remove_if() 配合 erase() 删除不及格的学生         │
 * │     （经典的 erase-remove 惯用法）                       │
 * │  6. 用 lambda 表达式作为上述算法的谓词                   │
 * └─────────────────────────────────────────────────────────┘
 *
 * 你需要完成的任务：
 * - 补全函数 wordFrequency()
 * - 补全 Student 结构体（添加比较运算符或提供 lambda）
 * - 补全 main() 中各算法的调用
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>
using namespace std;

// ==================== 任务 A：单词统计 ====================

void wordFrequency(const string& text) {
    cout << "\n========== 任务A：单词频率统计 ==========\n";

    // 你需要的容器
    map<string, int> freq;      // 单词 → 出现次数
    set<string> hapax;          // 只出现一次的单词

    // TODO 1: 文本预处理 + 统计
    // 步骤：
    // a) 用 stringstream 分割单词
    // b) 每个单词转小写、去掉首尾标点
    // c) 统计到 map 中

    // --- 提示代码（你可以用也可以自己写）---
    /*
    string word;
    stringstream ss(text);

    while (ss >> word) {
        // 转小写
        for (char& c : word) c = tolower(c);

        // 去掉首尾非字母字符
        while (!word.empty() && !isalpha(word.front()))
            word.erase(word.begin());
        while (!word.empty() && !isalpha(word.back()))
            word.pop_back();

        if (!word.empty())
            freq[word]++;
    }
    */

    // TODO 2: 收集 hapax 词（频率为 1 的单词）
    /*
    for (const auto& [word, count] : freq) {
        if (count == 1) hapax.insert(word);
    }
    */

    // TODO 3: 输出频率最高的 3 个单词
    // 提示：把 map 的 pair 拷贝到 vector<pair<string,int>> 中，
    // 然后按 count 降序排序
    /*
    cout << "频率 Top 3:\n";
    vector<pair<string, int>> sorted(freq.begin(), freq.end());
    sort(sorted.begin(), sorted.end(),
         [](const auto& a, const auto& b) { return a.second > b.second; });

    int topN = min(3, (int)sorted.size());
    for (int i = 0; i < topN; ++i) {
        cout << "  " << i+1 << ". \"" << sorted[i].first
             << "\" → " << sorted[i].second << " 次\n";
    }
    */

    // TODO 4: 输出所有 hapax 词
    /*
    cout << "\nHapax 词（只出现一次，共 " << hapax.size() << " 个）:\n  ";
    for (const auto& w : hapax) cout << w << " ";
    cout << "\n";
    */
}


// ==================== 任务 B：学生成绩管理 ====================

struct Student {
    string name;
    int id;
    double score;

    // TODO: 可选 —— 添加一个方便输出的方法
};

// 输出 Student 列表的辅助函数
void printStudents(const vector<Student>& students, const string& title) {
    cout << "\n--- " << title << " ---\n";
    cout << left << setw(6) << "ID" << setw(12) << "姓名" << "分数\n";
    cout << string(30, '-') << "\n";
    for (const auto& s : students) {
        cout << left << setw(6) << s.id
             << setw(12) << s.name
             << s.score << "\n";
    }
}


int main() {
    cout << fixed << setprecision(1);

    // ==================== 测试 A ====================

    string text = R"(
        C++ is a powerful language. C++ is also complex.
        But with practice, C++ becomes natural.
        Practice makes perfect, and perfect practice makes a C++ master.
        Language mastery requires patience and practice.
    )";

    wordFrequency(text);

    // ==================== 测试 B ====================

    cout << "\n========== 任务B：学生成绩管理 ==========\n";

    vector<Student> students = {
        {"Alice",   1001, 85.5},
        {"Bob",     1002, 92.0},
        {"Charlie", 1003, 55.0},  // 不及格
        {"Diana",   1004, 78.5},
        {"Eve",     1005, 91.0},
        {"Frank",   1006, 48.0},  // 不及格
        {"Grace",   1007, 88.5},
        {"Henry",   1008, 60.0},  // 刚好及格
    };

    printStudents(students, "原始数据");

    // TODO 1: sort() 按分数降序排序，同分按名字升序
    /*
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) {
             // 分数不同时降序，分数相同时名字升序
             if (a.score != b.score) return a.score > b.score;
             return a.name < b.name;
         });
    */
    // printStudents(students, "按分数降序排序");

    // TODO 2: find_if() 查找第一个不及格学生
    /*
    auto it = find_if(students.begin(), students.end(),
                      [](const Student& s) { return s.score < 60; });
    if (it != students.end())
        cout << "第一个不及格: " << it->name << " (" << it->score << "分)\n";
    else
        cout << "没有不及格的学生！\n";
    */

    // TODO 3: count_if() 统计优秀学生
    /*
    int excellent = count_if(students.begin(), students.end(),
                             [](const Student& s) { return s.score >= 90; });
    cout << "优秀学生(>=90分): " << excellent << " 人\n";
    */

    // TODO 4: 给所有人加 5 分（不超过 100）
    /*
    for_each(students.begin(), students.end(),
             [](Student& s) { s.score = min(100.0, s.score + 5.0); });
    */
    // 或者用 transform:
    /*
    transform(students.begin(), students.end(), students.begin(),
              [](Student s) { s.score = min(100.0, s.score + 5.0); return s; });
    */
    // printStudents(students, "加5分后（上限100）");

    // TODO 5: erase-remove 惯用法删除不及格
    /*
    students.erase(
        remove_if(students.begin(), students.end(),
                  [](const Student& s) { return s.score < 60; }),
        students.end()
    );
    */
    // printStudents(students, "删除不及格后");

    // TODO 6: 用 map<int, Student> 建立 "id → Student" 的映射
    // 用于快速查找某个学号的学生
    /*
    map<int, Student> idMap;
    for (const auto& s : students)
        idMap[s.id] = s;
    cout << "\n通过ID查找 1005: " << idMap[1005].name
         << " " << idMap[1005].score << "分\n";
    */

    cout << "\n所有测试完成!\n";
    return 0;
}


/*
 * ============================================================
 *  预期输出示例
 * ============================================================
 *
 * ========== 任务A：单词频率统计 ==========
 * 输入文本: "C++ is a powerful language. C++ is also complex. ..."
 *
 * 频率 Top 3:
 *   1. "practice" → 3 次
 *   2. "c++" → 3 次
 *   3. "is" → 2 次
 *
 * Hapax 词（只出现一次，共 X 个）:
 *   also becomes but complex language mastery natural patience powerful requires with
 *
 * ========== 任务B：学生成绩管理 ==========
 *
 * --- 原始数据 ---
 * ID   姓名         分数
 * ------------------------------
 * 1001 Alice       85.5
 * 1002 Bob         92.0
 * 1003 Charlie     55.0
 * 1004 Diana       78.5
 * 1005 Eve         91.0
 * 1006 Frank       48.0
 * 1007 Grace       88.5
 * 1008 Henry       60.0
 *
 * --- 按分数降序排序 ---
 * 1002 Bob         92.0
 * 1005 Eve         91.0
 * 1007 Grace       88.5
 * 1001 Alice       85.5
 * 1004 Diana       78.5
 * 1008 Henry       60.0
 * 1003 Charlie     55.0
 * 1006 Frank       48.0
 *
 * 第一个不及格: Henry (60.0分)   ← 排序后第一个 < 60 的是谁？
 * 优秀学生(>=90分): 2 人
 *
 * --- 加5分后（上限100）---
 * (每人 +5，Charlie 60.0, Frank 53.0, Henry 65.0, ... Bob 97.0)
 *
 * --- 删除不及格后 ---
 * (Frank 和 Charlie 被移除)
 *
 * ============================================================
 */
