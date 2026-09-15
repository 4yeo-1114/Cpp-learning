/* C++ | greedy: longest increasing subsequence. */
#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  

//用贪心去维护一个递增数组 但是d并不是最终的最长递增子序列
//d[k] 的真实含义是：
//在目前读过的数字中，长度为 k 的递增子序列，其末尾最小能是多少。
//如果下一个数大于我们数组的结尾即d[len]则加入 len++
//如下一个数是一个小的数 则我们“换血” 他加入数组比数组中刚好比他大的元素有用
//因为我们要尽可能地把数组变窄 所以用二分找到最后一个比他小的数 更新位置
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1;
        int n = nums.size();;
        if(n==0){
            return 0;
        }
        vector<int> d(n+1,0);
        d[len] = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i]>d[len]){
                d[++len] = nums[i];
            }
            else{
                int l = 1,r =len,pos = 0;
                //如果找不到说明d中所有的数都比nums[i]大 此时要更新d[1]所以pos初始化为0
                while(l<=r){
                    int mid  = l+(r-l)/2;
                    //红蓝染色法
                    //pos表示最后一个比nums[i]小的位置
                    //则nums[i]自然要插入到pos+1
                    if(d[mid]<nums[i]){
                        pos = mid;
                        l = mid+1;
                    }
                    else{
                        r = mid -1;
                    }
                }
                d[pos+1]  = nums[i];
            }
        }
        //最后我们放回我们维护的数组长度
        return len;
    }
};