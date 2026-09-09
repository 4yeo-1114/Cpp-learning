/* C | stack: validate pop order. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#define MAX 50
typedef struct{
	int data[MAX];
	int top;
}stack;
void initStack(stack *s){
	s->top = -1;
}
bool push(stack*s,int data){
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
bool isEmpty(stack *s){
	return s->top==-1;
}
int main(){
	stack s;
	stack s1;
	initStack(&s);
	initStack(&s1);
	int n,m,k;
	scanf("%d %d %d",&m,&n,&k);
	for(int i = 0;i<k;i++){
		int num;
		scanf("%d",&num);
		if(num>m) {
			printf("NO\n");
			continue;
		}
		for(int j = 1;j<=num;j++){
			push(&s,j);
		}
		for(int p = n;p>num;p--){
			push(&s1,p);
		}
		pop(&s);
		int h = n-1;
		int flag = 0;
		while(h--){
			int num1;
			scanf("%d",&num1);
			if(num1 == s.data[s.top] ) pop(&s);
			else if(num1 == s1.data[s1.top]){
				pop(&s1);
				push(&s,num1);
				pop(&s);
			}
			else{
				flag = 1;
				break; 
			}
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
