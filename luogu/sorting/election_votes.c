/* C | sorting: election votes. */
#include <stdio.h>
#include <stdlib.h>
int compare_int(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
    int v[m];
	for(int i = 0;i<m;i++){
		scanf("%d", &v[i]);
		
	}
	qsort(v,m,sizeof(int),compare_int);
	for(int i = 0; i<m;i++){
		printf("%d ",v[i]);
	}
	return 0 ;
	
	
} 
