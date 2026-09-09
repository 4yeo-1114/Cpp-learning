/* C | string matching: dna match. */
#include <stdio.h>
#include <string.h>
#define MAX 10000 // 定义dna最大长度

// BF算法实现模式匹配， 返回匹配位置
int BFIndex(char *s, char *t){
	int i = 1 ; 
	int j = 1;
	int lenS = strlen(s+1) ; //主串长 从下标1开始
	int lenT = strlen(t+1) ;
	while (i<=lenS && j<=lenT){
		if(s[i] == t[j]){
			i++;
			j++;
		}
		else{
			i = i - j + 2;
			j =1;
		}
		if(j>lenT){ // 匹配成功了
		   return i - lenT; 
			
		}
		return 0 ;
	}
} 

int main(){
	
}
