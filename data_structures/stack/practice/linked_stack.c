/* C | stack: linked stack. */
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node * next;
}node;

node * initStack(){
	node * s = (node*)malloc(sizeof(node));
	s->data = 0;
	s->next = NULL;
	return s;
}
int isEmpty(node *s){
	if(s->data == 0 || s->next == NULL){
		return 1;
	}
	else return 0;
}
int gettop(node *s){
	if(isEmpty(s)){
		return -1;
	}
	else{
		return s->next->data; // 第一个节点的data 
	}
}
int pop(node *s){
	if(isEmpty(s)){
		return -1;
	}
	else{
		node *n = s->next;
		s->next = n->next;
		int data = n->data;
		s->data--;
		free(n);
		return data;
	}
}
int push(node*s, int data){
	node * n = (node*)malloc(sizeof(node));
	n->data = data;
	n->next = s->next;
	s->next = n;
	s->data ++;
}
void printStack(node *s){
	node * n = s->next;
	while(n){
		printf("%d ",n->data);
		n  = n->next;
	}
	printf("NULL\n");
}
int main(){
	node *s = initStack();
	push(s,1);
	push(s,2);
	push(s,3);
	printStack(s);
	printf("top = %d",pop(s));
	return 0;
}
