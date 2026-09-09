/* C | sorting: insertion sort. */
#include <stdio.h>
#include <stdlib.h>
//插入排序
void insertionSort(int arr[],int n){
	//从第二个元素开始，向前插入到合适的位置
	for(int i =1;i<n;i++){
		//把当前要插的数存起来
		int key = arr[i];
		//j指向当前数前一个位置 
		int j = i-1; 
		//如果前面的数比key大，就往后挪
		while(j>=0&&arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		} 
		arr[j+1] = key;
	} 
} 
