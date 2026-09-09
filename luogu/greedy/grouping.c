/* C | greedy: grouping. */
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)a - *(int*)b; 
}
int main(){
	int n;
	scanf("%d", &n);
	int *num = (int*)malloc(sizeof(int)*n);
	for(int  i = 0;i<n;i++){
		scanf("%d", &num[i]);
	}
	qsort(num,n,sizeof(int),cmp);
	int group_size =1; 
	for(int i = 0;i<=n-2;i++){
		if(num[i+1] - num[i]!=1){
		group_size ++;
		}
	} 
	int current = 1;
	int current_group = 0;
	int *ans = (int*)malloc(sizeof(int)*group_size);
	for(int i = 1;i<n;i++){
		if(num[i] - num[i-1]==1){
			current ++;
		}
		else{
			ans[current_group++] = current;
			current = 1; 
		}
	}
	ans[current_group++]  = current;
	qsort(ans,group_size,sizeof(int),cmp);
	printf("%d",ans[0]);
	return 0;
	
} 
