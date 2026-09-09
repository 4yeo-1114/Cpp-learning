/* C | dp: number count. */
#include <stdio.h>
递归 
long long dg(int n){//n就是最后一个数 
	if(n==1) return 1; 
	long long res = 1;
	int i = n/2;
	for(;i>=1;i--){
		res += dg(i);
	}
	return res;
	
	
} 
int main(){
	int n;
	scanf("%d",&n);
	long long  ans = dg(n);
	printf("%lld",ans);
	return 0;
} 
dp
int main(){
	int n;
	scanf("%d",&n);
	long long dp[1001]; 
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3;i<=n;i++ ){
		dp[i] = 1; 
		for(int j = i/2;j>=1;j--){
			dp[i] += dp[j];
		}
		
	}
	printf("%lld",dp[n]);
	return 0;
} 
