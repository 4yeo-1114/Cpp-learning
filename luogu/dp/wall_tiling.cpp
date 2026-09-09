/* C++ | dp: wall tiling. */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX  4
//int dp[14500][MAX];
//void mutiply2(int a[]){
//	int carry  = 0;
//	for(int i = 0;i<MAX;i++){
//		int temp = a[i]*2 + carry;
//		a[i] = temp%10;
//		carry = temp/10;
//		
//	}	
//}
//void plus(int a[], int b[],int c[]){
//	int carry = 0;
//	for(int i = 0;i<MAX;i++){
//		int temp = a[i] +b[i] +carry;
//		c[i] = temp%10;
//		carry = temp/10;
//		
//	}
//	
//}
//int main(){
//	int n;
//	scanf("%d",&n);
//	dp[1][0] = 1;
//	dp[2][0] = 2;
//	dp[3][0] = 5;
//	for(int i = 4;i<=n;i++){
//		int temp2[MAX];
//		for(int j = 0;j<MAX;j++){
//			temp2[j] = dp[i-1][j];
//		}
//		mutiply2(temp2);
//		plus(temp2,dp[i-3],dp[i]);
//	}
//	int start = MAX - 1;
//    while (start >= 0 && dp[n][start] == 0) {
//        start--;  // 跳过前导0
//    }
//    if (start < 0) {
//        printf("0");  // 结果为0的特殊情况
//    } else {
//        for (int i = start; i >= 0; i--) {
//            printf("%d", dp[n][i]);
//        }
//    }
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int main(){
	int n;
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    dp[4] = 11;
    for(int i = 4;i<=n;i++){
        dp[i] = (dp[i-1]*2)%10000 + (dp[i-3])%10000;
        dp[i] %= 10000;
    }
    printf("%d",dp[n]);
    return 0;
}
// 正解
#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int g[1000005];
int mod  = 10000;
int main(){
	int n;
	cin>>n;
	f[0] = 1;
	f[1] = 1;
	f[2] = 1;
	f[3] = 5;
	f[4] = 11;
	g[0] = 0;
	g[1] = 1;
	for(int i = 4;i<=n;i++){
		f[i] = ((f[i-1])%mod + (f[i-2])%mod + (2*g[i-2])%mod)%mod;
		g[i] = (g[i-1] + f[i-1])%mod;
	}
	cout<<f[n]<<endl;
	return 0;
} 
