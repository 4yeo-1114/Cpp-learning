#include <iostream>
#include  <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int p = 0;
        int ans = -10000;
        for(int a : nums){
            p = max(p,0) + a;
            ans = max(ans, p);
        }
    return ans ; 
    }
};


