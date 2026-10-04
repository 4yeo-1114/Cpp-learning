#include<iostream>
#include<vector>
using namespace std;


//经典的棋盘路径问题 
//dfs暴力搜索会把整颗递归树展开 时间复杂度到了2的m+n次方 同一条路径会重复计算很多次
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int ans = 0;
        auto dfs = [&](this auto&&dfs,int x,int y) ->void{
            if(x==m&&y==n){
                ans ++;
                return ;
            }
            else if(x>m) return;
            else if(y>n) return;
            dfs(x+1,y);
            dfs(x,y+1);
        };
        dfs(1,1);
        return ans;

    }
};

//优化:记忆化搜索 记忆下每个递归状态的结果 这样就不用重复计算了

class Solution {
public:
    int uniquePaths(int m, int n) {
        //用一个二维数组储存记忆
        vector<vector<int>> memo(m+1,vector<int>(n+1,0));
        //dfs(x,y)表示从x,y开始的结果
        auto dfs = [&](this auto&&dfs,int x,int y)->int{
            if(x==m&&y==n) return 1;
            else if(x>m||y>n) return 0;
            if(memo[x][y]!=0) return memo[x][y];

            return memo[x][y] = dfs(x+1,y)  + dfs(x,y+1);
        };
        return dfs(1,1);
    }
};


//动态规划
//dp[i][j] = dp[i-1][j] +dp[i][j-1]
//可以把空间压缩到一维
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i = 0;i<m;i++){
            for(int j = 0 ;j<n;j++){
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
    
};


