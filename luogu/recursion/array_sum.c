/* C | recursion: array sum. */
#include <stdio.h>
int array_sum(int arr[],int start, int end){
	// 基准情况 如果只有一个元素
	if(start == end){
		return arr[start];
	} 
	// 递归情况 总和 = 第一个元素 + 剩余元素的和
	return arr[start]+array_sum( arr,  start+1,  end);   //起点要加一！ 
} 
int main(){
	int numbers[]={1,2,3,4,5,6,7,8};
	int n = sizeof(numbers)/sizeof(int);
	int sum = array_sum(numbers,0,n-1);
	printf("%d",sum);
	return 0;
} 
