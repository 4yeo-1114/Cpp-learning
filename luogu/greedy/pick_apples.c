/* C | greedy: pick apples. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int x;
	int y;
}apple;

int cmp(const void*a,const void*b){
	return (*(apple*)a).y - (*(apple*)b).y;
}
int main(){
	int n,s;
	int a,b;
	scanf("%d %d", &n,&s);
	scanf("%d %d", &a,&b);
	apple *ap = (apple*)malloc(sizeof(apple)*n);
	apple *ap1 = (apple*)malloc(sizeof(apple)*n);
	int j  =0;
	for(int i =0 ;i<n;i++){
		scanf("%d %d", &ap[i].x,&ap[i].y);
		if(ap[i].x<=(a+b)){
			ap1[j].x = ap[i].x;
			ap1[j].y = ap[i].y;
			j++;
		}
	}
	qsort(ap1,j,sizeof(apple),cmp);
	int cnt  = 0;
	for(int i = 0;i<j;i++){
		s -= ap1[i].y;
		if(s>=0){
			cnt++;
		} 
		else break;
	}
	printf("%d", cnt);
	return 0 ; 
}
