#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

//给定括号组合数量 给出所有满足的组合
//本质还是组合问题但是有约束 就是在递归过程中右括号个数不能大于左括号 ())(不合法
//所以还是选或者不选的问题 但是选右括号的条件是right<left 左括号的条件是left<n
//当right=n时一定选满了 注意不是left
//为什么不需要恢复现场
//如果初始化 path 为空列表，就需要写恢复现场。
// 本题由于所有括号长度都是固定的 2n，我们可以创建一个长为 2n 的 path 列表，
// 在递归时直接写入字符（而不是插入字符），这样做无需写恢复现场。



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path(2*n,0);//每一个答案长度都是2n 初始化为“       ”
        int left = 0; // 表示左括号的数量
        int right = 0; //表示右括号的数量
        auto dfs = [&](this auto&&dfs,int left,int right) -> void{
            if(right==n){
                ans.emplace_back(path);
                return ;
            }
            if(left<n){
                path[left+right] = '(';
                dfs(left+1,right);
            }
            if(right<left){
                path[left+right] = ')';
                dfs(left,right+1);
            }
        };
        dfs(0,0);
        return ans;
    }
};