/* C | greedy: fractional knapsack. */

#include <stdio.h>
#include <stdlib.h>
struct gold{
	int weight;
	int value;
	double pervalue;
};
void swap(struct gold*a, struct gold*b){
	struct gold tem  = *a;
	*a = *b;
	*b = tem; 
}
//排序函数 
void px(struct gold arr[],int n){
	for(int i = 0; i<n-1;i++){ //冒泡排序n个数进行n-1轮 
		for(int j = 0;j<n-i-1;j++){
			if( arr[j].pervalue < arr[j+1].pervalue )
			swap(&arr[j], &arr[j+1]);// 比如第一轮就把最小的数推到最后，第二轮以此类推 
		}
	}
}

int main(){
	int n,t;
	scanf("%d %d",&n,&t);
	struct gold *g = (struct gold*)malloc(n*sizeof(struct gold));
	for(int i= 0 ;i<n;i++){
		scanf("%d %d",&g[i].weight, &g[i].value);
		g[i].pervalue = (double)g[i].value/g[i].weight; 
	}
	px(g,n);
	int  qwq = 0;
	double value = 0;
	for(int i = 0 ;i<n;i++){
		if(g[i].weight <= t-qwq){
			value += (double)g[i].value;
			qwq += g[i].weight;
		}
		else{
			value += g[i].pervalue*(t-qwq);
			break;
		}
		
	}
	printf("%.2f", value);
	free(g);
	return 0;
} 
