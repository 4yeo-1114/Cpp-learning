#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

//在二维字符网格中搜索单词
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        char s = word[0];
        int l  =word.size();
        //记录所有首字母匹配的坐标
        vector<int> sx;
        vector<int> sy;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]==s){
                    sx.push_back(j);//列坐标
                    sy.push_back(i);//行坐标
                }
            }
        }
        if(sx.empty()&&sy.empty()){
            return false;
        }
        auto dfs = [&](this auto&&dfs,int x,int y,int target) -> bool{
            //越界检查
            if(y<0||y>=n||x<0||x>=m){
                return false;
            }
            if(board[y][x]==word[target]){
                if(target==l-1){
                    return  true;
                }
                // 回溯：先标记当前格子已范围 反正后面的函数又折返回来
                //可以把格子改为#标记
                char temp = board[y][x];
                board[y][x] = '#';

                //向四个方向递归 
                bool found = dfs(x + 1, y, target + 1) ||
                         dfs(x - 1, y, target + 1) ||
                         dfs(x, y + 1, target + 1) ||
                         dfs(x, y - 1, target + 1);
                
                board[y][x] = temp; //恢复现场
                return found;
            }
            //不匹配直接false
            return false;
        };
        for(int i = 0 ;i<sx.size();i++){
            if(dfs(sx[i],sy[i],0)){
                return true; //只要有一个能以该起点成立的路径就成功
            }
        }
        return false;
    }
};