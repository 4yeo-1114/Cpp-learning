/* C | two pointers: longest word. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main(){
	char s[100000];
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")] = ' ';
	int len = strlen(s);
	int l;
	l = 0;
	int max, min;
	max = -1;
	min = 10000;
	int curlen;
	char mx[100] = "";
	char mi[100] = "";
	for(int i = 0;i<len;i++){
		if(s[i] == ' '){
			curlen = i  - l;
			if(curlen>0){ //避免连续两个空格 
				if(curlen>max){
				max  = curlen;
				strncpy(mx,s+l,curlen);
				//用strncpy复制单词必须手动添加结束符 
				mx[curlen]  = ' \0';
				
			}
			if(curlen<min){
				min   =curlen;
				strncpy(mi,s+l,curlen);
				mi[curlen]  = ' \0';
			}
		}
		//操作完后 l就指向下个单词的头 
			l = i+1;
			
		}
		
	}
	printf("%s\n%s",mx,mi);
	return 0;
} 
