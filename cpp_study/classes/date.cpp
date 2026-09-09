/* C++ | classes: date. */
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year, month, day;

    // 判断是否为闰年
    bool isLeap() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    // 获取指定月份的天数（考虑闰年）
    int getDaysInMonth(int m) const {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            return 31;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        } else if (m == 2) {
            return isLeap() ? 29 : 28;
        }
        return 0; // 题目保证输入合法，无需处理无效月份
    }
public:
    // 构造函数：初始化年月日
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    // 重载+运算符：计算当前日期 + n 天后的日期
    Date operator+(int n) const{
        Date res = *this;
        res.day += n;
        while(true){
            int max_day = res.getDaysInMonth(res.month);
            if(res.day<=max_day) break;
            res.day - max_day;
            res.month++;
            if(res.month>12){
                res.year++;
                res.month  =1;
            }
        }
        return res;
    }
    // 重载-运算符：计算当前日期 - n 天前的日期
    Date operator-(int n) const{
        Date res = *this;
        //先减
        res.day -= n;
        //循环处理月份 年份
        while(true){
            if(res.day>0)break;
            //与加不同先减月再算日期 因为减完后的日期已经和减之前的月没关系了
            res.month--;
            if(res.month==0){
                res.month = 12;
                res.year--;
            }
            res.day += res.getDaysInMonth(res.month);
        }
        return res;
    }
    // 重载 > 运算符：判断当前日期是否晚于 other 日期
    bool operator>(const Date& other) const {
        // 1. 先拼年份
        if (year != other.year) {
            return year > other.year; // 年份大就返回 true，否则 false
        }
        // 2. 年份打平了，拼月份
        if (month != other.month) {
            return month > other.month; // 月份大就返回 true，否则 false
        }
        // 3. 年月都打平了，拼日子
        return day > other.day; 
    }

    // 将日期转为 "年-月-日" 格式字符串
    string toText() const {
        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }
};

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    Date d1(y, m, d);

    int n;
    cin >> n;

    cout << d1.toText() << " + " << n << " = " << (d1 + n).toText() << endl;
    cout << d1.toText() << " - " << n << " = " << (d1 - n).toText() << endl;
    return 0;
}

//升级版
class MyDate {
private:
    int month;
    int day;
    int year;

    // 辅助函数：判断是否为闰年
    bool isLeapYear(int y) const {
        return (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0));
    }

    // 辅助函数：获取某年某月的天数
    int getDaysInMonth(int m, int y) const {
        if (m == 2) {
            return isLeapYear(y) ? 29 : 28;
        }
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[m];
    }

    // 辅助函数：检查日期是否合法
    bool isValidDate(int m, int d, int y) const {
        if (y < 1 || m < 1 || m > 12) return false;
        if (d < 1 || d > getDaysInMonth(m, y)) return false;
        return true;
    }

    // 辅助函数：将日期往后推1天
    void nextDay() {
        if (day + 1 > getDaysInMonth(month, year)) {
            day = 1; // 天数重置为1
            if (month == 12) {
                month = 1; // 月份重置为1
                year++;    // 年份加1
            } else {
                month++;   // 月份加1
            }
        } else {
            day++; // 还在当月内，天数直接加1
        }
    }


public:
    // 默认构造函数
    MyDate() : month(1), day(1), year(1900) {}

    // 设置日期
    void setDate(int m, int d, int y) {
        if (isValidDate(m, d, y)) {
            month = m;
            day = d;
            year = y;
        } else {
            // 不符合实际则设置为默认日期
            month = 1;
            day = 1;
            year = 1900;
        }
    }

    // 重载 += 运算符（加上若干天）
    MyDate& operator+=(int daysToAdd) {
        for (int i = 0; i < daysToAdd; ++i) {
            nextDay(); // 循环调用单日增加逻辑，自动处理进位
        }
        return *this;
    }
    // 重载前置 ++ 运算符 (++d)
    MyDate& operator++() {
        nextDay();
        return *this;
    }

    // 重载后置 ++ 运算符 (d++)
    // 注意：后置加加需要一个 int 哑元参数来与前置区分
    MyDate operator++(int) {
        MyDate temp = *this; // 先保存当前状态
        nextDay();           // 对象本身增加
        return temp;         // 返回增加前的旧状态
    }
    // 重载流插入运算符 << 
    friend ostream& operator<<(ostream& os, const MyDate& date) {
        // 月份名称映射表
        static const string monthNames[] = {
            "", "January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December"
        };
        // 按照英文习惯输出，例如：January 1, 1900
        os << monthNames[date.month] << " " << date.day << ", " << date.year;
        return os;
    }
    
};
