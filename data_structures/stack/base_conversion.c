/* C | stack: base conversion. */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 32
// 栈结构
typedef struct{
	int data[MAXSIZE];
	int top; // 用不用栈底指针的方式定义 
	
}Stack;

//初始化栈
void InitStack(Stack *s){
	s->top = 0; 
} 
// 判断栈是否为空
int isEmpty(Stack *s){
	return s->top == 0;
} 

// 入栈
void push(Stack *s, int value){
	if(s->top >= MAXSIZE-1){
		printf("栈满\n");
		exit(1); 
	}
	s->data[s->top++] = value; 
} 

// 出栈
int pop(Stack *s){
	if(isEmpty(s)){
		printf("栈空\n");
	    exit(1);
	    
	}
	return s->data[--s->top]; 
} 
// 十进制转八进制
void decToOct(Stack *s, int n){
	int sign =  0 ; 
	if(n < 0){
		sign = 1; // 标记为正数
		n = -n; 
	}
	if(n == 0){
		push (s, 0);
		return ;
	}
	while(n > 0 ){
		push (s, n%8); // 把n除8的余数压到栈里
		n /= 8; 
	}
	if(sign){ // 还记得前面的负数处理吗 
		push(s,-1);
	}
	
} 

int main(){
	Stack s;
	InitStack(&s);
	
	int num = -124;
	decToOct(&s, num);
	printf("十进制%d的八进制数是：\n",num);
	while(!isEmpty(&s)){
		int val = pop(&s);
		if(val == -1){
			printf("-");
		}
		else{
			printf("%d", val);
		}
	} 
		printf("\n");
		return 0 ;
}
