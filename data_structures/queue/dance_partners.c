/* C | queue: dance partners. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_QUEUE_SIZE 100

// 舞者结构体
typedef struct {
    char name[MAX_NAME_LEN];
    char sex; // 'F' 表示女性，'M' 表示男性
} Dancer;

// 队列结构体
typedef struct {
    Dancer data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// 初始化队列
void InitQueue(Queue *q) {
    q->front = q->rear = 0;
}

// 判断队列是否为空
int QueueEmpty(Queue *q) {
    return q->front == q->rear;
}

// 入队操作
int EnQueue(Queue *q, Dancer dancer) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("队列已满，无法入队\n");
        return 0;
    }
    q->data[q->rear] = dancer;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    return 1;
}

// 出队操作
int DeQueue(Queue *q, Dancer *dancer) {
    if (QueueEmpty(q)) {
        printf("队列为空，无法出队\n");
        return 0;
    }
    *dancer = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return 1;
}

// 获取队头元素但不出队
int GetFront(Queue *q, Dancer *dancer) {
    if (QueueEmpty(q)) {
        printf("队列为空，无法获取队头元素\n");
        return 0;
    }
    *dancer = q->data[q->front];
    return 1;
}

// 舞伴匹配函数
void DancePartner(Dancer dancers[], int num) {
    Queue Mdancers, Fdancers;
    Dancer male, female;

    // 初始化男、女队列
    InitQueue(&Mdancers);
    InitQueue(&Fdancers);

    // 将舞者按性别分别入队
    for (int i = 0; i < num; i++) {
        if (dancers[i].sex == 'F') {
            EnQueue(&Fdancers, dancers[i]);
        } else {
            EnQueue(&Mdancers, dancers[i]);
        }
    }

    printf("The dancing partners are:\n");

    // 当男、女队列都不为空时，依次输出男女舞伴
    while (!QueueEmpty(&Fdancers) && !QueueEmpty(&Mdancers)) {
        DeQueue(&Fdancers, &female);
        DeQueue(&Mdancers, &male);
        printf("%s (F) 和 %s (M)\n", female.name, male.name);
    }

    // 如果女队列不为空，输出剩余女舞者
    while (!QueueEmpty(&Fdancers)) {
        DeQueue(&Fdancers, &female);
        printf("%s (F) 没有舞伴\n", female.name);
    }

    // 如果男队列不为空，输出剩余男舞者
    while (!QueueEmpty(&Mdancers)) {
        DeQueue(&Mdancers, &male);
        printf("%s (M) 没有舞伴\n", male.name);
    }
}

int main() {
    Dancer dancers[] = {
        {"Alice", 'F'},
        {"Bob", 'M'},
        {"Cindy", 'F'},
        {"David", 'M'},
        {"Ella", 'F'},
        {"Frank", 'M'},
        {"Grace", 'F'}
    };
    int num = sizeof(dancers) / sizeof(dancers[0]);

    DancePartner(dancers, num);

    return 0;
}
