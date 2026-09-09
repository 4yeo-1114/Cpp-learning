/* C++ | binary search: search range. */
//二分
//找出有序数列中第一个大于等于target的数的位置
//闭区间写法 手动实现lower_bound

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_firsttarget(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size() -1;
        //闭区间写法小于等于
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]<target){
                left = mid+1;

            }
            else{
                right = mid-1;
            }

        }
        return left;
}

//左闭右开
int find_firsttarget(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size();
        //左闭右开 写法小于 若等于区间内就没元素了
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]<target){
                left = mid+1;

            }
            else{
                //右开
                right = mid;
            }

        }
        return left;
}

//全开
int find_firsttarget(vector<int>& nums,int target){
        int left = -1;
        int right = nums.size();
        //开区间写法
        while(left+1<right){
            int mid = left+(right-left)/2;
            if(nums[mid]<target){
                left = mid;

            }
            else{
                right = mid;
            }

        }
        //为什么是right 自己模拟一下
        return right;
}


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //先找大于等于
        int start = find_firsttarget(nums,target);
        //数组中找不到大于等于target时start会等于n
        //还有找到了大于但是不等于的位置 也不行
        if(start==nums.size()|| nums[start]!=target){
            return {-1,-1};
        }
        //再找大于target的位置 即end的后一位
        int end =find_firsttarget(nums,target+1);
        end = end-1;
        
        return {start,end};
    }
};