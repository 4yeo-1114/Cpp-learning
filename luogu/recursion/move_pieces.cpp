/* C++ | recursion: move pieces. */
#include <iostream>
#include <cstdio>
using namespace std;
int n;
char ch[11110];
void swap (char *a,char *b){//交换函数 
	char temp = *a;
	*a = *b;
	*b = temp;
} 
void output(){//输出函数 
	for(int i = 0;i<2*n+2;i++){
	  putchar(ch[i]);
	}
	putchar('\n');
}
void movechess(int start, int end)
{//移动棋子
    swap(&ch[start], &ch[end]);
    swap(&ch[start + 1], &ch[end + 1]);
    output();//把输出也写到里面！ 
}
//打表 
string out[4] = {"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};
int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		ch[i]  = 'o';
	} 
	for(int i= n;i<2*n;i++){
		ch[i] = '*';
	}
	ch[2*n] = '-';
	ch[2*n+1] = '-';//初始化 
	int len =  n;
	output();//输出一开始的情况 
	while(1){
		movechess(len-1,2*len);
		if(len==4){//后面4个规律不一样 直接打表 
			break;
		}
		movechess(len-1,2*len-2);
		len--;
	}
	string ss;
	for(int i =0;i<n-4;i++){
		ss += "o*"; 
	}
	for(int i = 0;i<4;i++){
		cout<<out[i]<<ss<<endl;
	}
	return 0;
}
