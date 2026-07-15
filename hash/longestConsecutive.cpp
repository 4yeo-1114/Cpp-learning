#include <vector>         
#include <unordered_set>  
#include <algorithm>    
using namespace std;  

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        //unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(int x : st){
            if(st.count(x-1)){
                continue;
            }
            int  y = x+1;
            while(st.count(y)){
                y++;
            }
            ans = max(ans,y-x);
            if(ans*2>=nums.size()) break;

        }
        return ans;
    }

};

// 不能排序 不符合时间复杂度为O(n)的要求
// 建立哈希表就可以实现O(1)的查找
//  若x-1在哈希表里 则不以x为起点
//  这题的抓手是找起点，因为找到连续序列的起点就可以统计长度，
//  为了降低找起点的时间复杂度从而使用HashSet快速判断,判断依据是x-1是否在集合中。