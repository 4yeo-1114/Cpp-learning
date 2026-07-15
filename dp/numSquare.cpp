#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  

//f[i] 表示最少需要多少个数的平方来表示整数 i
//这些数必然落在区间 [1, i的平方根]。我们可以枚举这些数，假设当前枚举到 j，
//那么我们还需要取若干数的平方，构成（i−j^2） 。这样又回到了一个子问题。
//f[0]=0 为边界条件
//因为计算 f[i] 时所需要用到的状态仅有 f[i−j^2]，必然小于 i，因此我们只需要从小到大地枚举 i 来计算 f[i] 即可

class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n+1);
        //计算从1到n的所有情况
        //从小到大！！
        for(int i = 1;i<=n;i++){
            int minn = INT_MAX;
            for(int j = 1;j*j<=i;j++){
                minn = min(minn,f[i-j*j]);
            }
            //记录结果 记得要加一 表示先取了j再加上i-j*j的情况
            f[i] = minn+1;

        }
        return f[n];
    }
};

//硬币问题
//你有m种硬币,面额分别为1,4,9,16......你需要购买一个价格为n的商品,问最少花费几枚硬币
class Solution {
    public:
     int numSquares(int n) {
        int size = (int)sqrt(n) + 5;
        vector<int> coins(size);
        //初始化为最大值n 全用1来付
        vector<int> dp(n+1,n);
        //初始化完全平方数数组
        for(int i = 1; i < coins.size(); i++){
            coins[i] = i * i;
        }
        //边界条件：和为0需要零个硬币
        dp[0]= 0;
        //遍历每个完全平方数 从2*2=4 开始 因为1在初始化的时候已经用了
        //先遍历物品再遍历背包容量
        //这里只要求最小值 循环先背包再物品其实也一样
        for(int i = 2; i < coins.size(); i++){
            int money = coins[i];
            for(int j = money; j <= n; j++){
                dp[j] = min(dp[j],dp[j - coins[i]] + 1);
            }
        }
        return dp[n];
    }
};