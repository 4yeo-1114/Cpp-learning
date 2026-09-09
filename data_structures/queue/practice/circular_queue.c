/* C | queue: circular queue. */
#include <stdio.h>
#include <stdlib.h>
# define MAXSIZE 5
typedef struct Queue{
	int data[MAXSIZE];
	int rear;
	int front;
}queue;

queue * initQueue(){
	queue * q = (queue*)malloc(sizeof(queue));
	q->front = q->rear = 0;
	return q;
}
int isFull(queue *q){
	if((q->rear+1) % MAXSIZE == q->front){
		return 1;
	}
	else return 0;
}
int isEmpty(queue *q){
	if(q->rear == q->front){
		return 1;
	}
	else return 0;
}
int enQueue(queue *q,int data){
	if(isFull(q)){
		return 0;
	}
	else{
		q->data[q->rear] = data;
		q->rear = (q->rear+1) % MAXSIZE;
		return 1;
	}
}
int deQueue(queue *q){
	if(isEmpty(q)){
		return -1;
	}
	else{
		int data = q->data[q->front];
		q->front = (q->front +1)%MAXSIZE;
		return data; 
	}
}
void printQueue(queue *q){
	//要知道有多少个元素
	int len = (q->rear-q->front+MAXSIZE)% MAXSIZE; 
	int index = q->front;
	for(int i = 0;i<len;i++){
		printf("%d -> ",q->data[index]);
		index = (index + 1)%MAXSIZE;
	}
	printf("NULL\n");
}
int main(){
	queue *q  = initQueue();
	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);
	enQueue(q,4);
	enQueue(q,5);
	printQueue(q);
	deQueue(q);
	deQueue(q);
	printQueue(q);
	return 0;
}

 
