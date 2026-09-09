/* C | queue: linked queue. */
#include <stdio.h>
#include <stdlib.h>

//定义链队列节点
typedef struct Node{
	int data;
	struct Node *next;
}Node;
// 链队列结构 
typedef struct{
	Node *front; // 队头指针（指向头节点） 
	Node *rear; //队尾指针 
}LinkQueue;

//初始化链队列
void InitQueue(LinkQueue *q){
	// 创建头节点
	q->front = q->rear = (Node*)malloc(sizeof(Node));
	if(q->front == NULL){
		printf("内存分配失败\n");
		exit(1);
	}
	q->front->next = NULL ; //头节点初始无后继 
} 

//入队操作
int EnQueue(LinkQueue *q, int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("内存分配失败\n");
		exit(1);
	}
	newNode->data = value;
	newNode->next = NULL; 
	q->rear->next = newNode; //尾插法 
	q->rear = newNode; //更新队尾指针
	return 1; 
} 

// 出队操作
int DeQueue(LinkQueue *q, int * value){
	if(q->front == q->rear){
		printf("队列已空，出队失败！");
		return 0;
	}
	Node * temp = q->front->next; 
	q->front->next =temp->next;
	*value = temp->data;
	if(temp == q->rear){ // 若出队后队列为空
	  q->rear = q->front; 
	}
	free(temp);
	return 1;
} 

//判断队列是否为空
int IsEmpty(LinkQueue *q){
	return q->front == q->rear;
} 

//打印
void PrintQueue(LinkQueue *q){
	if(IsEmpty(q)){
		printf("队列为空\n");
		return ;
	}
	Node *p =q->front->next;
	printf("队列元素:");
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	} 
	printf("\n");
} 
// 销毁队列 
void DestroyQueue(LinkQueue *q){
	int val;
	while (!IsEmpty(q)){
		DeQueue(q, &val);
	} 
	free(q->front);
	q->front = q->rear = NULL; 
	
}

//测试函数
int main(){
	LinkQueue q;
	InitQueue(&q);
	printf("入队\n");
	EnQueue(&q,10);
	EnQueue(&q,20);
	EnQueue(&q,30);
	EnQueue(&q,40);
	PrintQueue(&q);
	
	int val;
	printf("出队\n");
	DeQueue(&q, &val);
	printf("出队元素：%d\n", val);
	PrintQueue(&q);
	
	DestroyQueue(&q);
	return 0; 
} 
