#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
#include <vector>
using namespace std; 

//跳跃问题 从后往前遍历 更新终点
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        while(end>=0){
            int flag  =0;
            if(end==0){
                return true;
            }
            for(int i = end-1;i>=0;i--){
                if(nums[i]>=end-i){
                    end = i;
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                return false;
            }
        }
        return true;
    }
};