#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0;i<numRows;i++){
            ans[i].resize(i+1,1);
            //第一个和最后一个默认一 中间的递推
            for(int j = 1;j<i;i++){
                ans[i][j] = ans[i-1][j-1] +ans[i-1][j];
            }
        }
        return ans;
    }
};

/* 怎么理解这个递推式
本质上是一个组合数恒等式，其中 c[i][j] 表示从 i 个不同物品中选出 j 个物品的方案数。
如何理解上式呢？考虑其中某个物品选或不选：
选：问题变成从剩下 i−1 个不同物品中选出 j−1 个物品的方案数，即 c[i−1][j−1]。
不选：问题变成从剩下 i−1 个不同物品中选出 j 个物品的方案数，即 c[i−1][j]。
*/