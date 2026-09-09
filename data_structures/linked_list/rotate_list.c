/* C | linked list: rotate list. */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int val;
	struct Node *next;
}Node;

// 旋转链表函数
Node* rotateRight(Node* head,int k ){
	// 将每个节点向右移动k个位置
	if(k == 0 || head == NULL || head->next  == NULL){
		return head; //如果链表长度不大于1，或者k=0,返回原链表
		 
	} 
	int n  =  1; //计算链表长度 
	Node* tail =head; //创建一个尾指针
	while(tail->next!=NULL){
		tail = tail->next;
		n++;
	} 
	int movenum = k%n; //链表实际需要移动的次数
	if(movenum == 0) return head;
	tail->next = head; //链表合并成环 
	int addnum = n - movenum; //计算旋转后的尾节点位置 
	while(addnum--){
		tail = tail->next; //把尾节点移动到新尾节点的位置 
	}
	Node* newhead  = tail->next; // 新的头节点
	tail->next = NULL;
	return newhead; 
} 
// 创建链表函数
Node* creatList(int arr[], int size){
	if(size == 0) return NULL;
	Node *head = (Node*)malloc(sizeof(Node));
	head->val = arr[0];
	head->next = NULL;
	Node* curr= head;
	for(int i = 1; i<size;i++){
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->val = arr[i];
		newNode->next = NULL;
		curr->next = newNode;
		curr = newNode; 
	} 
    return head;
	 
} 

// 打印链表
void printList(Node* head){
	Node *curr = head;
	while( curr!= NULL){
		printf("%d", curr->val);
		curr = curr->next;
	}
	printf("\n");
} 

//释放链表函数
void freeList(Node*head){
	Node *curr = head;
	while(curr != NULL){
		Node* temp = curr;
		curr = curr->next;
		free(temp);
	}
} 
//测试
int main(){
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(int);
	Node *head = creatList(arr, size);
	
	printf("原链表");  
	printList(head);
	int k = 2;
	Node* rotateHead = rotateRight(head,k);
	printf("旋转%d次后的链表：",k);
	printList(rotateHead);
	freeList(rotateHead);
	return 0; 
} 
