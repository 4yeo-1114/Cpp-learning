// #include <stdio.h>
// #include <stdlib.h>
// #define MAXSIZE 100

// typedef struct{
//     int data[MAXSIZE];
//     int length;
// }SeqList;

// int InsertSeqList(SeqList*L,int i,int e){
//     if(i<1 || i>L->length+1) return 0;
//     if(L->length>MAXSIZE) return 0;
//     for(int j  = L->length;j>=i;j--){
//         L->data[j] = L->data[j-1];
//     }
//     L->data[i-1] = e;
//     L->length++;
//     return 1;

// }

// void PrintfSeqList(SeqList L){
//     for(int i = 0;i<L.length;i++){
//         printf("%d ",L.data[i]);
//     }
//     printf("\n");
// }

// int DeleteSeqList(SeqList *L, int i,int *e){
//     if(i<1||i>L->length){
//         return 0;
//     }
//     *e  = L->data[i-1];
//     for(int j  = i-1;j<L->length-1;j++){
//         L->data[j] = L->data[j+1];
//     }
//     L->length --;
//     return 1;
// }
// int main(){
//     SeqList L;
//     L.length = 0;
//     InsertSeqList(&L,1,10);
//     InsertSeqList(&L,2,20);
//     InsertSeqList(&L,3,30);
//     int delval;
//     if(DeleteSeqList(&L,2,&delval)){
//         printf("删除成功:删除的值是:%d\n",delval);
//     }
//     PrintfSeqList(L);
//     return 0;


// }

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* elem;  //储存空间基址
    int length; //当前长度
    int listsize; //当前分配的存储容量
} SqList;

void InitList(SqList *L){
    L->elem = NULL;
    L->length = 0;
    L->listsize  = 0;
}

//为顺序表分配空间并初始化数据

void CreateList(SqList *L,int arr[],int n){
    L->elem  = (int*)malloc(n*sizeof(int));
    //内存分配失败
    if(!L->elem){
        exit(1);
    }
    L->length = n;
    for(int i = 0;i<n;i++){
        L->elem[i] = arr[i];
    }
}

//合并两个非递减顺序表
void MergeList(SqList LA,SqList LB,SqList *LC){
    LC->length = LA.length + LB.length;
    LC->elem = (int*)malloc(LC->length*sizeof(int));

    if(!LC->elem){
        exit(1);
    }

    int *pa = LA.elem;
    int *pb = LB.elem;
    int *pc = LC->elem;
    int *pa_last = LA.elem + LA.length -1;
    int *pb_last = LB.elem + LB.length -1;

    while(pa<=pa_last && pb<=pa_last){
        if(*pa<*pb){
            *pc = *pa;
            pa++;
        }
        else{
            *pc = *pb;
            pb++;
        }
        pc++;
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

void PrintList(SqList L){
    for(int i = 0;i<L.length;i++){
        printf("%d",L.elem[i]);
    }
    printf("\n");

}

void DestroyList(SqList *L){
    if(L->elem){
        free(L->elem);
        L->elem = NULL;
        L->length = 0;
        L->listsize = 0;
    }

}

int main(){
    SqList LA, LB, LC;

    // 初始化顺序表
    InitList(&LA);
    InitList(&LB);
    InitList(&LC);


        // 测试数据，非递减排列
    int  arrLA[] = {1, 3, 5, 7};
    int arrLB[] = {2, 4, 6, 8, 10};

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







}