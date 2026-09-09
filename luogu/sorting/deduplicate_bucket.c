/* C | sorting: deduplicate bucket. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int compare_int(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}
int main(){
	int n;
	scanf("%d", &n);
    int rand[n];
    for(int i = 0;i<n;i++){
     	scanf("%d", &rand[i]);
	 }
	 bool isAppeared[1001] = {0}; // 1-1001这些数先都初始化为未出现 
	 int same = 0;
	 int unique[100];
	 int m = 0; //搞一个新的数组来存储，同时要搞个动态的下标！-m 
	 for(int i= 0;i<n;i++){
	 if(!isAppeared[rand[i]]){ //如果没出现 
	      unique[m++] = rand[i]; //m++ == m;
	 }
	 isAppeared[rand[i]] = 1; //无论如何 都标记为出现； 
}
   
    qsort(unique, m ,sizeof(int),compare_int);
    printf("%d\n",m);
    for(int i = 0;i<m;i++){
    	printf("%d ",unique[i]);
	}
}
