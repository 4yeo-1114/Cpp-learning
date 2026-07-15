#include <vector>         
#include <unordered_map>  
#include <unordered_set>
#include <algorithm>    
#include <string>
#include <numeric>
using namespace std; 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int sum = 1;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                sum = 0 ;
                break;
            }
            else{
                sum *=nums[i];
            }
        }
        vector<int>answer(n) ;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                answer[i] = 1;
                for(int j = 0;j<i;j++){
                    answer[i]*=nums[j];
                }
                for(int z = i+1;z<n;z++){
                    answer[i]*=nums[z];
                }
            }
            else{
                answer[i] = sum/nums[i];
            }
        }
        return answer;
    }
};

//左右前缀积法：
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // 直接开辟大小为 n 的数组
        vector<int> answer(n);
        
        // 1. 先计算每个元素“左边所有元素的乘积”
        // 第一个元素左边没有东西，所以初始化为 1
        answer[0] = 1;
        for (int i = 1; i < n; i++) {
            // 当前元素的左侧乘积 = 前一个元素的左侧乘积 * 前一个元素的值
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        
        // 2. 再计算每个元素“右边所有元素的乘积”，并直接乘到 answer 里
        // 最后一个元素右边没有东西，所以右侧乘积初始为 1
        int right_product = 1; 
        for (int i = n - 1; i >= 0; i--) {
            // 左边乘积（已经在 answer 里了） * 右边乘积
            answer[i] = answer[i] * right_product;
            
            // 动态更新右侧乘积，供下一个（也就是更左边的一个）元素使用
            right_product = right_product * nums[i];
        }
        
        return answer;
    }
};