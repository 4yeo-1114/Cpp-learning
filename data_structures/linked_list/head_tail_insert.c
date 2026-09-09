/* C | linked list: head tail insert. */
#include <stdio.h>
#include <stdlib.h>
//定义链表节点
typedef struct Node{
	int data;
	struct Node* next;
}Node;
// 创建头节点（初始化链表）
Node* creatHead(){
	Node* head = (Node*)malloc(sizeof(Node));
	if(head == NULL){
		printf("内存分配失败！");
		exit(1);
	}
	head->next = NULL;
    return head; 
} 

//头插法
void headInsert(Node* head,int n){
	for(int i = 1; i<=n ; i++){
		Node* newNode = (Node*)malloc(sizeof(Node));
		if(newNode == NULL){
		printf("内存分配失败！");
		exit(1);}
		printf("第%d次输入：", i);
		scanf("%d", &newNode->data);
		newNode->next = head->next;
		head->next = newNode; 
	    
	}
}

//尾插法
void tailInsert(Node* head, int n){
	Node* tail = head;
	for(int i = 1; i<=n;i++){
		Node* newNode = (Node*)malloc(sizeof(Node));
		if(newNode == NULL){
		printf("内存分配失败！");
		exit(1);}
		printf("第%d次输入：",i);
		scanf("%d", &newNode->data);
		newNode->next = NULL;
		tail->next = newNode; //尾节点指向新节点 
		tail = newNode; // 更新尾节点 
	}
} 
// 打印链表 
void PrintList(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 释放链表
void DestroyList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        Node *temp = p->next;
        free(p);
        p = temp;
    
    }
}
// 测试
int main(){
	Node* head1 = creatHead();
	Node* head2 = creatHead();
	int n;
	printf("请输入要插入元素的个数:");
	scanf("%d", &n);
	headInsert(head1, n);
	printf("头插法结果：");
	PrintList(head1);
	
	tailInsert(head2,n);
	printf("尾插法结果：");
	PrintList(head2);
	
	DestroyList(head1);
	DestroyList(head2);
	return 0 ; 
} 

