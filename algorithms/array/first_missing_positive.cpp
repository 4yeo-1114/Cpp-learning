/* C++ | array: first missing positive. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//找最小的不存在的正数
//方法一：排序加遍历
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        int flag = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>1){
                ans = 1;
                flag = 1;
                break;
            }
            if(nums[i]>=0){
                flag  =1;
                while(i!=nums.size()-1&&(nums[i+1]==nums[i]+1||nums[i+1]==nums[i])){
                    i++;
                }
                ans = nums[i]+1;
                break;
            }


        }
        return ans;
    }
};

//方法二(原地哈希)：让每个正数去到它应该去的地方 如1在下标为0的地方 2在下标为1的地方 
//重排后 第一个不符合的就是答案
class Solution {
public:
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    int firstMissingPositive(vector<int>& nums) {
       for(int i = 0;i<nums.size();i++){
        //如果nums[i]为正数 并且它该在的地方不是他 那就交换 注意要保证下标范围
        //注意这里要是while
        while(nums[i]>0&&nums[i]<=nums.size()&&nums[nums[i]-1]!=nums[i]){
            swap(nums[i],nums[nums[i]-1]);
        }
       }
       //再扫描一边找出第一个不符合的
       for(int i = 0;i<nums.size();i++){
        if(nums[i]!=i+1){
           return i+1;
        }
       }
       //找不到
       return nums.size()+1;
    }
};