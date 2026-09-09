/* C | tree: level order. */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

//队列节点
typedef struct QueueNode{
    TreeNode * data;
    struct QueueNode *pre;
    struct QueueNode* next;
}QueueNode;
void creatTree(TreeNode** T,char *data,int *index){
    char ch;
    ch = data[*index];
    *index++;
    if(ch = '#'){
        *T = NULL;
    }
    else{
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        creatTree(&(*T)->lchild,data,index);
        creatTree(&(*T)->rchild,data,index);
    }
}

void preOrder(TreeNode *T){
    if(T=NULL){
        return ;
    }
    else{
        printf("%c ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
//初始化队列
QueueNode* initQueue(){
    QueueNode *Q = (QueueNode*)malloc(sizeof(QueueNode));
    Q->data = NULL;
    Q->next = Q;
    Q->pre  = Q;
    return Q;
}
//入队函数 尾插法
void enQueue(TreeNode *data,QueueNode*Q){   
    QueueNode* node  = malloc(sizeof(QueueNode));
    node->data = data;
    node->pre = Q->pre;
    node->next = Q;
    Q->pre->next = node;
    Q->pre = node;
}
int isEmpty(QueueNode*Q){
    if(Q->next==Q){
        return 1;
    }
    return 0;
}
//出队函数
QueueNode* deQueue(QueueNode*Q){
    if(isEmpty(Q)){
        return NULL;
    }
    else{
        QueueNode* node = Q->next;
        Q->next->next->pre = Q;
        Q->next = Q->next->next;
        return node;
    }
}
//层次遍历
void levelTraverse(TreeNode *data, QueueNode*Q){
    enQueue(data,Q);
    while(!isEmpty(Q)){
        QueueNode *node = deQueue(Q);
        pritnf("%c ",node->data->data);
        if(node->data->lchild){
            enQueue(node->data->lchild,Q);
        }
        if(node->data->rchild){
            enQueue(node->data->rchild,Q);
        }
    }
}
int main(int argc,char* argv[]){
    TreeNode *T;
    int index = 0;
    QueueNode*Q =  initQueue();
    creatTree(&T,argv[1],&index);
    preOrder(T);
    printf("\n");
    levleTraverse(T,Q);
    return 0;
}