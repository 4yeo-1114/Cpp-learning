/* C++ | binary search: cubic roots. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
double  a,b,c,d;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
double by(double l,double r){
	while(r - l > 1e-5){// 控制区间精度，确保小数点后2位准确
    double 	mid = l+(r-l)/2;
	if(fabs(f(mid))<1e-7) return mid;
	if(f(mid)*f(l)<0){
		r = mid;
	}
	else{
		l = mid;
	}	
}	
    return (r+l)/2;// 区间足够小，返回中点
}
int main(){
	scanf("%lf %lf %lf %lf", &a,&b,&c,&d);
	double  i;
	double j;
	double  z;
	double x1;
	double x2;
	double x3;
	for(i = -100;i<=99;i++){
		if(fabs(f(i))<1e-7) {
			x1 = i;break;
		}
		if(f(i)*f(i+1)<0){
			x1 = by(i,i+1); 
			break;
		} 
	}
	for(j = i+1;j<=99;j++){
			if(fabs(f(j))<1e-7) {
			x2 = j;break;
		}
		if(f(j)*f(j+1)<0){
			x2 = by(j,j+1);
			break;
		} 
	}
		for(z = j+1;z<=99;z++){
			if(fabs(f(z))<1e-7) {
			x3 = z;break;
		}
		if(f(z)*f(z+1)<0){
			x3 = by(z,z+1);
			break;
		} 
	}
	printf("%.2f %.2f %.2f",x1,x2,x3);
	return 0;
} 

//暴力枚举
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
   double a,b,c,d;
   scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
   for(double i=-100;i<=100;i+=0.001)
   {
      double j=i+0.001;//精度就可以保持在两位小数 
      double y1=a*i*i*i+b*i*i+c*i+d;
      double y2=a*j*j*j+b*j*j+c*j+d;
      if(y1>=0&&y2<=0||y1<=0&&y2>=0)
      {
         double x=(i+j)/2;
         printf("%.2lf ",x);
      }
   }
}
 
