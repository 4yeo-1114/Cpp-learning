#include <iostream>
#include <iomanip>    // setw, left
#include <sstream>    // 用于 to_string（或算数字宽度）
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Score {
    string name;
    int mark;
public:
    Score():mark(0) {}
    Score(string _name, int _mark) 
        : name(_name), mark(_mark) {}
    string getName() { return name; } 
    int getMark() { return mark; }
    void scan() { 
        cin>> name >> mark; 
    }
};

class Student {
    string name;
    map<string, int> mScore;
public:
    string getName() { return name; }
    void scan();
    set<string> getCourseNames();
    int getMarkByCourseName(string courseName);
};

class Department {
    vector<Student> vStudent;
public:
    void scan() {
        int number;
        cin >> number;
        for ( int i=0; i<number; i++ ) {
            Student stu;
            stu.scan();
            vStudent.push_back(stu);
        }
    }
    void report();
};


int main()
{
    Department dept;
    dept.scan();
    dept.report();
    return 0;
}


// ==================== Student 成员函数实现 ====================

void Student::scan() {
    // cin>>ws 吃掉所有前导空白（换行、空格、tab），比 cin.ignore() 安全
    cin >> ws;
    getline(cin, name);                 // 读整行作为姓名

    int m;
    cin >> m;                           // 课程数量
    for (int i = 0; i < m; i++) {
        Score sc;                       // ← 用老师给的 Score 类
        sc.scan();                      // 读入课程名和成绩
        mScore[sc.getName()] = sc.getMark();
    }
}

// 返回这个学生修过的所有课程名（set 自动去重 + 字典序）
set<string> Student::getCourseNames() {
    set<string> result;
    for (const auto& p : mScore)
        result.insert(p.first);
    return result;
}

// 查某门课的成绩，没修过返回 -1（约定值，调用方判断）
int Student::getMarkByCourseName(string courseName) {
    auto it = mScore.find(courseName);
    if (it != mScore.end())
        return it->second;
    else
        return -1;   // -1 表示没修这门课
}


// ==================== Department::report() ====================

void Department::report() {
    int N = vStudent.size();

    // --- 第 1 步：收集所有课程名（set 自动字典序） ---
    set<string> allCourses;
    for (int i = 0; i < N; i++)
        for (const string& c : vStudent[i].getCourseNames())
            allCourses.insert(c);

    vector<string> courses(allCourses.begin(), allCourses.end());
    int C = courses.size();

    // --- 第 2 步：计算每列的宽度（取该列最宽内容的长度） ---
    const int GAP = 4;                        // 列间距（空格数）
    vector<int> colW(C + 2);                 // +2: name 列 + average 列

    // name 列宽度
    colW[0] = 4;                             // 至少 "name" 的长度
    for (int i = 0; i < N; i++)
        colW[0] = max(colW[0], (int)vStudent[i].getName().size());

    // 每门课列宽度
    for (int k = 0; k < C; k++) {
        colW[k + 1] = courses[k].size();    // 至少表头长度
        for (int i = 0; i < N; i++) {
            int sc = vStudent[i].getMarkByCourseName(courses[k]);
            if (sc != -1)
                colW[k + 1] = max(colW[k + 1], (int)to_string(sc).size());
            else
                colW[k + 1] = max(colW[k + 1], 1);  // "-" 占 1 字符
        }
    }

    // average 列宽度
    colW[C + 1] = 7;                         // "average" 长度
    for (int i = 0; i < N; i++)
        colW[C + 1] = max(colW[C + 1], 2);   // avg 最多 3 位，至少 2 位

    // --- 第 3 步：输出表头 ---
    cout << left << setw(colW[0] + GAP) << "name";
    for (int k = 0; k < C; k++)
        cout << left << setw(colW[k + 1] + GAP) << courses[k];
    cout << "average" << endl;               // average 列不加 GAP

    // --- 第 4 步：逐行输出学生 ---
    vector<int> colSum(C, 0), colCnt(C, 0);

    for (int i = 0; i < N; i++) {
        // 姓名列
        cout << left << setw(colW[0] + GAP) << vStudent[i].getName();

        int mySum = 0, myCnt = 0;
        for (int k = 0; k < C; k++) {
            int sc = vStudent[i].getMarkByCourseName(courses[k]);
            if (sc != -1) {
                cout << left << setw(colW[k + 1] + GAP) << sc;
                mySum += sc;
                myCnt++;
                colSum[k] += sc;
                colCnt[k]++;
            } else {
                cout << left << setw(colW[k + 1] + GAP) << '-';
            }
        }

        int myAvg = (myCnt > 0) ? (int)((double)mySum / myCnt + 0.5) : 0;
        cout << myAvg << endl;
    }

    // --- 第 5 步：最后一行（每门课平均分），第一列为空 ---
    cout << left << setw(colW[0] + GAP) << "";   // 空白的姓名列
    for (int k = 0; k < C; k++) {
        if (colCnt[k] > 0)
            cout << left << setw(colW[k + 1] + GAP)
                 << (int)((double)colSum[k] / colCnt[k] + 0.5);
        else
            cout << left << setw(colW[k + 1] + GAP) << '-';
    }
    cout << endl;
}