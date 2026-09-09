/* C | tree: postorder threaded tree. */
//数不是一个线性结构 所以我们用线索将二叉树转化为一个类似的线性结构
//二叉树有n个节点 一共有2n个指针 但是有n+1个指针没用 利用这些指针来指向前去和后继

#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    struct TreeNode* parent;
    int ltag;
    int rtag;
}TreeNode;

void creatTree(TreeNode** T,TreeNode *parent){
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
        (*T)->parent = parent;
        //用递归创建左子树
        creatTree(&(*T)->lchild,(*T));
        creatTree(&(*T)->rchild,(*T));
    }
}
//线索化的函数
//pre传二级指针 因为要改变pre的值
void postThreadTree(TreeNode*T,TreeNode** pre){
    if(T){
        //后办事
        postThreadTree(T->lchild,pre);
        postThreadTree(T->rchild,pre);
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
        //更新pre
        *pre = T;
    }
}

//找到遍历的起点的树
//因为是后序所以不是最左的树 得看最左边得数还有没有右子树
TreeNode* getFirst(TreeNode*T){
    while(T->ltag==0){
        T=T->lchild;
    }
    if(T->rtag==0){
        return getFirst(T->rchild);
    }
    else return T;
}
//找到节点的下一个节点（后继）
//这里和中序 先序很不一样 尤其是根节点下一个节点必须是NULL 不然遍历时永远不会结束
TreeNode* getNext(TreeNode* node){
    //没右孩子 放回后继
    if(node->rtag==1){
        return node->rchild;
    }
    else{
        //如果是根节点
        if(node->parent ==NULL){
            return NULL;
        }
        //如果是右孩子
        //返回parent(根)
        else if(node->parent->rchild == node ){
            return node->parent;
        }
        //如果是左孩子
        //如果parent有右孩子 返回以右孩子为根的树的第一个节点
        //如果没有 返回parent
        else{
            if(node->parent->rtag=0){
                return getfirst(node->parent->rchild);
            }
            else return node->parent;
        }

    }
}


int main(){
    TreeNode* T;
    TreeNode* pre =NULL;
    createTree(&T,NULL);
    postThreadTree(T,&pre);
    //不用对最后一个节点处理 以为最后一个（pre）就是整颗树的根节点
    //遍历
    for(TreeNode*node =getFirst(T);node!=NULL;node=getNext(node)){
        printf("%c ",node->data);
    }
    return 0;  
}

