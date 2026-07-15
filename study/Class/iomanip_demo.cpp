#include <iostream>
#include <iomanip>   // setw, setfill, setprecision, left, right, hex, put_time, get_time 等
#include <cmath>     // sqrt
#include <sstream>   // put_time / get_time 的 stringstream 演示
#include <ctime>     // tm, time_t, localtime
using namespace std;

// ============================================================
// <iomanip> 格式化输入/输出 全讲解
// ============================================================
// 核心分类：
//   1. 宽度控制：setw
//   2. 填充控制：setfill
//   3. 对齐控制：left, right, internal
//   4. 浮点数控制：fixed, scientific, defaultfloat, setprecision
//   5. 整数进制：hex, oct, dec, showbase, noshowbase, setbase
//   6. 布尔/正号/大小写：boolalpha, showpos, uppercase
//   7. 小数点显示：showpoint
//   8. 时间/金额格式化：put_time, get_time, put_money, get_money
// ============================================================

int main(){
    // ════════════════════════════════════════════════════════
    // 一、setw(n) —— 设置输出宽度（只对"下一个"输出有效！）
    // ════════════════════════════════════════════════════════
    cout << "=== 一、setw 宽度控制 ===\n";
    cout << setw(10) << 123 << setw(10) << 456 << endl;
    //宽度控制
    // 输出: "       123       456"
    // 注意：setw 只作用于紧跟着的那一个输出，用完即失效。
    //      数字默认右对齐，不足宽度用空格填充。

    cout << "1234567890" << endl; // 参考线：10个字符
    cout << setw(10) << "abc" << endl;  // 右对齐，左补7空格
    // 输出: "       abc"

    // ════════════════════════════════════════════════════════
    // 二、setfill(c) —— 设置填充字符（持久生效）
    // ════════════════════════════════════════════════════════
    cout << "\n=== 二、setfill 填充字符 ===\n";
    cout << setfill('*') << setw(8) << 42 << endl;   // "******42"
    cout << setfill('0') << setw(5) << 7  << endl;   // "00007"  (注意是持续生效的)
    cout << setfill(' ') << setw(5) << 7  << endl;   // "    7"  (恢复空格)

    // ════════════════════════════════════════════════════════
    // 三、left / right / internal —— 对齐方式（持久生效）
    // ════════════════════════════════════════════════════════
    cout << "\n=== 三、对齐方式 ===\n";
    // left:   左对齐，右边填空
    // right:  右对齐，左边填空（默认）
    // internal: 符号(+/−)左对齐，数值右对齐，中间填空

    cout << setfill('.');
    cout << left  << setw(8) << 123 << "<-left\n";    // "123....."
    cout << right << setw(8) << 123 << "<-right\n";   // ".....123"
    cout << internal << setw(8) << -123 << "<-internal\n"; // "-....123"
    cout << internal << setw(8) << showpos << 123 << "<-internal(+)\n"; // "+....123"
    cout << setfill(' ') << noshowpos; // 还原

    // ════════════════════════════════════════════════════════
    // 四、浮点数输出格式（持久生效）
    // ════════════════════════════════════════════════════════
    cout << "\n=== 四、浮点数格式 ===\n";
    double pi = 3.1415926535;

    // 1. defaultfloat —— 默认格式：不显示无意义的尾随零
    cout << "defaultfloat:  " << defaultfloat << pi << endl;  // "3.14159"

    // 2. fixed —— 定点小数：始终显示小数点+n位小数
    cout << "fixed:         " << fixed        << pi << endl;  // "3.141593"

    // 3. scientific —— 科学计数法
    cout << "scientific:    " << scientific   << pi << endl;  // "3.141593e+00"

    // 4. setprecision(n) —— 控制有效位数或小数位数（持久生效）
    //    - 在 defaultfloat 下：控制"有效数字位数"
    //    - 在 fixed/scientific 下：控制"小数点后位数"
    double val = 12.3456789;
    cout << "\nsetprecision 在不同模式下的区别：\n";
    cout << "--- 在 fixed 模式下：setprecision 控制小数位数 ---\n";
    cout << fixed;
    cout << "precision(3): " << setprecision(3) << val << endl; // "12.346"  (3位小数)
    cout << "precision(5): " << setprecision(5) << val << endl; // "12.34568" (5位小数, 四舍五入)
    cout << "precision(0): " << setprecision(0) << val << endl; // "12"      (0位小数)

    cout << "\n--- 在 defaultfloat 模式下：setprecision 控制有效数字 ---\n";
    cout << defaultfloat;
    cout << "precision(3): " << setprecision(3) << val << endl; // "12.3"    (3位有效)
    cout << "precision(8): " << setprecision(8) << val << endl; // "12.345679"(8位有效)

    // showpoint —— 强制显示小数点（哪怕小数部分全为零）
    cout << "\nshowpoint:     " << showpoint   << setprecision(3) << 42.0 << endl; // "42.0"
    cout << "noshowpoint:   " << noshowpoint   << setprecision(3) << 42.0 << endl; // "42"

    // ════════════════════════════════════════════════════════
    // 五、整数进制控制（持久生效）
    // ════════════════════════════════════════════════════════
    cout << "\n=== 五、整数进制 ===\n";
    int n = 255;
    //dec 十进制 hex 十六进制 oct 八进制
    cout << "dec (十进制):       " << dec << n << endl;   // "255"
    cout << "hex (十六进制):     " << hex << n << endl;   // "ff"
    cout << "oct (八进制):       " << oct << n << endl;   // "377"

    // showbase —— 显示进制前缀
    //   oct → 前置 0,   hex → 前置 0x,   dec → 无前缀
    cout << "hex + showbase:     " << showbase << hex << n << endl;    // "0xff"
    // uppercase —— 进制前缀和十六进制字母大写
    cout << "hex + uppercase:    " << uppercase << hex << n << endl;   // "0XFF"

    // setbase(n) —— 等同于 hex/oct/dec，但参数为 8/10/16
    cout << "setbase(16):        " << setbase(16) << n << endl; // "0XFF"
    cout << "setbase(8):         " << setbase(8)  << n << endl; // "0377"
    cout << "setbase(10):        " << setbase(10) << n << endl; // "255"
    // ⚠️ setbase(0) 或 setbase(其他值) 行为未定义，不要用

    cout << nouppercase << noshowbase << dec; // 恢复

    // ════════════════════════════════════════════════════════
    // 六、布尔值 / 正号 / 空白控制（持久生效）
    // ════════════════════════════════════════════════════════
    cout << "\n=== 六、布尔值 & 正号 ===\n";

    // boolalpha —— 输出 true/false 而非 1/0
    cout << "默认bool:    " << false << " " << true << endl;          // "0 1"
    cout << "boolalpha:   " << boolalpha << false << " " << true << endl; // "false true"

    // showpos —— 正数显示 + 号 showpos显示 + 号
    cout << "showpos:     " << showpos   << 42 << " " << -42 << endl;  // "+42 -42"
    cout << "noshowpos:   " << noshowpos << 42 << " " << -42 << endl;  // "42 -42"

    // ════════════════════════════════════════════════════════
    // 七、输入格式化
    // ════════════════════════════════════════════════════════
    cout << "\n=== 七、输入格式化 ===\n";

    // hex/oct/dec 同样影响 cin
    // 读取十六进制输入：
    cout << "请输入十六进制数(如 ff): ";

    // ⚠️ 下面代码被注释掉，因为这是演示环境，无法交互输入
    /*
    int x;
    cin >> hex >> x;   // 用户输入 "ff" → x = 255
    cout << "十进制: " << dec << x << endl;
    */

    // setw 在 cin 中：限制读取的最大字符数（防止缓冲区溢出）
    /*
    char buf[10];
    cin >> setw(10) >> buf;  // 最多读9个字符，最后一个留给 '\0'
    */

    // ════════════════════════════════════════════════════════
    // 八、时间格式化 —— put_time (C++11)
    // ════════════════════════════════════════════════════════
    cout << "\n=== 八、时间格式化 put_time ===\n";
    time_t now = time(nullptr);
    tm* local = localtime(&now);

    cout << "当前时间相关格式化示例：\n";
    cout << "YYYY-MM-DD:        " << put_time(local, "%Y-%m-%d") << endl;
    cout << "HH:MM:SS:          " << put_time(local, "%H:%M:%S") << endl;
    cout << "完整格式:          " << put_time(local, "%Y-%m-%d %H:%M:%S") << endl;
    cout << "中文风格:          " << put_time(local, "%Y年%m月%d日 %A") << endl;
    cout << "12小时制:          " << put_time(local, "%I:%M:%S %p") << endl;

    // 常用格式符：
    //   %Y = 四位年份        %y = 两位年份
    //   %m = 两位月份        %d = 两位日期
    //   %H = 24小时制        %I = 12小时制
    //   %M = 分钟            %S = 秒
    //   %A = 完整星期名      %a = 缩写星期名
    //   %p = AM/PM

    // ════════════════════════════════════════════════════════
    // 九、时间输入 —— get_time (C++11)
    // ════════════════════════════════════════════════════════
    cout << "\n=== 九、时间输入 get_time ===\n";
    // 语法：cin >> get_time(&tm, "格式")   从输入流按格式解析时间
    {
        // 演示：从字符串流中解析时间
        stringstream ss("2025-03-15 14:30:00");
        tm parsed_time = {};
        ss >> get_time(&parsed_time, "%Y-%m-%d %H:%M:%S");
        if (!ss.fail()) {
            cout << "从 \"2025-03-15 14:30:00\" 解析成功：\n";
            cout << "  年=" << parsed_time.tm_year + 1900
                 << " 月=" << parsed_time.tm_mon + 1
                 << " 日=" << parsed_time.tm_mday
                 << " 时=" << parsed_time.tm_hour
                 << " 分=" << parsed_time.tm_min
                 << " 秒=" << parsed_time.tm_sec << endl;
        }
    }

    // ════════════════════════════════════════════════════════
    // 十、金额格式化 —— put_money / get_money (C++11)
    // ════════════════════════════════════════════════════════
    cout << "\n=== 十、金额格式化 put_money ===\n";
    // put_money(金额) 以"分"为单位（默认），按本地化设置输出
    // 注意：Windows 中文环境下可能显示 ¥，英文环境下显示 $

    long double cash = 123456;  // 单位：分 → 即 1234.56 元
    cout << "put_money(分): " << put_money(cash) << endl;

    // showbase + put_money：显示货币符号
    cout << "showbase + put_money: " << showbase << put_money(cash) << endl;
    cout << noshowbase;

    // ════════════════════════════════════════════════════════
    // 十一、对齐线表格：综合运用
    // ════════════════════════════════════════════════════════
    cout << "\n=== 综合示例：格式化表格 ===\n";
    cout << left;
    cout << setfill('-') << setw(30) << "" << endl; // 分隔线
    cout << setfill(' ');
    cout << setw(8)  << "姓名"
         << setw(8)  << "分数"
         << setw(8)  << "等级" << endl;
    cout << setfill('-') << setw(30) << "" << endl;
    cout << setfill(' ');

    // 使用数组模拟表格行
    const char* names[] = {"Alice", "Bob", "Tom"};
    double scores[] = {95.5, 72.0, 88.666};
    for (int i = 0; i < 3; ++i) {
        cout << setw(8)  << names[i]
             << fixed << setprecision(1)
             << setw(8)  << scores[i]
             << setw(8)  << (scores[i] >= 90 ? 'A' : scores[i] >= 80 ? 'B' : 'C')
             << endl;
    }
    cout << setfill('-') << setw(30) << "" << endl;
    cout << setfill(' ');

    // ════════════════════════════════════════════════════════
    // 十二、endl / ends / flush 的区别
    // ════════════════════════════════════════════════════════
    cout << "\n=== 结尾：endl vs ends vs flush ===\n";
    // endl   = '\n' + flush（换行 + 刷新缓冲区）
    // ends   = '\0' + flush（空字符 + 刷新缓冲区，极少使用）
    // flush  = 仅刷新缓冲区，不插入字符
    cout << "这一行用 endl" << endl;
    cout << "flush 强制刷新，但不换行..." << flush;
    cout << "——接到同一行了\n";

    return 0;
}
