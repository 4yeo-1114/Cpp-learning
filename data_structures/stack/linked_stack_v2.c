/* C | stack: linked stack v2. */
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode;

StackNode* InitStack(StackNode *S){
	S = NULL; // 没有必要设头节点，直接让栈顶指针为空即可。 
	return S;
}
// 入栈 
int Push(StackNode *S, int e){
	StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->data = e;
	newNode->next = S;
	S = newNode;
	return 0; 
}

//出栈
int Pop(StackNode *S,int *e){
	if(S == NULL ) return 0;
	*e = S->data; //和顺序栈不同 链栈的栈顶指针就是指向栈顶
	StackNode *p = S; // 用p临时存放栈顶元素空间，已备释放
	S = S->next;
	free(p);
	return 1; 
} 

int main() {
    StackNode S;
    int e;

    // 初始化链栈
    InitStack(&S);
    printf("链栈初始化完成\n");

    // 入栈测试
    Push(&S, 10);
    Push(&S, 20);
    Push(&S, 30);
    printf("入栈 10、20、30 成功\n");

    // 出栈测试
    if (Pop(&S, &e)) {
        printf("出栈元素：%d\n", e);
    }
    if (Pop(&S, &e)) {
        printf("出栈元素：%d\n", e);
    }

//    // 查看剩余栈顶元素
//    if (S != NULL) {
//        printf("当前栈顶元素：%d\n", S->data);
//    }

//    // 释放剩余栈节点内存（可选，测试时简单演示）
//    while (S != NULL) {
//        StackNode *p = S;
//        S = S->next;
//        free(p);
    }



