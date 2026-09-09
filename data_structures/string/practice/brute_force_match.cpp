/* C++ | string: brute force match. */
#include <stdio.h>
#include <stdlib.h> 
typedef struct string{
	char *data;
	int len;
}String;

String * initString(){
	String *s = (String*)malloc(sizeof(String));
	s->data = NULL;
	s->len = 0;
	return s;
}

void stringAssign(String*s ,char *data){
	if(s->data){
		free(s->data);
	}
	int len  = 0;
	char *temp = data;
	while(*temp){
		len++;
		temp++;
	}
	if(len==0){
		s->data = NULL;
		s->len = 0;
	} 
	else{
		temp = data;
		s->len  = len;
		s->data = (char*)malloc(sizeof(char)*(len+1));
		for(int i = 0;i<len;i++,temp++){
			s->data[i] = *temp;
		}
	}
}
void printString(String *s){
	for(int i = 0;i<s->len;i++){
		printf(i==0? "%c":"-> %c",s->data[i]);
	}
	printf("\n");
	return ;
}
void forceMatch(String *master,String *sub){
	int i = 0;
	int j = 0;
	while(i<master->len && j<sub->len){
		if(master->data[i] == sub->data[j]){
			i++;
			j++;
		}
		else{
			i = i - j + 1;//回溯 减去已经移动的 
			j = 0;//子串重新开始匹配 	
		}	 
	}//出去循环有两种情况 要么就是i到头了j没到头（失败） j到头了（成功） 
	if(j == sub->len){
		printf("force match success\n"); 
}
	else{
		printf("force match fail\n");
	}
	
}
int main(){
	String *s1 = initString();
	string *s2 = initString(); 
	stringAssign(s1,"Hello");
	stringAssign(s2,"He");
	printString(s1);
	printString(s2);
	forceMatch(s1,s2);
	return 0;
}
