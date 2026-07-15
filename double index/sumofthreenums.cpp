#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int  n = nums.size();
        if(n<3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<n-2;i++){
            int x = nums[i];
            //跳过重复数字
            if(i!=0&&nums[i]==nums[i-1]) continue;
            if(x+nums[i+1]+nums[i+2]>0) break;
            if(x+nums[n-1]+nums[n-2]<0) continue;
            //相向双指针
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum  = x+nums[l]+nums[r];
                if(sum==0){
                    ans.push_back({x,nums[l],nums[r]});
                    //ans.push_back(x,nums[l],nums[r]);
                    //去掉重复情况
                    for(l++;l<r&&nums[l]==nums[l-1];l++);
                    for(r--;l<r&&nums[r]==nums[r+1];r--);
                }
                else if(sum>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};