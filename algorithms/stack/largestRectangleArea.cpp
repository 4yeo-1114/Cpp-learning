#include <iostream>
#include <algorithm>  // swap
#include <vector>
#include <stack>
using namespace std;

//和dailyTemperatures 是一个道理的 用贪心的逻辑去维护一个单调栈 遇到矮的就开始计算面积
//right是右边第一个比当前柱子矮的下标 left是左边第一个比当前柱子矮的小标
//那么计算当前柱子对应的最大矩形就是 h*（right-left-1）
//利用单调栈 发生出栈时即遇到矮的 这个下标就是right 然后 栈的下一个就是left 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n  = heights.size();
        stack<int> sk;
        int ans = 0;
        for(int i = 0;i<=n;i++){
            //在下标为n的地方虚构一个高度为0的柱子 把左边的所有柱子都弹出
            int cur = i==n?0:heights[i];
            while(!sk.empty()&&(i==n||cur<heights[sk.top()])){
                int h  = heights[sk.top()];
                sk.pop();
                //如果已经是第一根柱子了 left为-1
                int left = sk.empty()?-1:sk.top();
                ans = max(ans,h*(i-left-1));

            }

            sk.push(i);

        }
        return ans;
    }
};
