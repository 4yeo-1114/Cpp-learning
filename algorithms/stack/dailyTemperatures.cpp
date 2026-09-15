#include <iostream>
#include <algorithm>  // swap
#include <vector>
#include <stack>
using namespace std;


//answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
//维护一个单调递减的栈 这样一遇到高的就说明异常 就说明找到答案了
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n  = temperatures.size();
            stack<int> sk;
            vector<int> ans;
            for(int i = 0;i<n;i++){
                int cur = temperatures[i];
                //遇到高的
                while(!sk.empty()&&cur>temperatures[sk.top()]){
                    int j  =sk.top();
                    sk.pop();
                    ans[j] = i - j;

                }

                sk.push(i);

            }
            return ans;
    }
};