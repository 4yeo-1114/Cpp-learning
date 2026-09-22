#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


// 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
//找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 


//这么写确实是能输出答案 但是因为每次都是从数组第一个开始遍历 导致回出现很多重复组合
//即下面的代码给出的是全排列
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&&dfs,int target)->void{
            if(target==0){
                ans.emplace_back(path);
                return;
            }
            if(target<0){
                return ;
            }
            for(int num:candidates){
                path.push_back(num);
                dfs(target-num);
                path.pop_back();
            }
        };
        dfs(target);
        return ans;

    }
};

//要只得到组合 每次进入递归函数 遍历得起点就得向前 

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        //start参数保证组合得非递减选择序列
        auto dfs = [&](this auto&&dfs,int start,int target)->void{
            if(target==0){
                ans.emplace_back(path);
                return;
            }
            if(target<0){
                return ;
            }
            for(int i = start;i<candidates.size();i++){
                path.push_back(candidates[i]);
                //下一层从i开始 因为允许重复使用 但是禁止倒回去选i之前的元素
                dfs(i,target-candidates[i]);
                path.pop_back();
            }
        };
        dfs(0,target);
        return ans;

    }
};