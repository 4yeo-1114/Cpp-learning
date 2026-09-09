/* C++ | binary search: rotated search. */
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

//方法一：两次二分 一次找最小值 一次找target
bool findmin(vector<int>& nums){
    int n = nums.size();
    int left = -1;
    int right = nums.size()-1;
    while(left+1<right){
        int mid = left  + (right-left)/2;
        if(nums[mid]<nums[n-1]){
            right  = mid;
        }
        else{
            left = mid;
        }
    }
    return right;

}
int lowerbound(vector<int>&nums,int target,int left,int right){
    while(left+1<right){
        int mid = left + (right-left)/2;
        if(nums[mid]<target){
            left = mid;
        }
        else{
            right =  mid;
        }
    }
    //如果没找到返回-1
    return nums[right]==target?right:-1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int  n = nums.size();
        int i = findmin(nums);
        //target在第一段
        int ans = 0;
        if(target>nums.back()){
            ans = lowerbound(nums,target,-1,i);
        }
        //在第二段
        else{
            ans = lowerbound(nums,target,i-1,n);
        }
        return ans ; 
    }
};

//方法二 一次二分
bool is_blue(int mid,int target,vector<int>& nums){
    if(mid<=nums.back()&&target>nums.back()){
        return true;
    }
    else if(mid>nums.back()&&target<=nums.back()){
        return false;
    }
    else{
        return mid>=target;
    }

}


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int  n = nums.size();
        int left = -1;
        int right = n;
        while(left+1<right){
            int mid  = left +(right-left)/2;
            if(is_blue(nums[mid],target,nums)){
                right = mid;
            }
            else{
                left =  mid;
            }
        }
        return nums[right]==target?right:-1;
    }
};

