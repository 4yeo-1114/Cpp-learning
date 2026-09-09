/* C++ | sliding window: min subarray length. */
#include <vector>         
#include <unordered_set>  


#include <algorithm>    
using namespace std;  

//和大于target的子数组的最小长度
int minSubArraylen(vector<int>& nums, int target){
    int n = nums.size();
    int ans = n+1;
    int left = 0;
    int sum  = 0;
    for(int right = 0;right<n;right++){
        sum+=nums[right];
        //写法一 确保left是最极端的情况再算ans
        // while(sum-nums[left]>=target){
        //     sum -= nums[left];
        //     left++;
        // }
        // if(sum>=target){
        //     ans = min(ans,right-left+1);
        // }
        //写法二 每次都更新ans
        while(sum>=target){
            ans = min(ans,right-left+1);
            sum -= nums[left];
            left++;
        }

    }
    if (ans <=n) return ans ;
    //没找到还是n+1
    else return 0;
}

//乘积小于k的子数组的个数
int numofSubArray(vector<int>& nums, int k){
    if(k==1) return 0 ;
    int sum = 1;
    int n = nums.size();
    int left = 0;
    int ans = 0;
    for(int right = 0;right<n;right++){
        sum *= nums[right];
        //滑动窗口直到满足为止
        while(sum>=k){
            sum /= nums[left];
            left++;
        }
        ans += right-left+1;
    }
    return ans;
}