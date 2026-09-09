/* C | linked list: merge sorted v2. */
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;          // 数据域
    struct Node* next; // 指针域
} Node;

// 初始化链表（带头节点）
Node* InitList() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    head->next = NULL;
    return head;
}

// 尾插法插入元素（用于构建初始有序链表）
void InsertTail(Node* head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;

    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

// 合并两个非递减单链表 LA 和 LB 到 LC
void MergeList(Node* LA, Node* LB, Node* LC) {
    Node* pa = LA->next; // pa 指向 LA 的第一个数据节点
    Node* pb = LB->next; // pb 指向 LB 的第一个数据节点
    Node* pc = LC;       // pc 指向 LC 的头节点

    while (pa != NULL && pb != NULL) {
        if (pa->data <= pb->data) {
            // 摘取 pa 所指节点
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            // 摘取 pb 所指节点
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    // 将非空表的剩余段插入到 pc 所指节点之后
    pc->next = (pa != NULL) ? pa : pb;

    // 释放 LB 的头节点
    Node* temp = LB;
    free(temp);
}

// 打印链表
void PrintList(Node* head) {
    Node* p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 释放链表（除头节点外，若要释放头节点需单独处理）
void DestroyListExceptHead(Node* head) {
    Node* p = head->next;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }
    head->next = NULL;
}

int main() {
    Node* LA = InitList();
    Node* LB = InitList();
    Node* LC = InitList();

    // 初始化 LA 为非递减序列：1 3 5 7
    InsertTail(LA, 1);
    InsertTail(LA, 3);
    InsertTail(LA, 5);
    InsertTail(LA, 7);

    // 初始化 LB 为非递减序列：2 4 6 8 10
    InsertTail(LB, 2);
    InsertTail(LB, 4);
    InsertTail(LB, 6);
    InsertTail(LB, 8);
    InsertTail(LB, 10);

    printf("链表 LA 的元素：");
    PrintList(LA);
    printf("链表 LB 的元素：");
    PrintList(LB);

    // 合并 LA 和 LB 到 LC
    MergeList(LA, LB, LC);

    printf("合并后的链表 LC 的元素：");
    PrintList(LC);

    // 释放链表空间（LA 后续若还需使用可保留，这里一起释放演示）
    DestroyListExceptHead(LA);
    free(LA);
    free(LC); // LC 的头节点是原 LA 的头节点，LA 已 free，这里也可理解为整体释放

    return 0;
}
