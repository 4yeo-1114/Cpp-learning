#include <stdio.h>
#include <stdlib.h>

typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild,*rchild;
    int LTag,RTag; // 线索标记：0表示指向孩子，1表示指向前驱/后继
} BiThrNode, *BiThrTree;


// 全局变量 记录中序遍历的前驱节点
BiThrNode *pre = NULL;

//对以p为节点的子树进行中序线索化
void InThreading(BiThrTree p){
    if(p){
        InThreading(p->lchild);

        //处理当前节点p的左线索
        if(!p->lchild){ //左孩子为空 建立左线索
            p->LTag  = 1;
            p->lchild = pre;
        }else{
            p->LTag = 0; 
        }
        // 处理前驱节点pre的右线索
        if(!pre->rchild){
            pre->RTag = 1;
            pre->rchild = p;
        }
        else{
            pre->RTag = 0;
        }
        pre = p; //在进入右子树线索化前要先把自己线索化好
        InThreading(p->rchild);
    }
}

//对整颗二叉树进行中序线索化
void InOrderThreading(BiThrTree*Thrt,BiThrTree T){
    *Thrt = (BiThrNode*)malloc(sizeof(BiThrNode)); // 分配头节点内存
    if (!*Thrt) exit(1); // 内存分配失败则退出
    
    (*Thrt)->LTag = 0;
    (*Thrt)->RTag = 1;
    (*Thrt)->rchild = *Thrt;

    if(!T){
        (*Thrt)->lchild = *Thrt;
    }
    else{
        (*Thrt)->lchild = T;
        pre = *Thrt;
        InThreading(T);
        pre->rchild = *Thrt;
        pre->RTag = 1;
        (*Thrt)->rchild = pre;
    }
}

//遍历

void InOrderTravverse_Thr(BiThrTree Thrt){
    BiThrNode *p = Thrt->lchild; // p指向根节点
    while(p!=Thrt){
        while(p->LTag==0){
            p = p->lchild;
        }
        printf("%c ",p->data);
        while(p->RTag==1&&p->lchild!=Thrt){
            p = p->rchild;
            printf("%c ",p->data);
        }
        p = p->rchild;   
    }
}

BiThrNode* GetNext(BiThrNode* p ){
    if(p->RTag==1){
        return p->rchild;
    }
    else{
        p = p->rchild;
        while(p->LTag==0){
            p = p->lchild;
        }
        return p;
    }
}

BiThrNode* GetPrior(BiThrNode*p){
    if(p->LTag==1){
        return p->lchild;
    }
    else{
        p = p->lchild;
        while(p->RTag==0){
            p = p->rchild;
        }
        return p;
    }

}