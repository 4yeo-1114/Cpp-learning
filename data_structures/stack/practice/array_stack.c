/* C | stack: array stack. */
#define MAX 100
typedef struct{
	int data[MAX];
	int top;
}Stack;

void push(Stack *s,int val){
	if(s->top<MAX-1) s->data[++(s->top)] = val;
}

int pop(Stack *s){
	if(s->top>0){
		return s->data[(s->top)--];
	}
	return -1; 
}
