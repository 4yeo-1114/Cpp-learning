#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //求最小值时如果不给他一个初始极大值 怎么能用min替换
        //如果全是面额为1的硬币 则要amount个 所以初始化为amount+1
        vector<int> dp(amount+1,amount+1);
        //钱为零的时候有零种组合
        //递推的边界条件
        dp[0] = 0;
        for(int i = 0;i<coins.size();i++){
            //j要从当前硬币面额coins[i]开始防止数组下标负数
            for(int j = coins[i];j<=amount;j++){
                //在拿当前硬币和不拿(延用之前的dp[j])做选择
                dp[j] =  min(dp[j],dp[j-coins[i]]+1);
            }
        }
        //如果结果还是amount+1 说明凑不出来 放回-1
        if(dp[amount]>amount){
            return -1;
        }
        else{
            return dp[amount];
        }
    }
};


/*
初始化技巧是动态规划里非常重要的一环：
求 最大值 时（如之前的打家劫舍），数组通常初始化为 0。
求 最小值 时（如这道零钱兑换），数组必须初始化为一个 极其大的数（无穷大）。
*/