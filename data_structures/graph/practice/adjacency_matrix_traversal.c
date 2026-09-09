/* C | graph: adjacency matrix traversal. */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef struct Queue{
    int front;
    int rear;
    int data[MAXSIZE];

}Queue;

Queue* initQueue(){
    Queue* Q =(Queue*)malloc(sizeof(Queue));
    Q->front =Q->rear = 0;
    return Q;
}
void printQueue(Queue* Q){
    //要知道当前队列有多少个元素
    int length = (Q->rear - Q->front+MAXSIZE)%MAXSIZE;
    int index = Q->front;
    for(int i = 0;i<length;i++){
        printf("%d -> ",Q->data[index]);
        index = (index+1)%MAXSIZE;
    }
    printf("\n");
}
int isFull(Queue*Q){
    if((Q->rear+1)%MAXSIZE == Q->front){
        return 1;
    }
    else return 0;
}
int isEmpty(Queue*Q){
    if(Q->front == Q->rear){
        return 1;
    }
    else return 0;
}

int enQueue(Queue*Q,int data){
    if(isFull(Q)){
        return 0;
    }
    else{
    Q->data[Q->rear++] = data;
    Q->rear = Q->rear%MAXSIZE;
    return 1;

    }
}
int deQueue(Queue*Q){
    if(isEmpty(Q)){
        return -1;
    }
    else{
        int data = Q->data[Q->front];
        Q->front = (Q->front+1)%MAXSIZE;
        return data;
    }
}

typedef struct Graph{
    char *vexs;//节点
    int** arcs;//边
    int vexNum; // 节点数量
    int arcNum;//边的数量

}Graph;

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
            if(G->arcs[i][j]!=0){
                G->arcNum++;
            }
        }
    }
    //边数要减半 因为是无向图
    G->arcNum /= 2;
}
//深度优先搜索
void DFS(Graph*G,int* visited,int index){
    printf("%c\t",G->vexs[index]);
    //记录被访问了
    visited[index] =1;
    for(int i =0;i<G->vexNum;i++){
        //有可访问的节点 而且这个节点没被访问过 则可递归
        if(G->arcs[index][i] == 1&&!visited[i]){
            DFS(G,visited,i);
        }
    }
    //当 for 循环结束时，函数自然执行完毕，自动 return 回上一层
    //所以不需要写什么终止条件
}
//广度优先搜索
//类似树的层次遍历
void BFS(Graph*G,int* visited,int index){
    Queue*Q = initQueue();
    printf("%c\t",G->vexs[index]);
    visited[index] = 1;
    enQueue(Q,index);
    while(!isEmpty(Q)){
        int i = deQueue(Q);
        for(int j = 0;j<G->vexNum;j++){
            if(G->arcs[i][j]==1&&!visited[j]){
                printf("%c\t",G->vexs[j]);
                visited[j] = 1;
                enQueue(Q,j);
            }
        }

    }
}
int main(){
    Graph*G = initGraph(5);
    int *visited = (int*)malloc(sizeof(int)*G->vexNum);
    for(int i= 0 ;i<G->vexNum;i++){
        visited[i] = 0;
    }
    int arcs[5][5]={
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0
    };
    //传入节点和边的情况来创建图
    //也可写(int*)arcs 把二级指针退化为一级指针
    creatGraph(G,"ABCDE",&arcs[0][0]);
    DFS(G,visited,0);
    printf("\n");
    for(int i= 0 ;i<G->vexNum;i++){
        visited[i] = 0;
    }
    DFS(G,visited,0);

    return 0;
}