/* C | linked list: doubly linked operations. */
#include <stdio.h>
#include <stdlib.h>

// 定义双向链表节点
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// 创建头节点
Node* createHead() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    head->data = 0;     // 头节点数据域可不用
    head->prev = NULL;
    head->next = NULL;
    return head;
}

// 在链表头部插入新节点（头节点之后）
void insertFront(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = head;
    newNode->next = head->next;

    if (head->next != NULL) { //如果后面是空的 就当然没必要改前驱了（不存在的东西怎么改呢） 
        head->next->prev = newNode; //让原来第一个节点的前驱指向新节点 
    }
    head->next = newNode;
}

// 在指定位置插入（位置从1开始）
void insertAtPosition(Node* head, int value, int pos) {
    if (pos < 1) {
        printf("位置无效\n");
        return;
    }
    Node* current = head;
    // 移动到目标位置前一个节点
    for (int i = 1; i < pos; i++) {
        if (current == NULL) {
            printf("位置超出链表长度\n");
            return;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("位置超出链表长度\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// 删除第一个值为value的节点
void deleteNode(Node* head, int value) {
    Node* current = head->next;
    while (current != NULL) {
        if (current->data == value) {
            current->prev->next = current->next;
            if (current->next != NULL) { //一样后面没有节点就只改前面的 
                current->next->prev = current->prev;
            }
            free(current); //释放被删节点的空间 
            return;
        }
        current = current->next;
    }
    printf("未找到值为 %d 的节点\n", value);
}

// 在指定位置删除（位置从1开始）
void deleteAtPosition(Node* head, int pos) {
    if (pos < 1) {
        printf("位置无效\n");
        return;
    }
    Node* current = head->next;
    for (int i = 1; i < pos; i++) {
        if (current == NULL) {
            printf("位置超出链表长度\n");
            return;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("位置超出链表长度\n");
        return;
    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

// 打印链表
void printList(Node* head) {
    Node* current = head->next;
    printf("链表内容: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 释放链表（保留头节点）
void freeList(Node* head) {
    Node* current = head->next;
    while (current != NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
    head->next = NULL;
}

// 测试
int main() {
    Node* head = createHead();

    printf("插入 10, 20, 30\n");
    insertFront(head, 10);
    insertFront(head, 20);
    insertFront(head, 30);
    printList(head);

    printf("在位置2插入 99\n");
    insertAtPosition(head, 99, 2);
    printList(head);

    printf("删除位置3的节点\n");
    deleteAtPosition(head, 3);
    printList(head);

    freeList(head);
    free(head); // 释放头节点
    return 0;
}
