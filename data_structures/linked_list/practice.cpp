#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node* creatHead(){
    Node* head  =(Node*)malloc(sizeof(Node));
    if(head==NULL){
        printf("内存表分配失败！");
        exit(1);
    }
    head->next = NULL;
    return head;
}

//头插法
void headInsert(Node *head,int n){
    for(int i  = 0 ;i<n;i++){
        Node* newNode = (Node*)malloc(sizeof(Node));
        if(newNode==NULL){
            printf("内存分配失败！");
            exit(1);
        }
        printf("第%d次输入",i+1);
        scanf("%d",&newNode->data);
        newNode->next =  head->next;
        head->next = newNode;
    }

}

void tailInsert(Node*head,int n){
    Node * tail = head;
    for(int i = 0;i<n;i++){
        Node * newNode = (Node*)malloc(sizeof(Node));
        if(newNode==NULL){
            printf("内存分配失败！");
            exit(1);
        }
        printf("第%d次输入",i+1);
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        tail->next = newNode;
        tail  = newNode;
    }
}


void PrintList(Node *head){
    Node*p = head->next;
    while(p != NULL){
        printf("%d",p->data);
        p = p ->next;
    }
    printf("\n");
}


void DestroyList(Node *head){
    Node *p = head;
    while(p!=NULL){
        Node * temp  = p ->next;
        free(p);
        p = temp;
    }
}

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
