/* C | tree: preorder threaded tree. */
//数不是一个线性结构 所以我们用线索将二叉树转化为一个类似的线性结构
//二叉树有n个节点 一共有2n个指针 但是有n+1个指针没用 利用这些指针来指向前去和后继

#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    int ltag;
    int rtag;
}TreeNode;

void creatTree(TreeNode** T){
    //因为要修改指针的值 并且还要开辟空间 所以传入二级指针
    char data;
    scanf("%c\n",&data);
    if(data=='#'){
        //此时为空节点
        *T=NULL;
    }
    else{
        *T =(TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = data;
        //tag等于0表示有孩子
        (*T)->ltag = 0; 
        (*T)->rtag = 0;
        //用递归创建左子树
        creatTree(&(*T)->lchild);
        creatTree(&(*T)->rchild);
    }
}
//线索化的函数
//pre传二级指针 因为要改变pre的值
void preThreadTree(TreeNode*T,TreeNode** pre){
    if(T){
        //先序就是先办事
        //如果没有左孩子 这个指针就指向前驱
        if(T->lchild==NULL){
            T->ltag =1;
            T->lchild = *pre;

        }
        //如果这个pre也没有右孩子，就指向后继（T）
        if((*pre)!=NULL && (*pre)->rchild==NULL){
            (*pre)->rtag =1;
            (*pre)->rchild = T;
        }
        //依旧按先序来递归 但是前面已经改变了T->lchild
        //所以要保证T-ltag=0 即T原来是真有左孩子才递归
        if(T->ltag==0) preThreadTree(T->lchild,pre);
        //更新pre
        *pre = T;
        preThreadTree(T->rchild,pre);
    }
}


//找到节点的下一个节点（后继）
TreeNode* getNext(TreeNode* node){
    //没右孩子 返回后继
    if(node->rtag==1){
        return node->rchild;
    }
    //因为是先序 有左孩子直接返回左孩子就好 没有返回右孩子
    else {
        if(node->ltag==0){
             return node->lchild;
        }
        else return node->rchild;
    }
   
}


int main(int argc,char* argv[]){
    TreeNode* T;
    TreeNode* pre =NULL;
    int index = 0;
    createTree(&T,argv[1],&index);
    preThreadTree(T,&pre);
    //再对最后一个节点处理
    pre->rtag =1;
    pre->rchild = NULL;
    //遍历
    for(TreeNode*node =T;node!=NULL;node=getNext(node)){
        printf("%c ",node->data);
    }
    return 0;  
}