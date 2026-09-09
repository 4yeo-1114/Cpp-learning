/* C | linked list: doubly linked list. */
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *pre;
	struct node *next;
}node;
node* initlist(){
	node *l  =(node*)malloc(sizeof(node));
	l->data = 0;
	l->pre = NULL;
	l->next = NULL;
	return l;
}
void headinsert(node*l,int data){
	node* n = (node*)malloc(sizeof(node));
	n->data = data;
	if(l->next == NULL){//双向链表要特判这个 
		//链表为空 
		n->next = l->next;
		n->pre = l;
		l->next = n;
	}
	else{
	n->pre = l;
	n->next = l->next;
	l->next->pre = n;
	l->next = n;	
	} 
	l->data++;
}
void tailinsert(node* l,int data){
	node *n = (node*)malloc(sizeof(node));
	node *tail = l;
	n->data = data;
	while(tail->next != NULL){
		tail = tail->next;
	}
	n->next = NULL;
	tail->next =n;
	n->pre = tail;
	l->data++;
}
int  deletelist(node*l,int data){
	node *n  = l->next;
	while(n){
		if(n->data == data){
			n->pre->next = n->next;
			n->next->pre = n->pre;
			free(n);
			return 1;
		}
		n = n->next;
	}
	return -1;
}
void printlist(node*l){
	node *n = l->next;
	while(n){
		printf("%d->",n->data);
		n = n->next;
	}
	printf("NULL\n");
}
//释放列表
 
void destoryList(node *l){
	node *p = l; 
	for(p!=NULL){
		node* temp = p->next;
		free(p);
        p =  temp;		
	} 
} 
int main(){
	node *l = initlist();
	headinsert(l,1);
	headinsert(l,2);
	headinsert(l,3);
	headinsert(l,4);
	tailinsert(l,5);
	tailinsert(l,6);
	tailinsert(l,7);
	printlist(l);
	deletelist(l,6);
	printlist(l);
	return 0 ;
} 
