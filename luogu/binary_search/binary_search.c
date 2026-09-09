/* C | binary search: binary search. */
#include <stdio.h>
int binary_search(int arr[],int start, int end,int key){
	int ret = -1; // 未搜索到数据返回-1下标
	int mid;
	while(start<end){
		mid = start + (end - start)/2;
		if(arr[mid]<key){
			start = mid+1; //偏小就取右半区间 
		}
		else if(arr[mid]>key){
			end = mid-1;
		}
		else{
			ret = mid;
			break;
		}
	} 
	return ret ;
	 
}
int main(){
	int arr[]={1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(int);
	int r = binary_search(arr,0,n-1,6);
	printf("%d",arr[r]);
	return 0;
	
} 
