/* C | binary search: difference pairs. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX  (1 << 30)
//找小于等于a[i]-C的数的个数的函数
// 左闭右开！！ 
int find1(int arr[],int key,int r){
	int l  = 0;
	int mid;
	while(l+1<r){
		mid = l +(r-l)/2;
		if(arr[mid]<=key){
			l = mid;
		}
		else r = mid;
	}
	return l;
}
//找小于a[i]-C的数的个数的函数
int find2(int arr[],int key,int r){
	int l= 0;
	int mid;
	while(l+1<r){
		mid = l +(r-l)/2;
		if(arr[mid]<key){
			l = mid;
		}
		else r = mid;
	}
	return l;
}
int compare(const void *a, const void *b){
	return *(int*)a  - *(int*)b;
}
int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	 int *num = (int *)malloc(n * sizeof(int)); 
    if (num == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
	for(int i = 0;i<n;i++){
		scanf("%d", &num[i]);
	}
	qsort(num,n,sizeof(int),compare);
	int ans = 0;
	for(int i = 0;i<n;i++){
		
		ans += find1(num,num[i]+c,n) - find2(num,num[i]+c,n); //这样一减就得出了等于a+c的数（不止一个） 
	}
	printf("%d",ans);
	return 0;
} 
