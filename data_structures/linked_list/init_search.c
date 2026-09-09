/* C | linked list: init search. */
#include <stdio.h>
#include <stdlib.h>
 // 定义链表节点 
typedef struct Node{
	int data; // 数据域 
	struct Node *next; // 指针域， 指向下一个节点 
}Node ;
// 初始化链表
Node* Initlist(){
	Node *head = (Node*) malloc(sizeof(Node)); // 创建头节点 
	head->next = NULL; // 头节点之后暂无数据节点 
	return head; 
} 
// 头插法 插入元素
void InsertHead(Node *head, int val){
	Node *newNode  = (Node*)malloc(sizeof(Node)); // 创建一个新节点；
	newNode->data  = val ; // 存入数据域里里面；
	newNode->next = head->next; // 新节点指向原第一个节点 ;
	head->next  = newNode; //头节点指向新节点
	 
} 
// 在链表里面查找值为wal的节点， 返回其地址（找不到返回NULL） 
Node* FindNode(Node *head, int val){
	Node *p = head->next; // 从第一个数据点开始查找
	while(p!= NULL){
		if(p->data == val){
			return p;
		} 
		p = p->next; // 找到继续向后 
	} 
	return NULL; 
}
//测试代码
int main(){
	Node *head = Initlist(); // 初始化链表
	// 插入几个元素
	InsertHead(head, 30);
	InsertHead(head, 20);
	InsertHead(head, 10);
	Node *found = FindNode(head,20);
		if(found != NULL){
			printf("找到了值为%d的节点\n", found->data);
		}
		else{
			printf("未找到该节点！"); 
		} 
		

	
		return 0;
} 
