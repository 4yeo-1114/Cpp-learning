#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//对三个颜色排序
//冒泡写法
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            for(int j = 0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    int temp = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = temp;
                }
            }
        }

    }
};


//荷兰国旗双指针写法

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //双指针
        int l = 0, r = nums.size()-1;
        int cur = 0;
        while(cur <= r){
            //看到0 就移动到左边 同时左指针加加
            if(nums[cur]==0){
                swap(nums[l], nums[cur]);
                l++;
                cur++;
            //看到2 移到右边
            }else if(nums[cur]==2){
                swap(nums[cur], nums[r]);
                r--;
            }else{
                cur++;
            }
        }
    }
};