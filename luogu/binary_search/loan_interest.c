/* C | binary search: loan interest. */
#include <stdio.h>
#include <stdlib.h>
int main(){
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	
	double l,r,mid;
	l = 0;
	r = 1000;
	mid = 0;
	while(l+0.0001<r){
		mid = l+(r-l)/2;
		// w 表示未还的钱 模拟还钱过程 
		double w  = a;
		for(int i = 0;i<c;i++){
			w = w - b + w*(mid/100);}
			if(w>0.001){
				//钱没换完 利息太大了
				r = mid; 
			} 
			else{
				l = mid;
			}

		}
	printf("%0.1f",mid);
	return  0;
} 
	
