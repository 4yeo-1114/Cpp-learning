/* C++ | stl: next permutation. */
#include <iostream>
#include <vector>
#include <algorithm>
//生成排列
// 函数功能：将当前排列就地修改为下一个字典序排列
// 返回值：如果存在下一个排列返回 true，如果当前已经是最后一个排列（全降序）则返回 false
bool next_permutation_custom(std::vector<int>& a) {
    int n = a.size();
    if (n <= 1) return false;

    int j = n - 2;
    // 步骤 1：从右向左寻找第一个满足 a[j] < a[j+1] 的转折点 j
    while (j >= 0 && a[j] >= a[j+1]) {
        j--;
    }

    // 如果 j < 0，说明整个序列完全降序，已经是最大的排列了
    if (j < 0) {
        return false; 
    }

    // 步骤 2：在 j 后面的降序序列中，从右向左找到大于 a[j] 的最小元素 a[k]
    int k = n - 1;
    while (a[j] >= a[k]) {
        k--;
    }

    // 步骤 3：交换 a[j] 和 a[k]
    std::swap(a[j], a[k]);

    // 步骤 4：将位置 j 之后的后缀部分进行翻转（从降序变回升序，保证字典序最小）
    int left = j + 1;
    int right = n - 1;
    while (left < right) {
        std::swap(a[left], a[right]);
        left++;
        right--;
    }

    return true;
}

void test_permutation() {
    std::vector<int> perm = {3, 6, 2, 5, 4, 1};
    std::cout << "当前排列: ";
    for (int num : perm) std::cout << num;
    
    if (next_permutation_custom(perm)) {
        std::cout << "\n下一个排列: ";
        for (int num : perm) std::cout << num; // 输出应为 364125
        std::cout << std::endl;
    }
}

//使用标准库函数
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3};
    // 注意：如果要遍历所有排列，必须先确保初始序列是升序的！
    std::sort(v.begin(), v.end()); 
    
    do {
        for(int num : v) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    } while (std::next_permutation(v.begin(), v.end())); // 返回 false 时循环结束

    return 0;
}

//生成组合
#include <iostream>
#include <vector>

// 函数功能：给定总体大小 n 和当前的 r-组合，就地修改为下一个组合
// 返回值：如果存在下一个组合返回 true，如果是最后一个组合返回 false
bool next_combination_custom(std::vector<int>& a, int n, int r) {
    if (r <= 0 || a.empty()) return false;

    int i = r - 1; // 从数组最右端（即组合的最后一个元素）开始检查
    
    // 步骤 1：从右向左寻找第一个没有达到其理论“上限”的元素 a[i]
    // 在 0-based 索引下，第 i 个位置的数字最大上限是 (n - r + i + 1)
    while (i >= 0 && a[i] == n - r + i + 1) {
        i--;
    }

    // 如果 i < 0，说明所有元素都已经达到了各自的上限，当前是最后一个组合
    if (i < 0) {
        return false;
    }

    // 步骤 2：将找到的未达上限的元素加 1
    a[i]++;

    // 步骤 3：将其后面位置的元素全部重置为紧挨着的递增序列
    for (int j = i + 1; j < r; j++) {
        a[j] = a[j - 1] + 1;
    }

    return true;
}

void test_combination() {
    int n = 5;
    int r = 3;
    // 初始组合：从 {1, 2, 3, 4, 5} 中选 3 个，前三个元素
    std::vector<int> comb = {1, 2, 3}; 

    std::cout << "生成所有从 " << n << " 选 " << r << " 的组合:" << std::endl;
    do {
        for (int num : comb) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    // 不断调用函数生成下一个组合，直到用尽所有情况
    } while (next_combination_custom(comb, n, r)); 

