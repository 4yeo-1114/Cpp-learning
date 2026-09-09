/* C | sequential list: merge sorted. */
#include <stdio.h>
#include <stdlib.h>

// 定义元素类型为 int
typedef int ElemType;

// 定义顺序表结构
typedef struct {
    ElemType *elem;  // 存储空间基址
    int length;      // 当前长度
    int listsize;    // 当前分配的存储容量（这里暂未用到，伪代码也未涉及）
} SqList;

// 初始化顺序表
void InitList(SqList *L) {
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
}

// 为顺序表分配空间并初始化数据
void CreateList(SqList *L, ElemType arr[], int n) {
    L->elem = (ElemType *)malloc(n * sizeof(ElemType));
    if (!L->elem) {
        exit(1); // 内存分配失败，退出程序
    }
    L->length = n;
    for (int i = 0; i < n; i++) {
        L->elem[i] = arr[i];
    }
}

// 合并两个非递减顺序表 LA 和 LB 到 LC
void MergeList(SqList LA, SqList LB, SqList *LC) {
    // 新表长度为两表长度之和
    LC->length = LA.length + LB.length;
    // 为合并后的新表分配数组空间
    LC->elem = (ElemType *)malloc(LC->length * sizeof(ElemType));
    if (!LC->elem) {
        exit(1); // 内存分配失败，退出程序
    }

    ElemType *pa = LA.elem;           // 指针 pa 指向 LA 的第一个元素
    ElemType *pb = LB.elem;           // 指针 pb 指向 LB 的第一个元素
    ElemType *pc = LC->elem;          // 指针 pc 指向 LC 的第一个元素
    ElemType *pa_last = LA.elem + LA.length - 1; // 指针 pa_last 指向 LA 的最后一个元素
    ElemType *pb_last = LB.elem + LB.length - 1; // 指针 pb_last 指向 LB 的最后一个元素

    // 未到达 LA 和 LB 的表尾
    while (pa <= pa_last && pb <= pb_last) {
        // 依次摘取两表中值较小的元素插入 LC 的最后
        if (*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    // 已到达 LB 表尾，依次将 LA 的剩余元素插入 LC 的最后
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    // 已到达 LA 表尾，依次将 LB 的剩余元素插入 LC 的最后
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
}

// 打印顺序表
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

// 释放顺序表空间
void DestroyList(SqList *L) {
    if (L->elem) {
        free(L->elem);
        L->elem = NULL;
        L->length = 0;
        L->listsize = 0;
    }
}

int main() {
    SqList LA, LB, LC;

    // 初始化顺序表
    InitList(&LA);
    InitList(&LB);
    InitList(&LC);

    // 测试数据，非递减排列
    ElemType arrLA[] = {1, 3, 5, 7};
    ElemType arrLB[] = {2, 4, 6, 8, 10};

    // 创建顺序表 LA 和 LB
    CreateList(&LA, arrLA, sizeof(arrLA) / sizeof(arrLA[0]));
    CreateList(&LB, arrLB, sizeof(arrLB) / sizeof(arrLB[0]));

    printf("顺序表 LA 的元素：");
    PrintList(LA);
    printf("顺序表 LB 的元素：");
    PrintList(LB);

    // 合并 LA 和 LB 到 LC
    MergeList(LA, LB, &LC);

    printf("合并后的顺序表 LC 的元素：");
    PrintList(LC);

    // 释放空间
    DestroyList(&LA);
    DestroyList(&LB);
    DestroyList(&LC);

    return 0;
}
