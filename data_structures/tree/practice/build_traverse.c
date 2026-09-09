/* C | tree: build traverse. */
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
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
        //用递归创建左子树
        creatTree(&(*T)->lchild);
        creatTree(&(*T)->rchild);
    }
}
//先序遍历
void preOrder(TreeNode*T){
  if(T==NULL){
    return;
  }
  else{
    //先输出根
    printf("%c ",T->data);
    //遍历左子树
    preOrder(T->lchild);
    //遍历右子树
    preOrder(T->rchild);
  }
}
//中序
void inOrder(TreeNode*T){
  if(T==NULL){
    return;
  }
  else{
    
    //遍历左子树
    inOrder(T->lchild);
    //再输出根
    printf("%c ",T->data);
    //遍历右子树
    inOrder(T->rchild);
  }
}
//后序
void postOrder(TreeNode*T){
  if(T==NULL){
    return;
  }
  else{
    
    //遍历左子树
    postOrder(T->lchild);
    //遍历右子树
    postOrder(T->rchild);
    //最后输出根
    printf("%c ",T->data);
  }
}
int main(){
    TreeNode* T;
    creatTree(&T);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    return 0;  
}