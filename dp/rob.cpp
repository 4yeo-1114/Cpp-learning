#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        //子情况为抢劫前i座房子能抢到的最大金额
        //目标为抢劫前n座房子的最大金额
        int n = nums.size();
        //如果只有 1 座房屋，直接抢了走人，防止后面越界！
        if(n == 1) {
            return nums[0];
        }
        vector<int> dp(n);
        //首先边界条件：
        //只有一座房屋 抢！
        dp[0] = nums[0];
        //有两座 选最大的抢
        dp[1] = max(nums[0],nums[1]);
        //进入动态规划
        for(int i = 2;i<n;i++){
            //可以抢第i座也可以不抢 选其中钱最多的!
            //抢了第i座就只能抢前i-2座
            //不抢第i座就能抢前i-1座
            //本质还是从后往前递归
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
         return dp[n-1];
    }
   
};