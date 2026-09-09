/* C | search: select numbers. */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int  n,k;
int  ans = 0;
int  num[25];
bool isprime(int x){
	if(x == 1) return false;
	if(x == 2) return true;
	if(x%2==0) return false;
	for(int i = 3;i*i<=x;i=i+2){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
void dfs(int now,int s,int aid){
	// 现在已经选了 now 个数，当前总和为 s
	// sid 是这次选数的起始下标，即我们从 a[sid] 开始选数枚举
	if(now == k){
		if(isprime(s)){
			ans++;
			return ;
		}
	}
	//已经选了 now次  这次选完后，还有 k - now - 1 个数要选择
	//所以枚举的终点是 n-(k-now-1) 
	for(int i = aid; i <= n-k+now+1;i++){
		dfs(now+1,s+num[i],i+1);//选了i位置的数 下次选只能从i+1开始 
	}
	return ;
}
int main(){
	scanf("%d %d", &n,&k);
	for(int i = 1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	dfs(0,0,1);
	printf("%d",ans);
	return 0;
}
//不降原则不是说数字一定要从高到低，是下标！选了一个位置的，下一个选就只能选后面的数
//这样可以避免出现排列重复 
