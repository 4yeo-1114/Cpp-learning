/* C | binary search: lookup numbers. */
#include <stdio.h>
#include <stdlib.h>
int search(int arr[],int key,int start,int end){
	int ret= -1;
	while(start<=end){ //这里可以等于 在1 3 3里找3 就可以输出2 
		int mid = start +(end-start)/2;
		if(arr[mid] == key){
			ret = mid +1; //要的是位置 下标加一1 
			end = mid -1; //还没结束，继续向左找更早的！
				} 
		else if(arr[mid]<key){
			start = mid+1;
		}
		else if(arr[mid]>key){
			end = mid-1;
		}
		
	
	}
	return ret;
}
int main(){
	int n,m;
    int num[1000000];
	int key[1000000]; 
	scanf("%d %d\n",&n,&m);
	for(int i = 0;i<n;i++){
		scanf("%d", &num[i]);
	}
	for(int i = 0;i<m;i++){
		scanf("%d",&key[i]);
	}
	for(int i = 0;i<m;i++){
		int result = search(num,key[i],0,n-1);
		printf("%d ",result);
//		if (i != m-1){
//			printf(" "); //最后一个数无空格！ 
//		}
	}
	return 0;
}
