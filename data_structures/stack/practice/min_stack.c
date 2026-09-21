/* C | stack: min stack. */
#include <stdio.h>
#define MAX 100
int stack[MAX]; // 主栈 
int minStack[MAX]; //辅助栈
int top  = 0;
void push(int val){
	if(top>= MAX) return ;
	stack[top++]  =val;
	//第一个元素入栈 也入最小栈
	if(top==1){
		minStack[top] = val;
	}else{
		minStack[top] = (val<minStack[top-1])?val:minStack[top-1];
	}
} 
int pop(){
	if(top<0) return -1;
	return stack[--top]; 
}
int Getmin(){
	if(top<=0) return -1;
	return minStack[top-1];
}
