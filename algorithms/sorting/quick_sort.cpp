/* C++ | sorting: quick sort. */
/*
 * 快速排序（C++ 风格实现）
 *
 * ===== 复杂度 =====
 * 时间：平均 O(n log n) | 最坏 O(n²) → 随机化 pivot 后稳定 O(n log n)
 * 空间：O(log n) —— 递归栈深度
 *
 * ===== 核心思想 =====
 * 1. 选一个 pivot（基准值），把数组分成两半：
 *    - 左边所有元素 ≤ pivot
 *    - 右边所有元素 > pivot
 * 2. 递归地对左右两半做同样的事
 * 3. 递归到子数组长度 ≤ 1 时自然有序，什么也不做
 *
 * ===== 随机化 pivot 为什么重要 =====
 * 如果每次都固定选最后一个元素，遇到已排序数组 [1,2,3,4,5]：
 *   partition 每次只切掉 1 个元素 → O(n²)，递归栈也爆到 O(n)
 * 随机选 pivot 则使每次划分期望均分 → O(n log n)
 */

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

// ─── 分区函数：把数组按 pivot 分成"小-大"两半 ───
// 返回值：pivot 最终位置的下标
//
// 过程图解（假设 pivot = arr[right] 为了简洁，实战用随机化）：
//   [ 5, 2, 8, 1, 9, (4) ]   ← pivot = 4（最右）
//   [ 2, 1, (4), 8, 9, 5 ]   ← partition 后，4 左边都 ≤ 它，右边都 > 它
//               ↑
//             返回 2

int partition(vector<int>& arr, int left, int right) {
    // ① 随机化 pivot：随机选一个位置，跟最右元素交换
    //    这样等价于"随机取 pivot 放到最右"，避免有序数组退化为 O(n²)
    int randomIdx = left + rand() % (right - left + 1);
    swap(arr[randomIdx], arr[right]);

    int pivot = arr[right];          // pivot 值（已在最右）
    int i = left - 1;                // i 指向 ≤pivot 区域的最后一个位置

    // ② 遍历：j 从 left 扫到 right-1
    //    遇到 ≤ pivot 的元素就扩大小于区域（i++，交换 arr[i] 和 arr[j]）
    //类似冒泡排序
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    // ③ 把 pivot 放到正确位置（i+1 就是它该去的地方）
    swap(arr[i + 1], arr[right]);
    return i + 1;                    // 返回 pivot 最终下标
}

// ─── 快速排序递归主体 ───
void quickSort(vector<int>& arr, int left, int right) {
    // 递归出口：子数组长度 ≤ 1，已经有序
    if (left >= right) return;

    // 一步 partition：arr[pivotIdx] 已经到达最终正确位置
    int pivotIdx = partition(arr, left, right);

    // 递归处理左右两半（pivotIdx 已经在正确位置，不用再动）
    quickSort(arr, left, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, right);
}

// ─── 包装函数：对外只暴露这一个接口 ───
void quickSort(vector<int>& arr) {
    if (arr.empty()) return;               // 空数组直接返回
    quickSort(arr, 0, arr.size() - 1);
}

// ─── 工具函数：打印数组 ───
void printArray(const vector<int>& arr, const string& label = "") {
    if (!label.empty()) cout << label << ": ";
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// ─── 测试框架 ───
// 返回 true=通过, false=失败
bool test(const string& name, vector<int> input, vector<int> expected) {
    cout << "--- " << name << " ---" << endl;
    printArray(input, "  排序前");

    quickSort(input);

    printArray(input, "  排序后");
    printArray(expected, "  期望值");

    bool pass = (input == expected);
    cout << "  结果: " << (pass ? "✓ 通过" : "✗ 失败") << endl << endl;
    return pass;
}

// ─── 主函数 ───
int main() {
    // 初始化随机数种子（rand() 用于 partition 的随机化 pivot）
    srand(static_cast<unsigned>(time(nullptr)));

    int passed = 0, total = 0;

    // 测试用例设计原则：
    //   涵盖：空数组、单元素、有序、逆序、重复元素、随机、偶数/奇数长度

    passed += test("空数组", {}, {});                          total++;
    passed += test("单元素", {42}, {42});                      total++;
    passed += test("两个元素已序", {1, 2}, {1, 2});            total++;
    passed += test("两个元素逆序", {2, 1}, {1, 2});            total++;
    passed += test("已有序", {1, 2, 3, 4, 5, 6, 7},
                            {1, 2, 3, 4, 5, 6, 7});            total++;
    passed += test("完全逆序", {7, 6, 5, 4, 3, 2, 1},
                              {1, 2, 3, 4, 5, 6, 7});          total++;
    passed += test("含重复元素", {3, 1, 4, 1, 5, 9, 2, 6, 5},
                                {1, 1, 2, 3, 4, 5, 5, 6, 9});  total++;
    passed += test("全相同元素", {5, 5, 5, 5, 5},
                                {5, 5, 5, 5, 5});              total++;
    passed += test("含负数", {-3, 0, -8, 5, -1, 2},
                            {-8, -3, -1, 0, 2, 5});            total++;
    passed += test("奇数长度随机", {9, 3, 7, 1, 5},
                                 {1, 3, 5, 7, 9});              total++;
    passed += test("偶数长度随机", {64, 25, 12, 22, 11, 36},
                                 {11, 12, 22, 25, 36, 64});     total++;
    passed += test("大数测试", {1000000, 500000, 0, 999999, 1},
                               {0, 1, 500000, 999999, 1000000}); total++;

    cout << "═══════════════════════" << endl;
    cout << "通过: " << passed << " / " << total << endl;

    return (passed == total) ? 0 : 1;
}
