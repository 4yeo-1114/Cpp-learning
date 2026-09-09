/* C | sorting: merge sort. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 合并两个有序数组的函数 
void merge(int arr[],int left, int mid,int right){
	int i,j,k;
	int n1 = mid - left + 1; //左半部分的大小 
	int n2 = right - mid;
	int *L = (int*)malloc(n1 * sizeof(int));
	int *R = (int*)malloc(n2 * sizeof(int));
	// 拷贝到临时数组里 
	for(int i = 0;i<n1;i++){
		L[i]=arr[left+i];//左 
	} 
	for(int j = 0;j<n2;j++){
		R[j]=arr[mid+1+j]; //右 
	} 
	// 合并临时数组回原数组；
	 i=0;
	 j =0;
	 k =left;
	while(i<n1 && j<n2){ //两边都还有元素时 
		if(L[i]<=R[j]){
			arr[k] =L[i]; //如果左边的元素小把左边的放进原数组， 然后左指针前进。 
			i++; 
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++; //原数组指针要前进 
	} 
	// 拷贝剩余元素
	while(i<n1){//如果左边还有剩余 
		arr[k] = L[i];
		i++;
		k++;
	} 
	while(j<n2){
		arr[k] = R[j];
		j++;
		k++;
	}
	
	free(L);
	free(R);
	
}
// 递归并排序 
void merge_sort(int arr[],int left,int right){
	if(left<right){// 递归终止条件：子数组只有1个元素（left == right）
		//计算中间点
	int mid = left + (right- left) / 2; 
	merge_sort(arr,left,mid);  //递归拆分左半部分 [left, mid]
	merge_sort(arr,mid+1,right); //递归右半边 
	merge(arr,left,mid,right);
	} //合并两部分 
}
// 打印数组
void print_array(int arr[],int size){
	for(int i = 0;i<size;i++) 	printf("%d\n",arr[i]);

} 

int main(){
	int numbers[] = {23,543,457,73,64,1,6,};
	int n =sizeof(numbers)/sizeof(int);
	merge_sort(numbers,0,n-1);
	print_array(numbers,n);
	return 0;
}
