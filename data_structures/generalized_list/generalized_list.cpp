/* C++ | generalized list: generalized list. */
#include <stdio.h>
#include <stdlib.h>
#define ATOM 0 //原子
#define LIST 1 //子表

// 广义表节点结构
typedef struct GNode{
	int tag; // 标记 0：原子 1：子表
	union{
		char atom; // 原子值 这里用char举例
		struct{
			struct GNode *hp; // 表头指针
			struct GNode *tp; // 表尾指针 
		}ptr;  // 子表指针（表头加表尾） 
	}val; 
}GNode, *GList; 

// 创建一个原子节点
GNode* createAtom(char ch){
	GNode *node = (GNode*)malloc(sizeof(GNode));
	node->tag = ATOM; // 也就是1
	node->val.atom = ch;
	return node; 
} 
// 创建一个子表
GNode* createList(GNode *hp, GNode *tp){
	GNode *node = (GNode*)malloc(sizeof(GNode));
	node->tag = LIST;
	node->val.ptr.hp = hp;
	node->val.ptr.tp = tp;
	return node; 
}

//打印广义表
void printGList(GNode *list){
	if(list  == NULL){
		printf("()");
		return ;
	}
	if(list->tag  == ATOM){
		printf("%c", list->val.atom);
		return ;
	}
	printf("("); // 打印子表
	GNode *p = list;
	while (p!= NULL){
		printGList(p->val.ptr.hp);
		p = p->val.ptr.tp;
		if( p!= NULL) printf(",");
		
	} 
	printf(")");
} 

//释放
void free(GNode *list){
	if(list == NULL) return;
	if(list->tag == LIST){
		free(list->val.ptr.hp);
		free(list->val.ptr.tp);
	}
	free(list);
} 

int main(){
	GNode *B = createAtom('B'); 
	GNode *C = createAtom('C'); 
	GNode *D = createAtom('D'); 
	
	GNode *BC = createList(B,createList(C,NULL));
	GNode *root = createList(BC,createList(D,NULL));
	
	printGList(root);
	free(root);
	return 0 ;
}
