#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
#include <vector>
using namespace std; 

//跳跃游戏二 不是要放回true或者false 而是要最小的跳跃次数 题目保证可以到达
class Solution {
public:
    int jump(vector<int>& nums) {
        int n  = nums.size();
        int count = 0;
        int end = n-1;
        //不能=0 =0 死循环了
        while(end>0){
            int farthest = end ;
            //这里要找最远的 就得从左到右遍历 最好就是第一个就能跳到
            for(int i = 0; i<=end-1;i++){
                if(nums[i]>=end - i){
                    farthest = min(farthest,i);
                    break;
                }
            }
            end = farthest;
            count ++;
        }
        return count;
    }
};

//最优算法正向贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int n  = nums.size();
        int max_pos = 0; //探测到的全局最远位置
        int cur_end = 0; //目前步速能到的最远位置
        int step = 0;
        //只遍历到n-2 因为到达n-1不需要再跳了
        for(int i = 0;i<n-1;i++){
            max_pos = max(max_pos,i+nums[i]);
            //已经到极限了 就结算一次起跳 跳到全局最远位置
            if(i==cur_end){
                cur_end = max_pos;
                step++;
            }

        }
        return step;
    }
};