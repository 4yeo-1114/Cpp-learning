#include <vector>         
#include <unordered_map>  
#include <unordered_set>
#include <algorithm>    
#include <string>
#include <stack>
using namespace std; 

//要返回第k大的数字 在排序完的数组中下标就是n-k
//为了实现时间复杂度为O(n)使用快排
class Solution {
public:
    // 在子数组 [left, right] 中随机选择一个基准元素 pivot
    // 根据 pivot 重新排列子数组 [left, right]
    // 重新排列后，<= pivot 的元素都在 pivot 的左侧，>= pivot 的元素都在 pivot 的右侧
    // 返回 pivot 在重新排列后的 nums 中的下标
    // 特别地，如果子数组的所有元素都等于 pivot，我们会返回子数组的中心下标，避免退化
    int partition(vector<int>&nums,int left,int right){
        // 1 在子数组中随机选择一个基准元素pivot
        int i = left + rand()% (right-left+1);
        int privot = nums[i];
        //把pivot和子数组第一个元素交换 避免pivot干扰后续划分 从而简化实现逻辑
        swap(nums[i],nums[left]);
        // 2. 相向双指针遍历子数组 [left + 1, right]
        // 循环不变量：在循环过程中，子数组的数据分布始终如下图
        // [ pivot | <=pivot | 尚未遍历 | >=pivot ]
        //   ^                 ^     ^         ^
        //   left              i     j         right

        i = left + 1;
        int j  =right;
        while(true){
            while(i<=j&& nums[i]<privot){
                i++; // i指向的元素确实是小的 没问题 i继续走
            }
            //此时nums[i]>=privot
            while(i<=j&&nums[j]>privot){
                j--; //同上
            }
            //此时nums[j]<=privot
            if(i>=j){
                break;
            }
            swap(nums[i],nums[j]); // 交换保证分界正确
            i++;
            j--;
        }
        // 循环结束后
        // [ pivot | <=pivot | >=pivot ]
        //   ^             ^   ^     ^
        //   left          j   i     right

        // 3. 把 pivot 与 nums[j] 交换，完成划分（partition）

        swap(nums[j],nums[left]);

        //返回privot的下标
        return j;
    }



    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        int n = nums.size();
        int target_index = n - k; // 第 k 大元素在升序数组中的下标是 n - k
        int left = 0, right = n - 1; // 闭区间

        while(true){
            int i = partition(nums,left,right);
            if(i==target_index){
                return nums[i];
            }
            if(i>target_index){
                right = i-1;
            }
            else{
                left = i+1;
            }
        }
    }
};