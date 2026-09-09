/* C++ | dp: longest valid parentheses. */
#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
#include <string>
using namespace std;  

class Solution {
public:
    int longestValidParentheses(string s) {
        //创建一个栈 因为要求长度 所以存的是下标而不是字符
        stack<int> st;
        //初始断点为-1 想一下（）怎么算长度的
        st.push(-1);
        int max_len = 0;
        //遍历字符串
        for(int i = 0;i<(int)s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                st.pop();
                //如果栈空了说明弹出去是断点 要加入新的断电即当前下标
                if(st.empty()){
                    st.push(i);
                }
                else{
                    max_len = max(max_len,i-st.top());
                }
                    
            }
        }
        return max_len;
    }
};

//用动态规划写
//dp[i] 表示：以第 i 个字符作为结尾的，最长有效括号子串的长度。
//只可能以）结尾所以只算）的即可
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        int n = s.length();
        vector<int> dp(n,0);
        //循环直接从一开始 因为最短也要两个
        for(int i = 1;i<n;i++){
            if(s[i]==')'){
                //情况 A：隔壁就是对象 ()
                if(s[i-1]=='('){
                    //一定要防止负数下标 下面的也一样
                    dp[i] = (i-2>=0?dp[i-2]:0)+2;
                }
                //情况B：((...))
                else if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                    dp[i] = dp[i-1] + (i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0)+2;
                }

            }
        }
        return *max_element(dp.begin(),dp.end());

    }
};