#include <iostream>
#include <vector>
#include <algorithm>
#include <math>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // 第一步：从右到左找到第一个小于 nums[i+1] 的数 nums[i]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 如果找到了，进入第二步；否则跳过第二步，反转整个数组
        if (i >= 0) {
            // 第二步：从右到左找到 nums[i] 右边最小的大于 nums[i] 的数 nums[j]
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // 交换 nums[i] 和 nums[j]s
            swap(nums[i], nums[j]);
        }

        // 第三步：反转 [i+1, n-1]（如果上面跳过第二步，此时 i = -1）
        reverse(nums.begin() + i + 1, nums.end());
    }
};
