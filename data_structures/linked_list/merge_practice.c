/* C | linked list: merge practice. */
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;          // 数据域
    struct Node* next; // 指针域
} Node;

// 初始化链表（带头节点）
Node* Initlist() {
    Node* head = (Node*)malloc(sizeof(Node)); // 创建头节点
    head->next = NULL;                        // 头节点之后暂无数据节点
    return head;
}

// 尾插法插入元素（用于构建初始链表）
void Inserttail(Node* head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    newNode->data = val;
    newNode->next = NULL;
    p->next = newNode;
}

// 在链表中查找元素 e，存在返回 1，否则返回 0
int LocateElem(Node* head, int e) {
    Node* p = head->next;
    while (p != NULL) {
        if (p->data == e) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

// 合并两个链表：将 LB 中不在 LA 中的元素插入 LA
void MergeList(Node* LA, Node* LB) {
    Node* p = LB->next; // p 指向 LB 的第一个数据节点
    while (p != NULL) {
        int e = p->data;
        if (!LocateElem(LA, e)) {
            Inserttail(LA, e); // 尾插法插入到 LA
        }
        p = p->next;
    }
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

// 释放链表
void DestroyList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        Node* temp = p->next;
        free(p);
        p = temp;
    }
}

// 测试
int main() {
    Node* LA = Initlist();
    Node* LB = Initlist();

    // 初始化 LA: 7,5,3,11
    Inserttail(LA, 7);
    Inserttail(LA, 5);
    Inserttail(LA, 3);
    Inserttail(LA, 11);

    // 初始化 LB: 2,6,3
    Inserttail(LB, 2);
    Inserttail(LB, 6);
    Inserttail(LB, 3);

    printf("合并前 LA：");
    PrintList(LA);
    printf("合并前 LB：");
    PrintList(LB);

    MergeList(LA, LB);

    printf("合并后 LA：");
    PrintList(LA);

    DestroyList(LA);
    DestroyList(LB);

    return 0;
}
