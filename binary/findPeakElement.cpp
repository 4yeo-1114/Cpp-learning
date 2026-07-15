#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //用开区间写法
        int left =  -1;
        int right  = nums.size()-1; //保证mid+1不会出现溢出
        //为什么二分范围不用包含 n−1
        //因为如果坡峰就是n-1 那么left一直移动 最后返回right(n-1)就是答案
        while(left+1<right){
            int mid =  left+(right-left)/2;
            //假设正在爬坡 若下一个坡比现在的坡高则坡峰一定在后面 哪怕一直变高 最后一个也一定是
            if(nums[mid]<nums[mid+1]){
                left = mid;
            }
            //反之坡峰在左边
            else{
                right = mid;
            }
        }
        return right;
    }
};