#include <stdio.h>

#define MAXN 3000

int max(int a,int b){
    return a>b?a:b;
}

int lengthOfLIS(int *nums,int numsSize){
    if(numsSize==0) return 0;
    int dp[MAXN];
    int max_len = 1;

    for(int i = 0;i<numsSize;i++){
        dp[i] = 1;
        for(int j = 0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
        if(dp[i]>max_len){
            max_len = dp[i];
        }
    }

    return max_len;

}


int main(){
    int nums[MAXN];
    int n = 0;

    while(scanf("%d",&nums[n])==1){
        n++;
        char c  = getchar();
        if(c=='\n'|| c==EOF){
            break;
        }
    }
    int ans = lengthOfLIS(nums,n);
    printf("%d\n",ans);
    return 0;
}



//贪心做法

#include <stdio.h>

#define MAXN 3000

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // d[k] 表示目前长度为 k 的递增子序列中，末尾元素的最小值
    // 下标从 1 开始，所以分配 numsSize + 1
    int d[MAXN + 1];
    int len = 1;
    d[len] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > d[len]) {
            // 当前数大于末尾，直接延长最长递增子序列
            d[++len] = nums[i];
        } else {
            // 二分查找 d[1...len] 中最后一个小于 nums[i] 的位置
            int l = 1, r = len, pos = 0;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (d[mid] < nums[i]) {
                    pos = mid;
                    l = mid + 1; // 尝试找更靠右的小于值
                } else {
                    r = mid - 1;
                }
            }
            // 贪心替换：将 nums[i] 放入 pos + 1 的位置，减小该长度结尾的数值
            d[pos + 1] = nums[i];
        }
    }

    return len;
}

int main() {
    int nums[MAXN];
    int n = 0;

    // 读取一行空格分隔的整数输入
    while (scanf("%d", &nums[n]) == 1) {
        n++;
        char c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
    }

    printf("%d\n", lengthOfLIS(nums, n));
    return 0;
}