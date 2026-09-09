/* C | dp: big integer stairs. */
#include <stdio.h>   
#include <string.h>  

#define MAX_DIGIT 10000 
 // 宏定义：最大数字位数（10000足够存n=5000的结果）
 // 大数加法函数 （高精度加法） 
 void add(int a[], int b[], int res[]) {
    memset(res, 0, sizeof(int) * MAX_DIGIT);  // 先把结果数组res清零
    int carry = 0;  // 进位标志（加法中超过10的部分要进位）
    for (int i = 0; i < MAX_DIGIT; i++) {
        res[i] = a[i] + b[i] + carry;  // 当前位 = a的第i位 + b的第i位 + 上一位的进位
        carry = res[i] / 10;  // 计算新的进位（比如15/10=1，进位1）
        res[i] %= 10;  // 只保留当前位的个位数（比如15%10=5）
    }
}
//数步数的函数
void solve(int n) {
    int dp0[MAX_DIGIT] = {1};  // 存储f(0)的结果（初始为1，即数组[1, 0, 0, ...]）
    int dp1[MAX_DIGIT] = {1};  // 存储f(1)的结果（初始为1）
    int dp2[MAX_DIGIT] = {0};  // 临时存储f(i)的结果（用于中间计算）
    
    // 从i=2开始计算，直到i=n q其实就是斐波那契数列 
    for (int i = 2; i <= n; i++) {
        add(dp1, dp0, dp2);  // 计算f(i) = f(i-1) + f(i-2)，结果存在dp2中
        memcpy(dp0, dp1, sizeof(int) * MAX_DIGIT);  // 把f(i-1)的值传给dp0（下次循环中作为f(i-2)）
        memcpy(dp1, dp2, sizeof(int) * MAX_DIGIT);  // 把f(i)的值传给dp1（下次循环中作为f(i-1)）
    }
    //因为最后把dp2传给dp1了 所以输出dp1即可 
    // 输出结果：从最高位开始找第一个非0数字，然后依次打印
    int i = MAX_DIGIT - 1;  // 从数组最后一个元素（最高位方向）开始找
    while (i >= 0 && dp1[i] == 0) i--;  // 跳过前面的0（比如结果是123，数组后面都是0，找到第一个非0位）
    for (; i >= 0; i--) {  // 从最高位非0数字开始，依次打印到个位（下标0）
        printf("%d", dp1[i]);
    }
    printf("\n");
} 
int main() {
    int n;
    scanf("%d", &n);  // 输入台阶数n 
    solve(n);  
    return 0;
}

//void solve(int n){
//	int dp0[MAX]  ={1};
//	int dp1[MAX]  ={1};
//	int dp2[MAX]  ={0};
//	for(int i = 2;i<=n;i++){
//		add(dp0,dp1,dp2);
//		memcpy(dp0,dp1,MAX*sizeof(int));
//		memcpy(dp1,dp2,MAX*sizeof(int));
//	}
//	int i =MAX-1;
//	while(i>=0&&dp2[i]==0) i--;
//	for(;i>=0;i--){
//		printf("%d",dp2[i]);
//	}
//	printf("\n");
//	
//}
//
//void add(int a[], int b[],int c[]){
//	memset(c,0,sizeof(int)*MAX);
//	int carry = 0;
//	for(int i = 0;i<MAX;i++){
//		c[i] = a[i] + b[i] + carry;
//		carry = c[i]/10;
//		c[i] = c[i]%10;
//	} 
//}
