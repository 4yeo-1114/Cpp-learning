#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  
//求乘积最大子数组 因为会有负负得正 所以不能跟求和最大一样！！
//这就要求我们在遍历数组不能只记录当前最大值imax 还得记录当前最小值 以应付后面遇到正数的情况


//状态转移
//当我们走到nums[i]时 有三种选择来更新当前的连乘记录
/*自己单干：不管前面了，就从现在的 nums[i] 重新开始算。
和前面连着乘：让 nums[i] 乘以之前的 imax。
和前面连着乘：让 nums[i] 乘以之前的 imin。
我们只需要在这三个数里挑出最大的当新的 imax，挑出最小的当新的 imin 就可以了！
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n<=0){
            return 0;
        }
        //不用开dp数组 动态更新ans即可
        //初始化
        int imax = nums[0];
        int imin = nums[0];
        int ans = nums[0];
        for(int i = 1;i<n;i++){
            //关键：当遇到负数是 imax和imin交换
            //因为乘一个负数后原来的最大值会变成最小值 最小值变成最大值
            if(nums[i]<0){
                swap(imax,imin);
            }
            //计算当前(即以nums[i]结尾)的最优解 要么自己单干要么带上之前的积继续
            imax = max(nums[i],imax*nums[i]);
            imin = max(nums[i],imin*nums[i]);
            //即刻更新答案
            ans = max(ans ,imax);
        }
        return ans;
        
    }
};

/*逻辑推演（用 [-2, 3, -4] 走一遍）
初始状态：imax = -2, imin = -2, ans = -2
遇到 3：
它是正数，不交换。
新的 imax = max(3, -2 * 3) = 3 (自己单干更好)
新的 imin = min(3, -2 * 3) = -6 (保留了这个绝版负数！)
ans = max(-2, 3) = 3
遇到 -4：
它是负数！先交换：imax = -6, imin = 3
新的 imax = max(-4, -6 * -4) = 24 (绝地翻盘！)
新的 imin = min(-4, 3 * -4) = -12
ans = max(3, 24) = 24
答案24
*/