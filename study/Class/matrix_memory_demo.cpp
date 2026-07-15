/*
 * 二维数组内存布局可视化 —— 验证静态 int[3][4] vs 动态 int**
 *
 * 运行后你可以清楚看到：
 * 1. 静态数组地址连续（每行递增 4×4=16 字节）
 * 2. 动态数组行间地址不连续（每次 new 分配可能相距很远）
 * 3. data[i][j] 的地址公式是否正确
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // ═══════════════════════════════════════════
    // 第一部分：静态二维数组 int data[3][4]
    // ═══════════════════════════════════════════
    cout << "===== 静态数组 int data[3][4] =====" << endl;
    int data[3][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 44}
    };

    // 打印每个元素的地址
    cout << "地址分布：" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "data[" << i << "][" << j << "] = " << setw(3) << data[i][j]
                 << "  地址: " << &data[i][j] << endl;
        }
    }

    // 验证"行内相邻元素差 4 字节，行间首元素差 16 字节"
    cout << endl << "地址差验证：" << endl;
    cout << "&data[0][4] - &data[0][0] = "
         << reinterpret_cast<intptr_t>(&data[0][4])
          - reinterpret_cast<intptr_t>(&data[0][0])  // C++ 中正确的指针差值方法
         << " (期望 4×4=16，即一行4个int的跨度)" << endl;

    cout << "&data[1][0] - &data[0][0] = "
         << &data[1][0] - &data[0][0]
         << " (期望 4，因为差值以 int 为单位)" << endl;

    cout << "&data[1][0] - &data[0][0] (字节差) = "
         << reinterpret_cast<intptr_t>(&data[1][0])
          - reinterpret_cast<intptr_t>(&data[0][0])
         << " (期望 16，即 sizeof(int)×4)" << endl;

    // 关键验证：data[1][2] 的手动地址计算
    int* base = &data[0][0];
    int cols = 4;
    int i = 1, j = 2;
    int* manual_addr = base + (i * cols + j);  // base + 1×4 + 2 = base + 6
    cout << endl << "地址公式验证 data[1][2]：" << endl;
    cout << "  实际地址:  " << &data[1][2] << endl;
    cout << "  公式计算:  base + " << i << "*" << cols << " + " << j
         << " = base + " << (i * cols + j) << " = " << manual_addr << endl;
    cout << "  data[1][2] = " << data[1][2]
         << "  vs  *manual_addr = " << *manual_addr << endl;

    // ═══════════════════════════════════════════
    // 第二部分：动态二维数组 int** dynamicData
    // ═══════════════════════════════════════════
    cout << endl << "===== 动态数组 int** dynamicData[3][4] =====" << endl;

    int** dynamicData = new int*[3];
    for (int i = 0; i < 3; i++) {
        dynamicData[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            dynamicData[i][j] = (i + 1) * 10 + (j + 1);  // 11, 12, ...
        }
    }

    cout << "地址分布：" << endl;
    cout << "  行指针数组地址: " << dynamicData << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  dynamicData[" << i << "] (行" << i << "的指针) = "
             << dynamicData[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << "    dynamicData[" << i << "][" << j << "] = "
                 << setw(3) << dynamicData[i][j]
                 << "  地址: " << &dynamicData[i][j] << endl;
        }
    }

    // 验证行间是否连续
    cout << endl << "行间连续性检查：" << endl;
    intptr_t row0_end = reinterpret_cast<intptr_t>(&dynamicData[0][3]) + sizeof(int);
    intptr_t row1_start = reinterpret_cast<intptr_t>(&dynamicData[1][0]);
    cout << "  第0行末尾 + 4 = " << row0_end << endl;
    cout << "  第1行起始 =       " << row1_start << endl;
    cout << "  是否相邻？ " << (row0_end == row1_start ? "✓ 相邻" : "✗ 不相邻（差值 = "
                                 + to_string(abs(row1_start - row0_end)) + " 字节）") << endl;

    // ═══════════════════════════════════════════
    // 第三部分：类型信息（用编译器错误来"读取"类型 —— 已注释掉，这里用推论）
    // ═══════════════════════════════════════════
    cout << endl << "===== 类型对比 =====" << endl;
    cout << "int data[3][4] 中 data 的类型:   int (*)[4]  (指向 int[4] 的指针)" << endl;
    cout << "int** dynamicData 的类型:        int**        (指向 int* 的指针)" << endl;
    cout << "&data[0][0] 的类型:              int*         (指向 int 的指针)" << endl;
    cout << "data[0] 的类型:                  int*         (退化为指向首元素的指针)" << endl;

    // ═══════════════════════════════════════════
    // 清理动态内存
    // ═══════════════════════════════════════════
    for (int i = 0; i < 3; i++) {
        delete[] dynamicData[i];
    }
    delete[] dynamicData;

    return 0;
}
