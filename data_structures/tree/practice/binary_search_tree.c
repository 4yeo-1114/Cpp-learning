/* C | tree: binary search tree. */
//bst
//左子树值小于根小于右子树 这个性质递归的
//元素不重复
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode*  lchild;
    struct TreeNode* rchild;

}TreeNode;

//查找函数
TreeNode* bstSearch(TreeNode*T,int data){
    if(T){
        if(T->data==data){
            return T;
        }
        else if(T->data>data){
            return bstSearch(T->lchild,data);
        }
        else{
            return bstSearch(T->rchild,data);
        }


    }
    else return NULL;

}

//插入函数
TreeNode* bstInsert(TreeNode**T,int data){
    //该节点为空 新建节点
    if(*T==NULL){
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->lchild =NULL;
        (*T)->rchild = NULL;

    }
    //树中已有这个值了啥也不做
    else if(data==(*T)->data){
        return ;
    }
    //值比现在这个节点小 插到左边
    else if(data<(*T)->data){
        bstInsert(&((*T)->lchild),data);
    }
    //反之插到右边
    else{
        bstInsert(&((*T)->rchild),data);
    }

}


//遍历函数
void preOrder(TreeNode*T){
    //一定要写if(T)不然递归不会停止
    if(T){
    printf("%d",T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
    }
    
}

int mian(){
    TreeNode*T = NULL;
    int nums[6] = {4,5,19,23,2,8};
    for(int i = 0;i<6;i++){
        bstInsert(&(T),nums[i]);
    }
    preOrder(T);
    printf("\n");
}