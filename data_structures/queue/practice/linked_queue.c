/* C | queue: linked queue. */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *initQueue(){
	node*q = (node*)malloc(sizeof(node));
	q->data =  0 ;
	q->next = NULL;
	return q;
}
int isEmpty(node *q){
	if(q->data==0|| q->next == NULL){
		return 1;
	}
	return 0;
}

void enQueue(node *q,int data){
	node *n  = (node*)malloc(sizeof(node));
	n->data = data;
	node *q1  = q;
	while(q1->next != NULL){
		q1 = q1->next;
	}
	n->next = q1->next;
	q1->next = n;
	q->data++;
}
int deQueue(node *q){
	if(isEmpty(q)){
		return -1;
	}
	else{
		node *n = q->next;
		int data  = n->data;
		q->next = n->next;
		free(n);
		return data;
	}
}
void printQueue(node *q){
	node *n = q->next;
	while(n){
		printf("%d -> ",n->data);
		n  = n->next;
	}
	printf("NULL\n");
}
int main(){
	node *q  = initQueue();
	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);
	enQueue(q,4);
	printQueue(q);
	deQueue(q);
	printQueue(q);
	return  0 ;
}
