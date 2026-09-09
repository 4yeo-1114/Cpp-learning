/* C | string: kmp. */
#include <stdio.h>
#include <stdlib.h>
typedef struct String{
 	int len;
 	char *data;
}String;
 
String* initString(){
	String *s = (String*)malloc(sizeof(String));
	s->data = NULL;
	s->len = 0;
	return s;
} 

void stringAssign(String *s,char *data){
	if(s->data){
		free(s->data);
	}
	int len = 0;
	char *temp = data;
	while(*temp!='\0'){
		len++;
		temp++;
		
	}
	if(len==0){
	s->data = NULL;
	s->len = 0;
	}
	else{
		temp  = data;
		s->len = len;
		s->data = (char*)malloc(sizeof(char)*(len+1));
		for(int i = 0;i<len;i++){
			s->data[i] = *temp;
			temp++;
		} 
	}
	s->data[len] = '\0';
}
int* getNext(String *s){
	int *next = (int*)malloc(sizeof(int)*s->len);
	int i = 0;//索引从0开始 
	int j = -1;//当前的串的最大公共前后缀-1（不包括索引）
	next[i] = j;
	while(i < s->len-1){
		if(j==-1){//先处理j==-1的情况 
			i++;
			j++;
			next[i] = j; 
		}
		 else if(s->data[i] == s->data[j]){ // 再比较
            i++;
            j++;
            next[i] = j;
        } 
		else{
			j = next[j];//把j往前推 写j--也一样 
		}
	} 
	return next;//next是公共缀加一 
}

void printNext(int* next,int len){
	for(int i = 0;i<len;i++){
		printf(i==0?"%d":"-> %d",next[i]);
	}
	printf("\n");
}
void printString(String *s){
	for(int i = 0;i<s->len;i++){
		printf(i==0?"%c":"->%c ",s->data[i]);
	}
	printf("\n");
}
void kmpMatch(String* master,String *sub,int  *next){
	int i = 0;
	int j = 0;
	while(i<master->len && j< sub->len){
		if (j==-1){//先处理j==-1的情况 
			i++;
			j++;
		}
		else if(master->data[i] == sub->data[j]){
			i++;
			j++;
		}
		else{ 
			j = next[j];
		}
	}
if(j == sub->len){
		printf("force match success\n"); 
}
	else{
		printf("force match fail\n");
	}
	
} 
int main(){
	String *s = initString();
	String *s1 = initString(); 
	stringAssign(s,"ABABA");
	stringAssign(s1,"ABA");
	printString(s);
	printString(s1);
	int *next  = getNext(s1);
	printNext(next,s1->len);
	kmpMatch(s,s1,next);
	return 0;
	free(s);
	free(s->data);
	free(next); 
}
