/* C++ | queue: josephus. */
//#include <stdio.h>
//#include <stdbool.h>
//int main(){
//	int s = 0;
//	bool visit[200];
//	int n,m;
//	scanf("%d %d", &n,&m);
//	for(int i = 0;i<n;i++){
//		for(int j = 0;j<m;j++){
//			if(++s>n) s = 1;//回到队头 
//			if(visit[s]) j--; //把出圈变为那个地方隐形了 i--循环加一 
//		}
//		if(i!=n-1) printf("%d ",s);
//		else printf("%d",s);
//		visit[s]  = true;
//	} 
//} 

//用链表实现 
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node * next;
}Node;
Node * initList(){
	Node *l = (Node*)malloc(sizeof(Node));
	l->data = 0;
	l->next = l;//循环链表 
	return l;
} 
void tailinsert(Node *l, int data){
	Node *node = (Node*)malloc(sizeof(Node));
	Node *n = l;//用于找到最后一个节点
	while(n->next!=l){
		n = n->next;
	} 
	node->next = l;
	n->next = node;
	node->data = data;
	l->data ++;
} 

// 释放链表
void DestroyList(Node *head) {
    Node *p = head;
	while(p!=NULL){
		Node*temp = p;
		p = p->next;
		free(temp);
	} 
}
int main(){
	Node *l = initList();
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++){
		tailinsert(l,i);
	} 
    Node *pre = l;
    Node *det = l->next;
    for(int i = 0;i<n;i++){
    	for(int j = 0;j<m-1;j++){
    		pre = det;
    		det = det->next;
    		//det不能是l(头节点) 
    		if(det == l){
    			pre = det;
    			det = det->next;
			}
		}
		int num = det->data;
		if(i!=n-1)	printf("%d ",num);
	    else printf("%d",num);
		pre->next = det->next;
		Node *temp = det;
		det  = det->next; 
		free(temp);
		//如果删除后的节点指向头节点移动一格
		if(det==l){
			det = det->next;
		} 
	}
	free(l);
	return 0 ;
}

//用数组实现循环队列 
#include <stdio.h>
int main(){
	int n,m;
	scanf("%d %d", &n,&m);
	int queue[200];
	for(int i = 0 ;i<n;i++){
		queue[i] = i+1;
	}
	int pos = 0;
	for(int i = 0;i<n;i++){
		//移动完后取模（队长等于n-i） 
		pos ,= (pos+m-1)%(n-i); 
		printf("%d",queue[pos]);
		if(i!=n-1) printf(" ");
		//出队
		for(int k = pos;k<n-i-1;k++){
			queue[k] = queue[k+1];
		} 
	}
} 

#include <stdio.h>
int main(){
	int n,m;
	scanf("%d %d", &n,&m);
	int queue[200];
	for(int  i = 0;i<n;i++){
		queue[i]  = i+1;
	}
	int pos = 0;
	for(int i = 0;i<n;i++){
		pos = (pos+(m-1))%(n-i);
		if(i!=n-1) printf("%d ",queue[pos]);
		else printf("%d",queue[pos]);
		for(int j = pos;j<n-i-1;j++){
			queue[j] = queue[j+1];
		}
	}
}

//用队列
//把圈转化为队列 如果报了数不出去就排到队尾  
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
queue<int> a; //初始化队列 
int main()
{
	int n,m,d,e=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a.push(i);//模拟队列 
	}
	while(!a.empty()) //直到队列为空 
	{
		if(e==m)//如果这个人正好被踢 （报的数刚好为m） 
		{
			cout<<a.front()<<" ";//先输出 
			a.pop();//再删除 
			e=1;//再从1开始报数 
		}
		else if(e!=c)//如果不被剔除 
		{
			e++;//报的数+1 
			a.push(a.front());//先把head压进队尾 
			a.pop();//再把head删除 让下一个人报数 
		}
	}
	return 0; 
}
 
