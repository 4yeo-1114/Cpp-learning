/* C | tree: avl tree. */
//就是建立一颗二叉排序树的过程
//建立的过程中要调整 用到树的高度 所以在结构体中需要加一个高度

#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
    int data;
    int height;
    struct TreeNode* lchild;
    struct TreeNode * rchild;


}TreeNode;

int getHeight(TreeNode* node){
    return node?node->height:0;
}
int Max(int a,int b){
    return a>b?a:b;
}

//RR:取中间的节点 使其父亲成为他的左孩子 如果他有左孩子的话 这个左孩子连接到父亲的右孩子上
void rrRotation(TreeNode*node,TreeNode**root){
    //node是第一个节点 temp是node右边的树 即新的根
    TreeNode*temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    //更新高度 左右子树的最大高度加一
    node->height = Max(getHeight(node->lchild),getHeight(node->rchild))+1;
    temp->height = Max(getHeight(temp->lchild),getHeight(temp->rchild))+1;
    //改变根
    *root = temp;

}
//LL:取中间的节点 使其父亲成为他的右孩子 如果他有右孩子的话 这个左孩子连接到父亲的左孩子上
void llRotation(TreeNode*node,TreeNode**root){
    TreeNode*temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
     node->height = Max(getHeight(node->lchild),getHeight(node->rchild))+1;
    temp->height = Max(getHeight(temp->lchild),getHeight(temp->rchild))+1;
    *root=temp;
}

void avlInsert(TreeNode**T,int data){
    if(*T==NULL){
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T) ->data = data;
        (*T) ->height = 0;
        (*T) -> lchild = NULL;
        (*T) -> rchild = NULL;

    }
    else if(data<(*T)->data){
        //先插入再调整
        avlInsert(&(*T)->lchild,data);
        //插入完后拿到当前节点左右子树的高度
        int  lHeight = getHeight((*T)-> lchild);
        int  rHeight = getHeight((*T)-> rchild);
         //判断高度差
        if(lHeight-rHeight==2){
            if(data<(*T)->lchild->data){
            //LL调整
            llRotation(*T,T);
        }
        else{
            //LR调整
            //先对左孩子做rr调整
            rrRotation((*T)->lchild,&(*T)->lchild);
            llRotation(*T,T);
        }

        }
        
    }
    else if(data>(*T)->data){
        avlInsert(&(*T)->rchild,data);
        int  lHeight = getHeight((*T)-> lchild);
        int  rHeight = getHeight((*T)-> rchild);
       
        if(rHeight-lHeight==2){
             if(data>(*T)->rchild->data){
            //RR调整
            rrRotation(*T,T);
        }
        else{
            //RL调整
            llRotation((*T)->rchild,&(*T)->rchild);
            rrRotation(*T,T);

        }
        }
       
    }
    //更新节点高度
    (*T)->height = Max(getHeight((*T)->lchild),getHeight((*T)->rchild))+1;
}

void preOrdered(TreeNode*T){
    if(T){
        printf("%d ",T->data);
        preOrdered(T->lchild);
        preOrdered(T->rchild);
    }

}

int main(){
    TreeNode *T = NULL;
    int nums[5] = {1,2,3,4,5};
    for(int i = 0;i<5;i++){
        avlInsert(&T,nums[i]);
    }

}