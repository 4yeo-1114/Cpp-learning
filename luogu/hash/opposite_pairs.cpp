/* C++ | hash: opposite pairs. */
#include <stdio.h> 
#include <string.h>
const int MAXN = 100000; //元素的界 
int solve(int n, int a[]){
	bool met[MAXN * 2 +1];//创建一个能装下-MAXN到MAXN的桶 
	memset(met, 0, sizeof(met));
	int ants = 0;
	for(int i = 0; i<n;++i){
		if(met[MAXN-a[i]]) ants++;
		met[MAXN + a[i]] = 1;  //无论如何，都要把当前元素放桶里面！ 
	} 
	printf("%d",ants);
	return ants; 
}
int main(){
	int a[]={1,3,6,4,8,-8,-3,-1,6,64,-4};
	int n = sizeof(a)/sizeof(int);
	solve(n,a);
	return 0;
}
