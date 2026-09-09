/* C | tree: inorder threading. */
#include <stdio.h>
#include <stdlib.h>

// 线索二叉树节点结构定义
typedef struct BiThrNode {
    char data;                     // 节点存储的数据
    struct BiThrNode *lchild, *rchild; // 左右孩子指针
    int LTag, RTag;                // 线索标记：0表示指向孩子，1表示指向前驱/后继
} BiThrNode, *BiThrTree;

// 全局变量，记录中序遍历的前驱节点
BiThrNode *pre = NULL;

// ************************** 中序线索化（子树） **************************
// 功能：对以p为根的子树进行中序线索化
void InThreading(BiThrTree p) {
    if (p) { // 若当前节点p存在
        InThreading(p->lchild); // 递归线索化左子树
        
        // 处理当前节点p的左线索
        if (!p->lchild) {       // 左孩子为空，建立左线索（指向前驱）
            p->LTag = 1;
            p->lchild = pre;
        } else {
            p->LTag = 0; // 左孩子非空，标记为0
        }
        
        // 处理前驱节点pre的右线索
        if (!pre->rchild) {             // pre的右孩子为空
            pre->RTag = 1;
            pre->rchild = p;    // 前驱的右指针指向当前节点p（后继）
        } else {
            pre->RTag = 0; // 前驱右孩子非空，标记为0
        }
        pre = p;                // 更新pre为当前节点p，作为下一个节点的前驱
        
        InThreading(p->rchild); // 递归线索化右子树
    }
}

// ************************** 带头结点的中序线索化（整树） **************************
// 功能：对整个二叉树T进行带头结点的中序线索化，Thrt为头结点指针
void InOrderThreading(BiThrTree *Thrt, BiThrTree T) {
    *Thrt = (BiThrNode *)malloc(sizeof(BiThrNode)); // 分配头结点内存
    if (!*Thrt) exit(1); // 内存分配失败则退出
    
    (*Thrt)->LTag = 0;  // 头结点左标记为0（指向根节点）
    (*Thrt)->RTag = 1;  // 头结点右标记为1（指向中序最后一个节点）
    (*Thrt)->rchild = *Thrt; // 初始时右指针指向自己（空树时的循环）
    
    if (!T) {           // 若原树为空，左指针也指向自己
        (*Thrt)->lchild = *Thrt;
    } else {
        (*Thrt)->lchild = T; // 头结点左指针指向根节点
        pre = *Thrt;         // 初始化pre为头结点（作为第一个节点的前驱）
        InThreading(T);      // 对根节点T进行中序线索化
        pre->rchild = *Thrt; // 中序最后一个节点的右指针指向头结点
        pre->RTag = 1;       // 中序最后一个节点的右标记为1
        (*Thrt)->rchild = pre; // 头结点右指针指向中序最后一个节点
    }
}

// ************************** 中序线索二叉树的遍历（非递归） **************************
// 功能：中序遍历带头结点的线索二叉树Thrt
void InOrderTraverse_Thr(BiThrTree Thrt) {
    BiThrNode *p = Thrt->lchild; // p指向根节点
    while (p != Thrt) {          // 未遍历到头结点时循环
        while (p->LTag == 0) {   // 左标记为0，说明有左孩子，继续向左找最左节点
            p = p->lchild;
        }
        printf("%c ", p->data);  // 访问当前节点
        
        // 右标记为1且未到头结点时，沿右线索访问后继
        while (p->RTag == 1 && p->rchild != Thrt) {
            p = p->rchild;
            printf("%c ", p->data);
        }
        p = p->rchild; // 进入右子树（或后继节点）
    }
}

// ************************** 中序线索二叉树的查找（找后继） **************************
// 功能：查找节点p的中序后继
BiThrNode *GetNext(BiThrNode *p) {
    if (p->RTag == 1) { // 右标记为1，直接返回右指针（后继）
        return p->rchild;
    } else {            // 右标记为0，找右子树的最左节点
        p = p->rchild;
        while (p->LTag == 0) {
            p = p->lchild;
        }
        return p;
    }
}

// ************************** 中序线索二叉树的查找（找前驱） **************************
// 功能：查找节点p的中序前驱
BiThrNode *GetPrior(BiThrNode *p) {
    if (p->LTag == 1) { // 左标记为1，直接返回左指针（前驱）
        return p->lchild;
    } else {            // 左标记为0，找左子树的最右节点
        p = p->lchild;
        while (p->RTag == 0) {
            p = p->rchild;
        }
        return p;
    }
}

// ************************** 测试代码 **************************
int main() {
    // 构建示例二叉树：A为根，左孩子B，右孩子C；B左孩子D，右孩子E；C右孩子F
    BiThrNode *A = (BiThrNode *)malloc(sizeof(BiThrNode));
    BiThrNode *B = (BiThrNode *)malloc(sizeof(BiThrNode));
    BiThrNode *C = (BiThrNode *)malloc(sizeof(BiThrNode));
    BiThrNode *D = (BiThrNode *)malloc(sizeof(BiThrNode));
    BiThrNode *E = (BiThrNode *)malloc(sizeof(BiThrNode));
    BiThrNode *F = (BiThrNode *)malloc(sizeof(BiThrNode));
    
    A->data = 'A'; B->data = 'B'; C->data = 'C';
    D->data = 'D'; E->data = 'E'; F->data = 'F';
    
    // 初始化各节点的孩子和标记
    A->lchild = B; A->rchild = C; A->LTag = 0; A->RTag = 0;
    B->lchild = D; B->rchild = E; B->LTag = 0; B->RTag = 0;
    C->lchild = NULL; C->rchild = F; C->LTag = 1; C->RTag = 0;
    D->lchild = NULL; D->rchild = NULL; D->LTag = 1; D->RTag = 1;
    E->lchild = NULL; E->rchild = NULL; E->LTag = 1; E->RTag = 1;
    F->lchild = NULL; F->rchild = NULL; F->LTag = 1; F->RTag = 1;
    
    BiThrTree Thrt;
    InOrderThreading(&Thrt, A); // 对二叉树进行带头结点的中序线索化
    
    printf("中序遍历线索二叉树：");
    InOrderTraverse_Thr(Thrt);
    printf("\n");
    
    // 测试查找节点D的前驱和后继
    BiThrNode *D_node = D;
    BiThrNode *D_prior = GetPrior(D_node);
    BiThrNode *D_next = GetNext(D_node);
    printf("节点D的中序前驱：%c\n", D_prior ? D_prior->data : '无');
    printf("节点D的中序后继：%c\n", D_next ? D_next->data : '无');
    
    return 0;
}
