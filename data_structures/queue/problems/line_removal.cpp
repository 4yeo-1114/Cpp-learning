/* C++ | queue: line removal. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//每次删除增加节点时都要遍历 
//typedef struct node{
//	int data;
//	struct node *next;
//	struct node *pre;
//}node;
//
//node *initList(){
//	node * l = (node*)malloc(sizeof(node));
//	node *n  = (node*)malloc(sizeof(node));
//	l->data = 0;
//	l->next = n;
//	l->pre = NULL; 
//	n->pre = l;
//	n->next = NULL;
//	n->data = 1;
//	return l;
//} 
//
//void printList(node *l){
//	node * j  = l->next;
//	while(j->next!=NULL){
//		printf("%d ",j->data);
//		j = j->next;
//	}
//	printf("%d",j->data);
//	return  ;
//}
//
//int main(){
//	int n,m;
//	scanf("%d",&n);
//	node *l  =initList();
//	for(int i = 2;i<=n;i++){
//		int num,dir;
//		scanf("%d %d",&num,&dir);
//		node * k = l;
//		while(k->data != num && k!=NULL){
//			k = k->next;
//		}
//		if(dir == 0){
//			node *newnode = (node*)malloc(sizeof(node));
//			k->pre->next = newnode;
//			newnode->pre = k->pre;
//			newnode->next = k;
//			k->pre = newnode;
//            newnode->data = i;
//		}
//		else if(dir ==1 ){
//			node *newnode = (node*)malloc(sizeof(node));
//			k->next->pre = newnode;
//			newnode->next = k->next;
//			newnode->pre = k;
//			k->next = newnode;
//			newnode->data = i;
//		}
//	}	
//    scanf("%d", &m);
//    bool visit[100010] = {0};
//    for(int i = 0;i<m;i++){
//    	int move;
//    	scanf("%d",&move);
//    	if(visit[move]) continue;
//    	else{
//    		node *k = l;
//    		while(k->data != move && k!=NULL){
//			k = k->next;
//		}
//            k->pre->next = k->next;
//			k->next->pre = k->pre;
//			free(k);  		
//    		visit[move] = true;
//		}	
//	}
//	printList(l);
//	return 0;
//} 

//用数组储存地址 找节点时 复杂度直接将为n(1)；
typedef struct node{
	int data;
	struct node *next;
	struct node *pre;
}node;
//储存地址的数组
node* p[100010] ; 
node *initList(){
	node * l = (node*)malloc(sizeof(node));
	node *n  = (node*)malloc(sizeof(node));
	l->data = 0;
	l->next = n;
	l->pre = NULL; 
	n->pre = l;
	n->next = NULL;
	n->data = 1;
	p[1] = n;//储存1的地址 
	return l;
} 

void printList(node *l){
	node * j  = l->next;
	while(j->next!=NULL){
		printf("%d ",j->data);
		j = j->next;
	}
	printf("%d",j->data);
	return  ;
}

int main(){
	int n,m;
	scanf("%d",&n);
	node *l  =initList();
	for(int i = 2;i<=n;i++){
		int num,dir;
		scanf("%d %d",&num,&dir);
		//找到目标地址 
		node *k   = p[num];
		if(dir == 0){
			node *newnode = (node*)malloc(sizeof(node));
			k->pre->next = newnode;
			newnode->pre = k->pre;
			newnode->next = k;
			k->pre = newnode;
            newnode->data = i;
            //记录新节点地址 
            p[i] = newnode;
		}
		else if(dir ==1 ){
			node *newnode = (node*)malloc(sizeof(node));
			k->next->pre = newnode;
			newnode->next = k->next;
			newnode->pre = k;
			k->next = newnode;
			newnode->data = i;
			//记录新节点地址 
            p[i] = newnode;
		}
	}	
    scanf("%d", &m);
    bool visit[100010] = {0};
    for(int i = 0;i<m;i++){
    	int move;
    	scanf("%d",&move);
    	if(visit[move]) continue;
    	else{
    		node *k = p[move];
            k->pre->next = k->next;
			k->next->pre = k->pre;
			free(k);  		
    		visit[move] = true;
		}	
	}
	printList(l);
	return 0;
} 

//用链表思想 当时用数组实现
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int mx = 1e5+10;
int n,m;
//并不是链表，各个元素是不相连的 
struct T{
	int  l ,r;  //左手右手边
	int d;//表示同学是否输出 便利删除操作
	 
}t[mx] = {0};

void add(int i,int k,int f){
//新增同学 i是插入的位置，k是插入的同学 
if(f==1){
	t[k].r = t[i].r;
	t[k].l = i;
	t[i].r = k;
	t[t[k].r].l  = k;
} 
else{
	t[k].r=i;
    t[k].l=t[i].l;
    t[i].l=k;
    t[t[k].l].r=k;
}
}
int main(){
	int x,k,f;
	cin>>n;
	//初始化数组 
	//相当于头节点。 
	t[0].r = 0;
	t[0].l = 0;
	//先插入1 
	add(0,1,1);
	for(int i =  2;i<=n;i++){
		cin>>x>>f;
		add(x,i,f);
	}
	cin>>m;
	while(m--){
		cin>>x;
		//标记d为1 不输出 相当于删除
		//牺牲空间换时间 
		t[x].d = 1;
	}
	//i等于0 说明到终点了 
	for(int i = t[0].r;i;i = t[i].r){
		if(t[i].d==0){
			cout<<i;
			if(t[i].r!=0){
				cout<<" ";
			}
		}
	} 
	return 0;
}
 
