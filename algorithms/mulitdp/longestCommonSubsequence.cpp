#include <iostream>
#include <string>
#include <vector>
using namespace std;

//LCS问题 不能简单的贪心 因为具有重叠子问题和最优子结构性质，必须同时考虑两个字符串当前字符选与不选的状态，需要二维动态规划
//用双指针来动态规划 相当于选或者不选的问题
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        //dp[i][j]表示text1前i个字符和text2前j个字符的LCS长度
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        //注意这里是从1开始 防止访问非法下标
        for(int i = 1;i<=l1;i++){
            for(int j = 1;j<=l2;j++){
                if(text1[i-1]==text2[j-1]){
                    //匹配了就相当于都要选 直接在都包含当前字符的最优解上+1
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                else{
                    //不匹配 舍弃一个 不能都舍弃 都舍弃则退化到上一个状态了
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }

            }
        }
        return dp[l1][l2];
    }
};


//一样可以压缩为一维
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        //dp[j]表示当前text1长度和text2前j个字符的LCS长度
        vector<int> dp(l2+1,0);
        //注意这里是从1开始 防止访问非法下标
        for(int i = 1;i<=l1;i++){
            int pre = 0; // 记录上一行的 dp[j-1]（即左上角 dp[i-1][j-1]）
            for(int j = 1;j<=l2;j++){
                int temp = dp[j] ; //此时dp[j]还没改所以他还是dp[i-1][j];
                if(text1[i-1]==text2[j-1]){
                    //匹配了就相当于都要选 直接在都包含当前字符的最优解上+1 这里不能直接写dp[j] = dp[j-1] +1 因为dp[j-1]已经是dp[i][j-1]了
                    //所以必须用temp;
                    dp[j] = pre +1;
                }
                else{
                    //不匹配 舍弃一个 不能都舍弃 都舍弃则退化到上一个状态了
                    dp[j] = max(dp[j],dp[j-1]);
                }
                 pre = temp; //为下一个状态转移做准备

            }
        }
        return dp[l2];
    }
};