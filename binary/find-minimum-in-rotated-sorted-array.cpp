#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
//递增数组在旋转后分为两段递增数组 最右边的数要么是最小值 要么是第二段递增数组中最大的 同时又小于第一段
//所以可以将数字与nums[n-1]比较来确定该数字在那一段
//但是我们是要找最小值 没必要每个都比 所以用红蓝染色即二分来做
//最后right即为蓝色红色交界 即最小值（用开区间写）
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = -1;
        int right = n-1;
        while(left+1<right){
            int mid = left + (right-left)/2;
            //因为mid在等于n-1时这个if不一定成立 所以可以直接把n-1染成蓝色的
            if(nums[mid]<nums[n-1]){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return nums[right];
    }
};