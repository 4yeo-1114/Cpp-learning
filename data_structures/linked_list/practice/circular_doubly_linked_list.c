/* C | linked list: circular doubly linked list. */
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node* pre;
	struct node* next;
}node;
node* initList(){
	node *l = (node*)malloc(sizeof(node));
	l->data = 0;
	l->pre =  l;
	l->next = l;
	return l;
} 
void headInsert(node *l,int data){
	node* n = (node*)malloc(sizeof(node));
	n->data = data;
	if(l->data == 0){//链表为空
	  l->next = n;
	  l->pre = n;
	  n->pre  = l;
	  n->next = l; 
	}
	else{
		n->next = l->next;
		n->pre = l;
		l->next->pre = n;
		l->next  = n;
	}
	l->data++;
}
void tailInsert(node *l,int data){
	node *tail = l;
	while(tail->next != l ){
		tail = tail->next;
	}
	node *n  = (node*)malloc(sizeof(node));
	n->data = data;
	tail->next  = n;
	l->pre = n;
	n->next = l;
	n->pre = tail;
	l->data ++;
	
}
int  deleteList(node *l, int data){
	node *n = l->next;
	while(n->next != l){
		if(n->data = data){
			n->pre->next = n->next;
			n->next->pre = n->pre;
			free(n);
			l->data--;
			return -1; 
		}
		n = n->next;
	}
	return  0;
}
void printList(node *l){
	node *n = l->next;
	while(n!=l){
		printf("%d -> ",n->data);
		n = n->next;
	}
	printf("NULL\n");
}
int main(){
	node *l = initList();
	headInsert(l,1);
	headInsert(l,2);
	headInsert(l,3);
	headInsert(l,4);
	headInsert(l,5);
	tailInsert(l,6);
	tailInsert(l,7);
	tailInsert(l,8);
	printList(l);
	deleteList(l,4);
	deleteList(l,6);
	printList(l);
	return 0 ;
	
}
