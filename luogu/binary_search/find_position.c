/* C | binary search: find position. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int by(int arry[],int key,int l,int r){
	while(l<r){
	int mid = l + (r-l)/2;
	if(arry[mid] == key) {
	return mid+1;
	break;	
	}
	else if(arry[mid]>key){
		r  = mid;
	}
	else {
		l =  mid+1 ;	
	}
}
	
	return 0;
}
int cmp(const void *a,void const *b){
	return *(int*)a  - *(int*)b;
}
int main(){
	int n,k;
	while(scanf("%d", &n)!=EOF){
	int *a = (int*)malloc(n*sizeof(int));
	for(int i= 0;i<n;i++){
		scanf("%d", &a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	scanf("%d", &k);
	int *b = (int*)malloc(n*sizeof(int));
	for(int i= 0;i<k;i++){
		scanf("%d", &b[i]);
	}
	for(int i = 0;i<n;i++){
		printf("%d", a[i]);
		if(i!=n-1) printf(" ");
	}
	printf("\n");
	for(int i = 0;i<k;i++){
	   int ans = 0;
	   ans = by(a,b[i],0,n);
	   printf("%d",ans);
	   if(i != k-1) printf(" ");	
	}	
	printf("\n");	
}
	
	return 0;
}


int by(int arr[],int left,int right,int key){
	while(left<right){
		int mid = left+(right-left)/2;
		if(arr[mid] == key){
			return mid +1;
		}
	    else if(arr[mid]>key){
	    	right  = mid;
		}	
	    else{
	    	left = mid+1;
		}
	}
	return -1;
}
int cmp(const void*a, const void *b){
	return *(int*)a - *(int*)b;
}
int main(){
	int n;
	scanf("%d", &n);
	int *a  = (int*)malloc(sizeof(int)*n);
	for(int i = 0 ;i<n;i++){
		scanf("%d", &a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	int m ; 
	scanf("%d",&m);
	int  *b  = (int*)malloc(sizeof(int)*n);
	for(int i = 0;i<m;i++){
		scanf("%d", &b[i]);
	}
	for(int  i  = 0;i<n;i++){
		printf("%d", a[i]);
	}
	printf("\n");
	for(int i = 0;i<m;i++){
		int ans = by(a,0,n,b[i]);
		printf("%d ",ans);
	}
}
