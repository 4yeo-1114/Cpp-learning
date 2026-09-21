#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


//枚举子集

//做法一 选或者不选 每个节点都可以选或者不选 看作是一个选择二叉树即可 树的叶子就是子集
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();  // 根据数学知识 子集个数一定是2的n次方
        vector<vector<int>> ans;
        vector<int> path;
        //这个函数的意思就是决定i位置的数字要不要取
        auto dfs = [&](this auto&& dfs,int i) ->void{
            //如果到达末尾了
            if(i==n){
                ans.emplace_back(path);
            }

            //不取
            dfs(i+1);

            //取
            path.push_back(nums[i]);
            dfs(i+1);
            path.pop_back(); //恢复状态 防止污染其他的分支
        
        };
        dfs(0);
        return ans;

    }
};

//为什么要pop
// 刚开始：
// 篮子：path = []
// 第 0 层（考虑数字 1）：
// 不选 1：直接调用 dfs(1)。
// 来到第 1 层（考虑数字 2）：
// 不选 2：直接调用 dfs(2)。到了尽头，收集到子集 []。
// 选 2：path.push_back(2)，此时 path = [2]。调用 dfs(2)，收集到子集 [2]。
// (如果此时不把 2 拿出来，path 里面就一直留着 2！)
// 第 1 层执行完毕，返回到第 0 层。
// 回到第 0 层，终于轮到“选 1”的分支了：
// 代码执行：path.push_back(1)。如果之前选 2 后没有 pop_back()，此时篮子里已经有个 2 了，再放一个 1，篮子变成了 [2, 1]！
// 接着走 dfs(1)（考虑 2）：
// 选 2：path.push_back(2)，篮子变成了 [2, 1, 2]！
// 如果不清空，后面所有分支都会被前面留下的“脏数据”污染。


//做法二 ：选哪一个 这里就是树的节点是子集了 这颗递归树是一个多叉树
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n  = nums.size();
        vector<int> path;
        vector<vector<int>> ans;

        //dfs(i)表示从i到n-1选一个数
        auto dfs =  [&](this auto&&dfs,int i) ->void{
            ans.emplace_back(path); // 不选了直接加入答案
            for(int j = i;j<n;j++){
                path.push_back(nums[j]); //加入子集
                dfs(j+1); //继续递归后面的子集 只能继续往后选 保证顺序 保证子集不重复
                path.pop_back(); //回溯防止污染其他分支 这样这轮循环结束后下一轮循环得到的就是干净的path
            }
        };
        dfs(0);
        return ans;
    }
};