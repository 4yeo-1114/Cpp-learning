/* C | tree: iterative postorder. */
#include <stdio.h>
typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    int flag;
}TreeNode;

typedef struct StackNode{
    struct TreeNode* data;
    struct StackNode*next;
}StackNode;

void creatTree(TreeNode**T){
    char ch;
    scanf("%c", &ch);
    if(ch=='#'){
        *T = NULL;
    }
    else{
        (*T) = malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->flag = 0;
        creatTree(&(*T)->lchild);
        creatTree(&(*T)->rchild);
    }
}
StackNode* initStack(){
    StackNode*S = (StackNode*)malloc(sizeof(StackNode));
    S->data = NULL;
    S->next = NULL;
    return S;
}
void push(TreeNode*data,StackNode*S){
     StackNode* node = (StackNode*)malloc(sizeof(StackNode));
     node->next= data;
     node->next = S->next;
     S->next = node;

}
int isEmpty(StackNode*S){
    if(S->next){
        return 0;
    }
    else return 1;
}
StackNode* pop(StackNode*S){
    if(isEmpty(S)){
        return NULL;
    }
    else{
        StackNode* node = S->next;
        S->next = S->next->next;
        return node;
    }
}

StackNode* gettop(StackNode*S){
    if(isEmpty(S)){
        return NULL;
    }
    else{
        StackNode* node = S->next;
        return node;
    }
}
//后序遍历
//从根节点开始，寻找最左边的节点，并依次入栈
//找到最左边节点后，开始出栈
//出栈前，判断栈顶元素是否有右子树且该右子树还未被访问过
//如果有再将该右子树入栈
void postOrder(TreeNode*T){
    TreeNode*node =T;
    StackNode*S = initStack();
    //只要还有节点并且栈不为空就继续
    while(node||!isEmpty(S)){
        if(node){
            push(node,S);
            node = node->lchild;
        }
        else{
            TreeNode*top = gettop(S)->data;
            if(top->rchild&&top->rchild->flag==0){
                    top = top->rchild;
                    push(top,S);
                    node = top->lchild;
            }
            else{
                top   = pop(S)->data;
                pritnf("%c ",top->data);
                top->flag = 1;
            }
        }
    }
}
