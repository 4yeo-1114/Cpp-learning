/* C | stack: min stack. */
#include <stdio.h>
#define MAX 100
int stack[MAX]; // 主栈 
int minStack[MAX]; //辅助栈
int top  = -1;
void push(int val){
	if(top>= MAX-1) return ;
	stack[++top]  =val;
	if(top==0){
		minStack[top] = val;
	}else{
		minStack[top] = (val<minStack[top-1])?val:minStack[top-1];
	}
} 
int pop(){
	if(top<0) return -1;
	return stack[top--]; 
}
int Getmin(){
	if(top<0) return -1;
	return minStack[top];
}
