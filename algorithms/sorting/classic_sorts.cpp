/* C++ | sorting: classic sorts. */
/*
 * ============================================================
 *  经典排序算法模板 —— 考试常用 6 种
 * ============================================================
 *
 *  | 算法        | 平均时间   | 最坏时间   | 空间    | 稳定性 |
 *  |------------|-----------|-----------|--------|-------|
 *  | 冒泡排序    | O(n²)     | O(n²)     | O(1)   | 稳定   |
 *  | 选择排序    | O(n²)     | O(n²)     | O(1)   | 不稳定 |
 *  | 插入排序    | O(n²)     | O(n²)     | O(1)   | 稳定   |
 *  | 快速排序    | O(n log n)| O(n²)     | O(log n)| 不稳定 |
 *  | 归并排序    | O(n log n)| O(n log n)| O(n)   | 稳定   |
 *  | 堆排序      | O(n log n)| O(n log n)| O(1)   | 不稳定 |
 *
 * 记忆技巧：
 *   - "快归堆" 是 O(n log n) 三剑客
 *   - "冒选插" 是 O(n²) 三兄弟
 *   - 只有"归并"需要额外 O(n) 空间
 *   - "选快堆" 不稳定，其余稳定
 */

#include <iostream>
#include <algorithm>  // swap
#include <vector>
using namespace std;

// ==================== 1. 冒泡排序 ====================
// 思路：每轮把最大的"冒"到最后
// 优化：若某轮没有交换，说明已经有序，提前结束
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {   // 每轮后边界前移
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;   // 已有序，提前退出
    }
}

// ==================== 2. 选择排序 ====================
// 思路：每轮选最小的放到前面
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// ==================== 3. 插入排序 ====================
// 思路：像整理扑克牌，把当前牌插入到前面已排序的合适位置
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];   // 后移
            --j;
        }
        arr[j + 1] = key;          // 插入
    }
}

// ==================== 4. 快速排序 ====================
// 思路：选 pivot，小的放左边，大的放右边，递归
// 这是 Lomuto 分区方案（用最后一个元素做 pivot）
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];      // 选最后一个为基准
    int i = low;                // i 指向"小于区的尾部"
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot)
            swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[high]);    // 把 pivot 放到正确位置
    return i;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

// 方便调用的包装
void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// ==================== 5. 归并排序 ====================
// 思路：分两半，分别排序，再合并
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while (i <= mid)  temp[k++] = arr[i++];   // 左边剩余
    while (j <= right) temp[k++] = arr[j++];  // 右边剩余

    for (int t = 0; t < k; ++t)
        arr[left + t] = temp[t];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;   // 防溢出写法
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// 方便调用的包装
void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

// ==================== 6. 堆排序 ====================
// 思路：建大顶堆 → 每次取堆顶放到末尾 → 调整剩余堆
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left  = 2 * i + 1;   // i 的左孩子
    int right = 2 * i + 2;   // i 的右孩子

    if (left  < n && arr[left]  > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);   // 递归调整被破坏的子树
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 建堆：从最后一个非叶节点开始
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // 逐个取堆顶
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);       // 堆顶(最大)放到末尾
        heapify(arr, i, 0);         // 调整剩余 i 个元素
    }
}

// ==================== 测试 ====================

void print(const vector<int>& arr, const string& name) {
    cout << name << ": ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> original = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };

    auto testSort = [&](void (*sortFunc)(vector<int>&), const string& name) {
        vector<int> arr = original;   // 拷贝原始数据
        sortFunc(arr);
        print(arr, name);
    };

    cout << "原始数组: ";
    print(original, "");

    // 每个排序都从原始数组开始，方便对比
    testSort(bubbleSort,    "冒泡排序");
    testSort(selectionSort, "选择排序");
    testSort(insertionSort, "插入排序");
    testSort(quickSort,     "快速排序");
    testSort(mergeSort,     "归并排序");
    testSort(heapSort,      "堆排序  ");

    return 0;
}
