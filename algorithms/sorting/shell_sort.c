/* C | sorting: shell sort. */
#include <stdio.h>

/*
 * 希尔排序 (Shell Sort) — 分组插入排序
 * ======================================
 * 核心思路：插入排序在"基本有序"的序列上非常快（接近 O(n)），
 * 但乱序时很慢（O(n²)）。希尔排序先用大步长把远距离元素
 * "粗略排好"，再逐步缩小步长精细调整，最后步长=1 时做一次
 * 标准插入排序——此时序列已经接近有序，效率很高。
 *
 * 时间复杂度：O(n^(3/2)) ~ O(n²)，取决于步长序列
 * 空间复杂度：O(1)（原地排序）
 * 此处使用的步长序列：5 → 3 → 1（教学常用，非最优）
 */

// array: 待排数组   length: 数组长度   step: 当前步长(间隔/gap)
void shellSort(int array[], int length, int step) {
    // 外层 i：枚举每一"组"的起始位置
    // 步长为 step 时，序列被分成 step 个组（下标 0 ~ step-1 各领一组）
    // i >= step 时内层 j 初始值已越界，循环体不会执行，因此无冗余副作用
    for (int i = 0; i < length; i++) {
        // 中层 j：遍历当前组内元素（从该组第2个元素开始，类似插入排序的"待插入牌"）
        for (int j = i + step; j < length; j += step) {
            // 内层 k：在当前组已排好的前缀中，找到 array[j] 的正确插入位置
            for (int k = i; k < j; k += step) {
                if (array[j] < array[k]) {
                    // 找到了插入点 k，暂存待插入值
                    int temp = array[j];
                    // 将 [k, j-step] 区间的元素整体后移一步，为 temp 腾位置
                    for (int l = j - step; l >= k; l -= step) {
                        array[l + step] = array[l];
                    }
                    // 将 temp 放入正确位置
                    array[k] = temp;
                    // 已插入完成，无需继续向后比较（同组前缀已有序）
                }
            }
        }
    }
}

int main() {
    int array[10] = {49, 38, 65, 97, 50, 2, 9, 31, 6, 84};

    // 步长序列：逐步缩小间隔，最后一次步长=1 等价于标准插入排序
    int step[3] = {5, 3, 1};
    for (int i = 0; i < 3; i++) {
        shellSort(array, 10, step[i]);
    }
    return 0;
}
