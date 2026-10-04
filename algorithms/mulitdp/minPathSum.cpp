#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(j==0){
                    dp[j] += grid[i][j];
                }
                //这里要特殊处理一下第一层的情况 因为一开始第一层dp[j]=0 如果和后面的一样按min处理就不对了 只能从左边过来
                else if(i==0){
                    dp[j] = dp[j-1] + grid[i][j];
                }
                else{        
                dp[j]  = min(dp[j],dp[j-1]) + grid[i][j];
                }
            }
        }
        return dp[n-1];
    }
};