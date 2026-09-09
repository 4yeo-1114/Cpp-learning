/* C | stack: expression eval. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 100
typedef struct{
	int data[MAX];
	int top;
}stack;

void initStack(stack *s) {
    s->top = -1;
}
bool push(stack *s, int data) {
    if (s->top >= MAX - 1) {
        return false; // 栈满
    }
    s->data[++(s->top)] = data;
    return true;
}
int pop(stack *s){
	if(s->top>=0){
		return s->data[(s->top)--];
	}
	return -1; 	
}
int main(){
	stack s;
	initStack(&s);
    char c;
    int sum = 0;
    int isreadingnum;
	while(scanf("%c",&c)!=EOF){
		if(c=='@'){
			break;
		}
		
		if(isdigit(c)){
			sum  = sum*10 + (c - '0');
			isreadingnum = 1;
		}
		else{//如果遇到非数字 压入栈 
			if(isreadingnum){
				push(&s,sum);
				sum = 0;
				//重置
				isreadingnum = 0; 
		}
		if(c=='+'||c=='-'||c=='*'||c=='/'){
				int a1 = pop(&s);
				int a2 = pop(&s);
				if(c=='+'){
					int a3 = a1+a2;
					push(&s,a3);
				}
				else if(c=='-'){
					int a3 = a2-a1;
					push(&s,a3);
				}
				else if(c=='*'){
					int a3 = a2*a1;
					push(&s,a3);
				}
				else{
					int a3 = a2/a1;
					push(&s,a3);
				}
			}
	} 
}
	int ans  = pop(&s);
	printf("%d",ans);
	return 0;
}
