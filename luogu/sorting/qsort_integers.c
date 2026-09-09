/* C | sorting: qsort integers. */
#include <stdio.h>
#include <stdlib.h>
int compare_ints(const void*a, const void*b){
	const int *arg1 =(const int *)a;
	const int *arg2 =(const int *)b;
	return *arg2-*arg1; //右减左降序排序 
} 
int compare_ints(const void*a, const void*b){
	return *(int*)b - *(int*)a; 
}
int main(){
	int arr[]={5,3,6,3,74,1,47};
	int n = sizeof(arr)/sizeof(arr[0]);
	qsort(arr,n,sizeof(int),compare_ints);// 数组，元素个数，大小，函数 
	for(int i=0;i<n;i++){
		printf("%d  ",arr[i]);
		
	} 
	return 0;
}
