/* C | stack: linked stack. */
#include <stdio.h>
#include <stdlib.h>

// 链栈节点结构定义
typedef struct StackNode {
    int data;               // 节点数据域
    struct StackNode *next; // 节点指针域，指向下一个节点
} StackNode, *LinkStack;

// 初始化链栈
void InitStack(LinkStack *S) { //用指针的指针去修改栈顶指针 所以要加*号！ 
    *S = NULL; // 栈顶指针初始化为 NULL，表示空栈
}

// 入栈操作
int Push(LinkStack *S, int e) {
    StackNode *p = (StackNode *)malloc(sizeof(StackNode)); // 分配新节点内存
    if (!p) {
        return 0; // 内存分配失败，入栈失败
    }
    p->data = e;        // 新节点存储数据
    p->next = *S;       // 新节点的 next 指向原栈顶节点
    *S = p;             // 栈顶指针指向新节点，完成入栈
    return 1;           // 入栈成功
}

// 出栈操作
int Pop(LinkStack *S, int *e) {
    if (*S == NULL) {
        return 0; // 栈为空，出栈失败
    }
    StackNode *p = *S;   // 暂存栈顶节点
    *e = p->data;        // 取出栈顶节点的数据
    *S = p->next;        // 栈顶指针指向原栈顶节点的下一个节点
    free(p);             // 释放原栈顶节点的内存
    return 1;            // 出栈成功
}

// 测试函数
int main() {
    LinkStack S;
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

    // 查看剩余栈顶元素
    if (S != NULL) {
        printf("当前栈顶元素：%d\n", S->data);
    }

    // 释放剩余栈节点内存（可选，测试时简单演示）
    while (S != NULL) {
        StackNode *p = S;
        S = S->next;
        free(p);
    }

    return 0;
}
