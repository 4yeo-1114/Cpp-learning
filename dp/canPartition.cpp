#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  
//若数组和为s s为奇数时没法分割为两个和一样的子序列
//s为偶数时 则这个子序列要和为s/2 转化为求和为s/2的子序列
//方法一：记忆化搜索 递归
class Solution {
public:
    bool canPartition(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0||n<=1){
            return false;
        }
        //定义dfs(i,j) 表示能否从nums[0]到nums[i]中选出一个和恰好为j的子序列
        //考虑nums[i]选还是不选
        //选：问题变为能否从nums[0]到nums[i-1]中找出和为j-nums[i]的子序列
        //不选：问题变为能否从nums[0]到nums[i-1]中找出和为j的子序列
        //这两个只要有一个成立 dfs(i,j)就是true
        //递归边界dfs(-1,0) = true dfs(-1,>0)=false 递归入口dfs(n-1,s/2) 倒着来的
        vector memo(n,vector<int>(sum/2+1,-1));//-1表示没计算过
        auto dfs = [&](this auto&&dfs,int i , int j) ->bool{
            if(i<0){
                return j==0; //刚好凑够就放回1 不够就返回-1 递归边界
            }
            int &res = memo[i][j];
            if(res!=-1){//计算过
                return res;
            }
            if(j<nums[i]){//nums[i]比j还大只能不选
                return res = dfs(i-1,j);

            }
            return res = dfs(i-1,j)||dfs(i-1,j-nums[i]);//选或不选

        };
        //递归入口
        return dfs(n-1,sum/2);
    }
};


//把递归翻译为递推 即自底向上
class Solution {
public:
    bool canPartition(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0||n<=1){
            return false;
        }
        //递推数组
        //这里要注意f[i+1][j] 表示从nums[0]到nums[i]能否找到和为j的子序列
        //因为我们要用f[0][j] 来表示没用数字的情况即边界情况 f[0][0] =1表示成功 其他为0表示失败
        //dfs不需要是因为函数传参可以传负数表示没有数字咯
        vector f(n+1,vector<int>(sum/2+1));
        f[0][0] = 1;
        //0-1背包问题 遍历物品再遍历容量
        for(int i = 1;i<=n;i++){
            for(int j  =0;j<=sum/2;j++){
                //选或者不选 在选之前要确保背包容量够
                    f[i][j] = (j>nums[i]&&f[i-1][j-nums[i]]) || f[i-1][j];
            }
        }
        return f[n][sum/2];
    }
};

// vector f(n+1,vector<int>(sum/2+1))
// f[0][0]  = 1;
// for(int i = 0;i<n;i++){
//     for(int j = 0;j<=sum/2;j++){
//         f[i][j] = (j>nums[i]&&f[i-1][j-nums[i]])||f[i-1][j];
//     }
// }
// return f[n][sum/2];

//空间优化 因为我们只会用到上一层的状态 所以可以动态改变一个一维数组
class Solution {
public:
    bool canPartition(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0||n<=1){
            return false;
        }
        vector<int> f(sum/2+1);
        f[0] = 1;
        int s2 = 0;
        for(auto x:nums){
            //假设前i个数和为s' 因为和不可能比s'大 所以直接从min(s',sum/20)枚举j即可 
            s2 = min(s2+x,sum/2);
            for(int j  =s2;j>=x;j--){
                f[j]  = f[j]||f[j-x];
                //为什么直接到j>=x就结束了没考虑只不选的情况
                //因为在之前只不选的化f[i][j] = f[i-1][j] 这里是一位直接继承前面的状态就好了 不用更新
            }
            //如果循环中途就有遇到满足和为sum/2的情况直接返回
            if(f[sum/2]){
                return true;
            }

        }
        return false;
    }
};

