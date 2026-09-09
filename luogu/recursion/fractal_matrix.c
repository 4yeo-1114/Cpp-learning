/* C | recursion: fractal matrix. */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a[1025][1025];
//不能传矩阵，没法递归 要传坐标 
void px(int n,int l,int p){ //边长 左上角的坐标 
    if(n==2){
    	
    	a[l][p] = 0;
    	return ; //要终止！ 
   } 
	for(int i = l;i<l+n/2;i++){
			for(int j = p;j<p+n/2;j++){
				a[i][j] = 0;
			}
	} 
	if(n>=4){
	  px(n/2,l,p+n/2);
	  px(n/2,l+n/2,p);
	  px(n/2,l+n/2,p+n/2);
	}
		
}
int main(){
	int n;
	scanf("%d",&n);
	int rows = 1;
//	int cols = 1;
	for(int i = 0;i<n;i++){
		rows *= 2;
//		cols *= 2;
	}
//	int **std = (int**)malloc(rows*sizeof(int*)); 
//	for(int i =0;i<rows;i++){
//		std[i] = (int*)malloc(cols*sizeof(int));
//		
//	}
	for(int i = 0;i<rows;i++){
		for(int j = 0;j<rows;j++){
			a[i][j] =  1;
		}
	}
	
//	for(int i= 0;i<rows;i++){
//		free(std[i]);
//	}
	px(rows,0,0);
	for(int i =0 ;i<rows;i++){
		for(int j = 0;j<rows;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n"); 
	} 
//	free(std);
	return 0;
} 
