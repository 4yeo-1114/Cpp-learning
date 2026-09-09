/* C++ | dp: trap. */
//接雨水
//方法一：用两个数组储存当前位置左边的最大高度和右边的最大高度
//每个位置能接的雨水就是min(left,right)-当前高度


#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i = 1 ;i<height.size();i++){
            left[i] = max(height[i],left[i-1]);
        }
        for(int j = n-2;j>=0;j--){
            right[j] = max(height[j],right[j+1]);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += min(left[i],right[i]) - height[i];

        }
        return ans;
    }
};
//优化 用变量来动态存储前缀最大值和后缀最大值
//一次遍历即可：指针相向移动的过程中即动态变化最大值 
//同时根据哪边小 来算哪边的雨水
class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
       int left = 0;
       int right = n-1;
        //pre为当前的前缀最大值
        //suf为当前的后缀最大值
        int pre = height[0];
        int suf = height[n-1];
        int ans = 0;
        while(left<=right){
            //先动态规划
            pre = max(pre,height[left]);
            suf = max(suf,height[right]);
            //哪边小就算哪边的雨水
            if(pre<suf){
                ans += pre -height[left];
                left ++;
            }
            else{
                ans += suf - height[right];
                right--;
            }

        }
        return ans;

    }
};


//方法二：维护一个单调递减栈 栈顶是高度最小的
//栈储存的是下标
//这种做法相当于横着算面积
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                //遇到i比自己（top）高
                //i就是右边界
                //left即栈的第二个元素即为左边界
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            //因为上面的while保证了现在i的高度不比栈顶高 所以无论如何都入栈
            stk.push(i);
        }
        return ans;
    }
};

