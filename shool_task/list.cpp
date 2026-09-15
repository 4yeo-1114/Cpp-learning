#include <iostream>
#include <stdlib.h>

using namespace std;

const int maxn = 10000;

struct node {
    int data;
    struct node *next;
};

node *head;

// 1. 在链表的第 i 个位置插入元素 x
void insert(int i, int x) {
    node *p = head;
    // 寻找第 i-1 个节点（因为下标从1开始，且带头节点）
    // 如果 i=1，p 指向 head，循环不执行，直接在 head 后插入
    for (int k = 1; k < i && p != NULL; k++) {
        p = p->next;
    }
    
    // 如果 p 为空，说明 i 超出了当前链表长度，通常不做操作或可追加到末尾
    if (p == NULL) return;

    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    // 插入操作
    newNode->next = p->next;
    p->next = newNode;
}

// 2. 删除链表的第 i 个位置的元素
void deleteByIndex(int i) {
    node *p = head;
    // 寻找第 i-1 个节点
    for (int k = 1; k < i && p != NULL; k++) {
        p = p->next;
    }

    // 如果 p 为空或者 p 没有下一个节点（即要删除的位置不存在）
    if (p == NULL || p->next == NULL) return;

    node *temp = p->next;
    p->next = temp->next;
    free(temp);
}

// 3. 查找元素 x 第一次出现的位置，返回下标，不存在返回0
int find(int x) {
    node *p = head->next;
    int index = 1;
    while (p != NULL) {
        if (p->data == x) {
            return index;
        }
        p = p->next;
        index++;
    }
    return 0;
}

// 4. 统计链表中值在 [x, y] 范围内的元素个数
void count(int x, int y) {
    node *p = head->next;
    int cnt = 0;
    while (p != NULL) {
        if (p->data >= x && p->data <= y) {
            cnt++;
        }
        p = p->next;
    }
    printf("%d\n", cnt);
}

// 5. 去除链表中的所有重复元素，只保留第一次出现的元素
void eliminateRepeat() {
    node *p = head->next;
    while (p != NULL) {
        node *q = p; // q 用于遍历 p 之后的所有节点
        while (q->next != NULL) {
            if (q->next->data == p->data) {
                // 发现重复元素，删除 q->next
                node *temp = q->next;
                q->next = temp->next;
                free(temp);
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
}

// 6. 删除链表中所有值在 [x, y] 范围内的元素
void deleteByRange(int x, int y) {
    node *p = head;
    while (p->next != NULL) {
        if (p->next->data >= x && p->next->data <= y) {
            // 如果 p 的下一个节点在范围内，删除它
            node *temp = p->next;
            p->next = temp->next;
            free(temp);
            // 注意：这里不移动 p，因为新的 p->next 可能还需要检查
        } else {
            p = p->next;
        }
    }
}

int main() {
    int c, i, x, y;
    int m;
    scanf("%d", &m);
    head = (node*) malloc(sizeof(node));
    head->next = NULL;
    for (int k = 0; k < m; k++) {
        scanf("%d", &c);
        switch (c) {
            case 1: scanf("%d%d", &i, &x); insert(i, x); break;
            case 2: scanf("%d", &i); deleteByIndex(i); break;
            case 3: scanf("%d", &x); printf("%d\n", find(x)); break;
            case 4: scanf("%d%d", &x, &y); count(x, y); break;
            case 5: eliminateRepeat(); break;
            case 6: scanf("%d%d", &x, &y); deleteByRange(x, y); break;
        }
    }
    return 0;
}