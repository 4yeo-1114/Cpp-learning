#include <vector>         
#include <unordered_set>  
#include <algorithm>    
using namespace std;  


//相向双指针
//那边小就移动那边
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left<right){
            int area = (right-left) * min(height[left],height[right]);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
            ans = max(ans,area);
        }
        return ans;
    }
};