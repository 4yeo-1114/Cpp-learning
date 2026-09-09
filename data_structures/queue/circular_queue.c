/* C | queue: circular queue. */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

typedef struct CircleQueue{
	int data[MAXSIZE];
	int front;
	int rear;
}CircleQueue;

// 初始化队列
void InitQueue(CircleQueue *q){
	q->front = 0; //头指针 
	q->rear = 0; // 尾指针 
} 

//判断队列是否为空
int IsEmpty(CircleQueue *q){
	return q->front == q->rear ;
} 

//判断队列是否已满
int IsFull(CircleQueue *q){
	return (q->rear + 1) % MAXSIZE == q->front;
} 

//入队
int EnQueue(CircleQueue *q,int value){
	if(IsFull(q)){
		printf("队列已满，无法入队！\n");
		return 0 ; //失败 
	}
	q->data[q->rear] = value; //尾指针指向的地方本来就是空的
	q->rear  =  (q->rear+1) % MAXSIZE; //尾指针后移
	return 1; //成功 
} 

//出队
int DeQueue(CircleQueue *q, int *value){
	if(IsEmpty(q)){
		printf("队列已空，无法出队！\n");
		return 0;
	}
	*value = q->data[q->front];
	q->front = (q->front+1)%MAXSIZE; //头指针后移
	return 1; 
} 

// 打印队列
void PrintQueue(CircleQueue *q){
	if(IsEmpty(q)){
		printf("队列为空\n");
		
		return;
	}
	printf("队列元素：");
	int i = q->front; //这里要用i 不能改变front的值 只是输出不是出队！ 因为后面要判断队列空满 
	while(i != q->rear) {
		printf("%d ",q->data[i]);
	    i  = (i+1) % MAXSIZE;
	}
	printf("\n");
} 

int main(){
	CircleQueue q;
	InitQueue(&q);
	printf("入队10，20，30，40\n");
	EnQueue(&q,10);
	EnQueue(&q,20);
	EnQueue(&q,30);
	EnQueue(&q,40);
	PrintQueue(&q);
	
	printf("尝试入队50\n");
	EnQueue(&q,50);
	PrintQueue(&q);
	
	int val;
	printf("出队一次：");
	DeQueue(&q,&val);
	printf("%d", val);
	PrintQueue(&q);
	
	printf("再入队50\n");
	EnQueue(&q,50);
	PrintQueue(&q);
	 
	
	return  0 ;
}

