#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int  n = word1.size();
        int m = word2.size();
        //dp[i][j] 表示第一个单词i个字母 怎么变成第二个单词j个字母
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        //初始化
        for(int j  = 1;j<=m;j++){
            f[0][j]  = j; //第一个单词没有字母 第二单词j个 只能增加j个单词
        }
        for(int i = 1;i<=n;i++){
            f[i][0] = i; //第一个单词i个 第二个0个 删除i个单词
            for(int j  =1;j<=m;j++){
                //如果当前字母一样那操作数就和f[i-1][j-1]一样 
                //如果不一样 考虑 删除f[i-1][j]+1 增加f[i][j-1]+1 替换f[i-1][j-1]+1
                f[i][j] = word1[i-1]==word2[j-1]?f[i-1][j-1]:min({f[i-1][j],f[i][j-1],f[i-1][j-1]}) +1;
            }
        }
        return f[n][m];
    }
};