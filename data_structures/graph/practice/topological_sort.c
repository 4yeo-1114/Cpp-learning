/* C | graph: topological sort. */
//AOV 网 节点表示任务 弧表示依赖关系
//拓扑排序就是将aov中的顶点排成一个线性序列
//若排完后输出的顶点数不变则说明aov没有环是一个DAG有向无环图 若减少则有环

//流程：
//1找出没有前驱的点 输出 剪掉以他为出发点的所有边
//重复第一步 直到图中不存在没有前驱的点

#include <stdio.h>
#include <stdlib.h>
#define MAX 1234235
typedef struct Graph{
    char *vexs;//节点
    int** arcs;//边
    int vexNum; // 节点数量
    int arcNum;//边的数量

}Graph;

typedef struct Node{
    int data;
    struct Node*next;
}Node;

Node* initStack(){
    Node * stack = (Node*)malloc(sizeof(Node));
    stack->data = 0;
    stack->next = NULL;
    return stack;
}

int isEmpty(Node* stack){
    if(stack->next = NULL){
        return 1;
    }
    else return 0;
}

void push(Node* stack,int data){
    Node* node  = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->next;
    stack->next = node;
    stack->data++;
}
int pop(Node* stack){
    if(!isEmpty(stack)){
        Node* node  =stack->next;
        stack->next = node->next;
        return node ->data;
    }
    else {
        return -1;
    }
}


Graph* initGraph(int vexNum){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->vexs = (char*)malloc(sizeof(char)*vexNum);
    G->arcs = (int**)malloc(sizeof(int*)*vexNum);
    for(int i = 0;i<vexNum;i++){
        G->arcs[i] = (int*)malloc(sizeof(int)*vexNum);
    }
    G->vexNum = vexNum;
    G->arcNum = 0;//初始化边数为零
    return G;
}
void creatGraph(Graph*G,char*vexs,int*arcs){
    //对节点进行赋值
    for(int i = 0;i<G->vexNum;i++){
        G->vexs[i] = vexs[i];
        for(int j = 0;j<G->vexNum;j++){
            //记录边的情况
            G->arcs[i][j] = *(arcs+i*G->vexNum+j);
            if(G->arcs[i][j]!=0 && G->arcs[i][j]!=MAX){
                G->arcNum++;
            }
        }
    }
    //拓扑排序是有向的 边数不减半
}
//深度优先搜索
void DFS(Graph*G,int* visited,int index){
    printf("%c\t",G->vexs[index]);
    //记录被访问了
    visited[index] =1;
    for(int i =0;i<G->vexNum;i++){
        //有可访问的节点 而且这个节点没被访问过 则可递归
        if(G->arcs[index][i]>0&&G->arcs[index][i]!=MAX&&!visited[i]){
            DFS(G,visited,i);
        }
    }
    //当 for 循环结束时，函数自然执行完毕，自动 return 回上一层
    //所以不需要写什么终止条件
}
//统计入度
int* findInDegree(Graph*G){
    int* inDegrees = (int *)malloc(sizeof(int)*G->vexNum);
    for(int i = 0;i<G->vexNum;i++){
        inDegrees[i] = 0;
    }
    for(int i = 0;i<G->vexNum;i++){
        for(int j = 0;j<G->vexNum;j++){
            if(G->arcs[i][j])
            //若有以他为尾的边 入度就加一
            inDegrees[j]++;
        }
    }
    return inDegrees;
}

void topologicalSort(Graph*G){
    Node * stack = initStack();
    int* inDegrees = findInDegree(G);
    int*top =  (int *)malloc(sizeof(int)*G->vexNum);
    int index = 0;
    //循环一轮 入度为零的入栈
    for(int i = 0;i<G->vexNum;i++){
        if(inDegrees[i]==0){
            push(stack,i);
        }
    }
    //入度为零的出栈 直到栈为空
    while(!isEmpty(stack)){
        int vex = pop(stack);
        //加入top数组
        top[index++] = vex;
        //更新入度
        for(int i = 0;i<G->vexNum;i++){
           if( G->arcs[vex][i]){
            inDegrees[i]  = inDegrees[i]  -1;
            if(inDegrees[i]==0){
                push(stack,i);
            }
           }
        }
    }
    //输出排序后结果
    for(int i = 0;i<index;i++){
        printf("%c ",G->vexs[top[i]]);
    }
    printf("\n");
}

int main(){
    Graph*G = initGraph(6);
    int *visited = (int*)malloc(sizeof(int)*G->vexNum);
    for(int i= 0 ;i<G->vexNum;i++){
        visited[i] = 0;
    }
    int arcs[6][6]={
        0,1,1,1,0,0,
        0,0,0,0,0,0,
        0,1,0,0,1,0,
        0,0,0,0,1,0,
        0,0,0,0,0,0,
        0,0,0,1,1,0

    };
    //传入节点和边的情况来创建图
    //也可写(int*)arcs 把二级指针退化为一级指针
    creatGraph(G,"123456",&arcs[0][0]);
    DFS(G,visited,0);
    printf("\n");
    return 0;
}