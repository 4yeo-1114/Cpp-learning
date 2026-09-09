/* C | binary search: river stones. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//如果题目规定了有“最大值最小”或者“最小值最大”的东西，
//那么这个东西应该就满足二分答案的有界性和单调性。
int d,n,m;
int l,r;
int ans;
int stone[50010];
bool judge(int mid){
	int cnt = 0 ;
	//for写不出就写while 
	int now = 0; //当前在哪个石头上 
	int i = 0; //下一块石头的位置
	while(i<n+1){
		i++;
		if((stone[i] - stone[now]) < mid){
			cnt++;
		}
		else{
			now  = i ;
		}
	} 
	
	if(cnt>m) return false;
	else return true; 
}
int main(){
	scanf("%d %d %d", &d,&n,&m);
	stone[0] = 0;
	for(int i = 1;i<=n;i++){
		scanf("%d", &stone[i]);
	}
	stone[n+1] = d;
	l = 1;
	r = d;
	//左闭右闭 
	while(l<=r){
		int mid = l+(r-l)/2;
		if(judge(mid)){
			ans  = mid;
			l = mid +1;
		}
		else{
			r  = mid-1;
		} 
	}
	printf("%d", ans);
	return  0 ;
} 
