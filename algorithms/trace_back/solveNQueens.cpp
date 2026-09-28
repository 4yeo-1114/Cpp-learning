#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//N皇后问题
//由于每行恰好放一个皇后，记录每行的皇后放在哪一列，可以得到一个 [0,n−1] 的排列 queens。
//如示例 1 的两个图，分别对应排列 [1,3,0,2] 和 [2,0,3,1]。所以我们本质上是在枚举列号的全排列。

//怎么判断皇后会不会互相攻击 处于同一主对角线的格子行坐标和列坐标的差为常数 副对角线和为常数 所以用两个数组储存
//范围为-(n-1) - (n-1)

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        //初始化一个n*n的棋盘 每个格子都初始化为.
        vector board(n,string(n,'.'));
        //记录每个格子的列坐标以及行列坐标和差数组
        vector<uint8_t> col(n),diag1(n*2-1),diag2(n*2-1);
        auto dfs = [&](this auto&&dfs,int r){
            //排完了
            if(r==n){
                ans.push_back(board);
                return ;
            }
            //在(r,c)放皇后
            for(int c = 0;c<n;c++){
                int rc = r-c+n-1; //为什么要+ n-1 数组不能为负数
                if(!col[c] && !diag1[r+c] && !diag2[rc]) {
                    //即没放过 也不会被吃
                    board[r][c] = 'Q';
                    col[c]=diag1[r+c]=diag2[rc]  =true;
                    dfs(r+1);
                    col[c] = diag1[r+c] = diag2[rc] = false; //恢复现场
                    board[r][c]  = '.';

                }
            }

        };
        dfs(0);
        return ans;
    }
};