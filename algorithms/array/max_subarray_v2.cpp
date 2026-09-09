/* C++ | array: max subarray v2. */
#include <vector>
#include <algorithm> // 使用 std::max 需要包含此头文件

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        return maxSubArrayHelper(nums, 0, size - 1);
    }

private:
    // 在 C++ 中，为了防止数组被拷贝导致超时，我们使用 const vector<int>& 来传递引用
    int maxSubArrayHelper(const vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        // C++ 中防止 (left + right) 溢出的标准写法，等同于 Python 的 (left + right) >> 1
        int mid = left + (right - left) / 2; 
        
        int max_left = maxSubArrayHelper(nums, left, mid);
        int max_right = maxSubArrayHelper(nums, mid + 1, right);
        int max_cross = maxCrossArray(nums, left, mid, right);
        
        // C++ 的 std::max 默认只能比较两个数。
        // 要比较三个数，可以使用花括号 {} 括起来的初始化列表（C++11 特性）
        return max({max_left, max_right, max_cross});
    }

    int maxCrossArray(const vector<int>& nums, int left, int mid, int right) {
        // 一定包含 nums[mid] 元素的最大连续子数组的和
        int left_sum_max = 0;
        int start_left = mid - 1;
        int s1 = 0;
        
        while (start_left >= left) {
            s1 += nums[start_left];
            left_sum_max = max(left_sum_max, s1);
            start_left -= 1;
        }

        int right_sum_max = 0;
        int start_right = mid + 1;
        int s2 = 0;
        
        while (start_right <= right) {
            s2 += nums[start_right];
            right_sum_max = max(right_sum_max, s2);
            start_right += 1;
        }
        
        return left_sum_max + nums[mid] + right_sum_max;
    }
}