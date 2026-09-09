/* C++ | string: thousands separator. */
//#include <bits/stdc++.h>
//#include <algorithm>
//using namespace std;
//int main(){
//	int d;
//	char s[1000000] = {0};
//	scanf("%d", &d);
//	int q = d<0?-d:d;//转成正数
//	int  p = 0,sep = 0;
//	while(q!=0){
//		if(sep == 3){
//		//有了三位 
//		s[p++] = ',';
//		sep = 0;
//	} 
//	sep++;
//	s[p++] = q%10 + '0';
//	q= q/10;	
//} 
//if(d<0)  s[p++] = '-';
//else if(d==0) s[p++] = '0'; // 特殊情况d=0 
//s[p] = 0;//结束
//reverse(s,s+p); //反转
//printf("%s",s); 
//
//}
#include <stdio.h>
#include <algorithm>
using namespace std; 
int main(){
	int n;
	scanf("%d",&n);
	int q = n;
	q = q<0?-q:q;
	int sep = 0;
	char s[10000];
	int p = 0;
	while(q!=0){
		if(sep==3){
			s[p++] = ',';
			sep = 0;
		}
		s[p++] =  q%10+'0';
		q = q/10;
		sep++;
	}
	if(n<0) s[p++] = '-';
	//考虑边界情况 0 
	else if(n==0)  s[p++] = '0';
	s[p] = '\0'; //结束符 
	reverse(s,s+p);//左闭右开 
	printf("%s",s); 
	return 0; 
}
