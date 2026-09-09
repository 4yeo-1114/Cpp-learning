/* C++ | binary search: search insert. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = -1;
        int right  = n;
        while(left+1<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>=target){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return right;
    }
};