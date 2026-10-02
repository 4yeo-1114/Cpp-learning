#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n  = nums.size();
        int count = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==ans){
                count++;
            }
            else if(nums[i]!=ans&&!count){
                ans = nums[i];
                count = 1;
            }
            else if(nums[i]!=ans&&count){
                count --;
            }
        }
        return ans;
    }
    
};