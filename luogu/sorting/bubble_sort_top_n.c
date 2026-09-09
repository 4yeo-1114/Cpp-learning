/* C | sorting: bubble sort top n. */
#include <stdio.h>
#include <stdlib.h>
struct score{
	int chi;
	int math;
	int eng;
	int grade;
	int num;
}score[500];

void swap(struct score*a, struct score*b){
	struct score tem  = *a;
	*a = *b;
	*b = tem; 
}


//排序函数 
void px(struct score arr[],int n){
	for(int i = 0; i<n-1;i++){ //冒泡排序n个数进行n-1轮 
		for(int j = 0;j<n-i-1;j++){
			if(arr[j].grade < arr[j+1].grade|| 
			(arr[j].grade == arr[j+1].grade && arr[j].chi<arr[j+1].chi) ||
			(arr[j].grade == arr[j+1].grade && arr[j].chi == arr[j+1].chi && arr[j].num>arr[j+1].num)   )
			swap(&arr[j], &arr[j+1]);// 比如第一轮就把最小的数推到最后，第二轮以此类推 
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n;i++){
		scanf("%d %d %d\n",&score[i].chi,&score[i].math,&score[i].eng);
		score[i].num = i + 1;
		score[i].grade = score[i].chi+score[i].math+score[i].eng;
	}
	px(score,n); 
	int count = (n<5)?n:5; // 如果n小于5就输出前n个 
	for(int j = 0;j<count;j++){
		printf("%d %d\n", score[j].num,score[j].grade);
	}
	return 0;
}

//冒泡逻辑：
//外层循环 for (int i = 0; i < n - 1; i++)
//作用：控制冒泡排序的“轮数”。
//逻辑：对于 n 个元素，最多需要进行 n-1 轮比较
//（每轮会将当前未排序部分的最大元素“冒泡”到末尾）。
//例如，当 n=5 时，外层循环会执行 4 轮，
//每轮分别将第 1、2、3、4 大的元素依次放到正确位置。
//内层循环 for (int j = 0; j < n - i - 1; j++)
//作用：在每一轮中，逐个比较相邻元素并交换，实现“冒泡”过程。 
