#include <string>         // 提供 string 类型，以及 s.size(), s.substr() 等字符串操作
#include <vector>         // 提供 vector 动态数组，用于 wordDict 和 memo
#include <unordered_set>  // 提供 unordered_set 哈希集合，用于 O(1) 极速查词
#include <algorithm>      // 提供 ranges::max (找最长单词) 和 max (比较大小)

using namespace std;      // 必须加上这句，否则你要到处写 std::string, std::vector


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        //max_len表示wordDict最长单词的长度
        int max_len = ranges::max(wordDict,{},&string::size).size();
        //建立哈希表 方便后面找子串在没在wordDict
        unordered_set<string> words(wordDict.begin(),wordDict.end());

        int n = s.size();
        vector<int> memo(n+1,-1); //-1表示没计算过

        auto dfs = [&](this auto&& dfs,int i)->bool{
            //成功拆分
            if(i==0){
                return true;
            }
            int& res = memo[i];//引用
            if(res!=-1){
                //之前计算过
                return res;
            }
            //一定要max(i-max_len,0)一方面不可能分割出比单词表长度最长单词还长的单词另一方面不能越界
            for(int j = i-1;j>=max(i-max_len,0);j--){
                if(words.contains(s.substr(j,i-1))&&dfs(j)){
                    return res = true;//记忆化
                }
            }
            //记忆化
            return res = false;
        };

        return dfs(n);
    }
};


//递归写法
//得外层循环枚举长度内层枚举words
//不能反着写变成完全背包 因为完全背包是一个物品连续选择以后再也不选了 这里单词组合可以交替

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        //max_len表示wordDict最长单词的长度
        int max_len = ranges::max(wordDict,{},&string::size).size();
        //建立哈希表 方便后面找子串在没在wordDict
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        
        //n为枚举长度
        int n = s.size();

        //递归函数
        vector<int> f(n+1);
        //边界条件
        f[0] = true;
        //这里的i是长度不是下标
        for(int i = 1;i<=n;i++){
            //这里j即要大于i-ma_len也要大于0
            for(int j = i-1;j>=max(i-max_len,0);j--){
                if(f[j]&&words.contains(s.substr(j,i-j))){
                    f[i] = true;
                    //找到一种了就退出
                    break;
                }
            }
        }
        
        return f[n];

        
    }
};
