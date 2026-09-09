/* C | dp: catalan stack sequences. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int n;
	scanf("%d", &n);
	long long dp[20][20];
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=n;j++){
			if(!i) dp[i][j] = 1;//初始条件 相当与点菜的f[0]=1; 没有数可以入栈也算一种情况 
			else if(!j) dp[i][j] = dp[i-1][j+1];
			else dp[i][j] = dp[i-1][j+1] + dp[i][j-1]; // 结果等于push后的结果+pop后的结果 
		}
	}
	printf("%d",dp[n][0]);
	return 0;
} 
//第一次重写 
int mian(){
	int n;
	scanf("%d",&n);
	long long dp[20][20];
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<n;j++){
			if(i==0) dp[i][j] = 1;
			else if(j==0) dp[i][j] = dp[i-1][j+1];
			else dp[i][j] = dp[i][j-1] + dp[i-1][j+1];
		}
	}
	printf("%lld",dp[n][0]);
	return 0;
} 
//用递归写 
#define MAXN 30;
long long memo[MAXN][MAXN];//记忆化数组，储存已计算的状态
//递归函数 
long long dg(int x,int y,int n){
	// 非法状态返回 0
	if(x<0 || y<0||y>n){
		return 0;
	} 
	// 终止状态返回1
	if(x==0 && y==0){
		return 1;
	} 
	//若已计算过该结果 直接返回结果 
	if(memo[x][y] != -1){
		return memo[x][y]; 
	}
	//状态 = push操作加pop操作
	long long res = 0;
	if(x>0){//可push 
		res += dg(x-1,y+1,n);
	} 
	if(y>0){
		res += dg(x,y-1,n);
	} 
	memo[x][y] = res; //记录结果 
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	// 初始化记忆数组
	memset(memo,-1,sizeof(memo));
	long long ans = dg(n,0,n);
	printf("%lld",ans);
	return 0; 
}
