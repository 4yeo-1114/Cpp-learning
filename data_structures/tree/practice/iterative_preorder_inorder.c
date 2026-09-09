/* C | tree: iterative preorder inorder. */
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

typedef struct StackNode{
    TreeNode* data;
    struct StackNode* next;
}StackNode;

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
StackNode * initStack(){
    StackNode* S = malloc(sizeof(StackNode));
    S->data = NULL;
    S->next =NULL;
    return S;
}
void push(TreeNode *data,StackNode*S){
    StackNode* node = malloc(sizeof(StackNode));
    node->data = data;
    node->next = S->next;
    S->next = node;
}
int isEmpty(StackNode*S){
    if(S->next==NULL){
        return 1;
    }
    else return 0;
}
StackNode* pop(StackNode* S){
    if(isEmpty(S)){
        return NULL;
    }
    else{
        StackNode* node = S->next;
        S->next = node->next;
        return node;
    }
}

//先序遍历 
//入栈依旧按中序的逻辑入栈 
//入栈的顺序就是先序遍历的结果
void preOrder(TreeNode*T){
    TreeNode*node  = T;
    StackNode*S= initStack;
    //只要还有节点并且栈不为空就继续
    while(node||!isEmpty(S)){
        if(node){
            printf("%c ",node->data);
            push(node,S);
            node = node->lchild;
        }
        else{
            node = pop(S)->data;
            node = node->rchild;
        }
    }
}
//中序遍历
//入栈
//左子树为空就出栈
void inOrder(TreeNode*T){
    TreeNode*node  = T;
    StackNode*S= initStack;
    while(node||!isEmpty(S)){
        if(node){
            push(node,S);
            node = node->lchild;
        }
        else{
            node = pop(S)->data;
            printf("%c ",node->data);
            node = node->rchild;
        }
    }
     
}
int main(int argc,char* argv[]){
    TreeNode*T;
    int index = 0;
    createTree(&T,argv[1],&index);
    preOrder(T);
    pritnf("\n");
    inOrder(T);
    return 0;
}