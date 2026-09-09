/* C++ | dp: longest increasing subsequence. */
#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  

//子序列不用连续 子数组要连续
//递推
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        vector<int> dp(n,0);
        //dp[i] 表示以i结尾的数组中最长递增子序列的长度
        //故全都初始化为1，并且i从0到n-1遍历
        for(int  i =0;i<n;i++){
            dp[i] = 1;
            //再分割子问题 看i前面的递增子序列长度
            for(int j = 0;j<i;j++){
               if(nums[i]>nums[j]) dp[i] = max(dp[i],dp[j]+1);
            }
        }
        //错！！ 不是return dp[n-1]因为最长的递增子序列不一定是以n-1结尾的！
        //应该是dp中的最大值
        return *max_element(dp.begin(), dp.end());
    }
};

//记忆化搜索 递归
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //记忆化数组 可以初始化为0 因为长度最短也为1
        vector<int> memo(n);
        //递归函数格式： auto dfs = [&](this auto&&dfs,int i)-> int{};
        auto dfs = [&](this auto&& dfs, int i) -> int {
            int& res = memo[i]; // 注意这里是引用
            if (res > 0) { // 之前计算过
                return res;
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    //递归也好递推也罢 在更新的时候一定要和自己之前的值比较
                    res = max(res, dfs(j));
                }
            }
            res++; // 加一（nums[i]自己）提到循环外面
            return res;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};


