/* C | linked list: insert delete. */
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node{
	int data;  // 数据域 
	struct Node* next; // 指针域 
}Node;
 
 //初始化链表（带头节点） 
Node* Initlist(){
	Node *head = (Node*) malloc(sizeof(Node)); // 创建头节点 
	head->next = NULL; // 头节点之后暂无数据节点 
	return head; 
} 
// 头插法插入元素
void InsertHead(Node *head,int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = head->next;// 新节点指向原第一个节点
	head->next = newNode; // 头节点指向新节点
	
}
// 尾插法插入元素
void Inserttail(Node *head,int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *p =head;
	while(p->next!=NULL){
		p = p->next;
	} // 移动p到最后 
    newNode->data = val;
	newNode->next = p->next; //即NULL； 
	p->next = newNode;
	
} 

// 指定位置插入元素
void InsertAtPosition(Node *head, int val, int pos){
	if(pos < 1)return; //位置无效
	Node *p = head;
	for(int i = 1; i<pos && p!=NULL;i++){
		p = p->next; 
	} 
	if(p ==  NULL) return ; //位置超出链表长度
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = p->next;  // 新节点指向原位置节点
	p->next = newNode;
} 

// 删除第一个值为val的节点
void DeleteNode(Node *head, int val){
	Node *p = head;
	while(p->next != NULL && p->next->data != val){
		p = p->next; //没找到就指针就前进 
	}
	if(p->next != NULL){ // 找到节点了！ 
	Node *temp = p->next; //暂时存一下删除节点 
	p->next = temp->next; // 逃过删除节点！ 
	free(temp); 
	}
} 
// 删除指定位置的元素
void DeleteAsPositionNode(Node *head, int pos){
	Node * p =head;
	for(int i = 1; i<pos && p != NULL;i++){
		p = p->next;
	}
	if(p->next != NULL){
		Node *temp = p->next;
		p->next = temp->next;
		free(temp);
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
        Node *temp = p;
        p = p->next;
        free(temp);
    
    }
}

// 测试
int main(){
	Node *head = Initlist();
	InsertHead(head,30);
	InsertHead(head,20);
	InsertHead(head,10);
	printf("头插法结果：");
	PrintList(head); 
	
	Inserttail(head,40);
	printf("尾插法结果：");
	PrintList(head); 
	
	InsertAtPosition(head, 15, 2);
	printf("在位置2插入15：");
	PrintList(head);
	
	DeleteNode(head,20);
	printf("在删除20后");
	PrintList(head);
	
	DeleteAsPositionNode(head, 2);
	printf("删除第二个位置的元素：");
	PrintList(head);
	 
	 DestroyList(head);
	 
	return 0; 
} 
