/* C | sorting: quickselect. */
#include <stdio.h>
#include <stdlib.h>
// 交换两个整数的值 
void swap(long long *a, long long *b){
	long long temp = *a;
	*a  = *b;
	*b  =temp;
} 
//分区函数 返回枢轴的最终位置
int partition(long long arr[],int left, int right){
	long long pivot = arr[right]; // 选择最右边的数作为枢轴；
	int i = left - 1; // i记录小于等于枢轴的元素的右边界 
	for(int j = left;j<right;j++){
		if(arr[j]<=pivot){
			i++; // 到最后就有i+1个数在左边 
			swap(&arr[i],&arr[j]);
		}
	} 
	swap(&arr[i+1], &arr[right]);// 把枢轴放到中间 
	return i+1; //前面有多少个数比他小 他就是第几小 或者说下标就是第k小 
} 
// 快速选择算法， 寻找出数组中第k小的元素
long long quickSelect(long long arr[], int left, int right, int k){
	if(left == right ){
		return arr[left];
	}
	int pos = partition(arr,left, right);
	if(pos == k){//如果 pos == k，则枢轴元素就是第 k 小的元素。
		return arr[pos]; // 找到第k小的元素了 
	}
	else if (pos > k) {// 如果 pos > k，则在左子数组中寻找第 k 小的元素。
		return quickSelect(arr, left,pos-1,k); //在左边继续找 
	}
	else if(pos<k){// 如果 pos < k，则在右子数组中寻找第 k - pos - 1 小的元素
		return quickSelect(arr,pos+1,right,k);
	} 
} 
int main(){
	int n,k;
	scanf("%d %d",&n, &k);
	long long *arr = (long long *)malloc(n*sizeof(long long));
	for(int i = 0;i<n;i++){
		scanf("%lld", &arr[i]);
	}
	long long result  = quickSelect(arr, 0,n-1,k);
	printf("%lld\n",result);
	return 0;
	
}
//方法思路
//
//1. 分治思想：快速选择算法的核心是类似快速排序的分区（Partition）操作。
//选择一个枢轴元素（pivot），将数组分为两部分，
//一部分是小于等于枢轴的元素，
//另一部分是大于枢轴的元素。
//
//2. 分区操作：通过分区操作确定枢轴元素的最终位置 pos。
//
//3. 递归或直接判断：比较枢轴位置 pos 和目标位置 k：

long long position(int arry[],int left,int right){
	int priot = arry[right];
	int i = -1;
	for(int j = left;j<=right;j++){
		if(arry[j]<=priot){
			i++;
			swap(&arry[i],&arry[j]);
		}
	}
	swap(&arry[i+1],&arry[right]);
	return i+1;
}
long long select(int arry[],int left,int right,int key){
	if(left==right) return arry[left];
	long long pos =  position(arry,left,right);
	if(pos == key) return arry[pos];
	else if(pos > key) {
		 return select(arry,left,pos-1,key);
	}
	else{
		return select(arry,pos+1,right,key);
	}
}




