/* C | graph: prim. */
#include <stdio.h>
#include <stdlib.h>
//图顶点之间不同 那么领接矩阵的值为MAX 若顶点为他本身 那么值为零
#define MAX 213940

typedef struct Graph{
    char *vexs;//节点
    int** arcs;//边
    int vexNum; // 节点数量
    int arcNum;//边的数量

}Graph;


typedef struct Edge{
    char vex;
    int weight;
}Edge;
//edge其实就是一个动态的情报本 edge[i]记录了从vex(起点)到i节点的路程weight
//当edge.weight=0 代表了当前顶点加入U集合中
Edge* initEdge(Graph*G,int index){
    Edge* edge = (Edge*)malloc(sizeof(Edge)*G->vexNum);
    for(int i = 0;i<G->vexNum;i++){
        edge[i].vex = G->vexs[index];
        edge[i].weight = G->arcs[index][i];
    }
    return edge;
}

//找最小边
int getMinEdge(Edge* edge,Graph *G){
    int index;
    int min = MAX;
    for(int i  = 0;i<G->vexNum;i++){
        if(edge[i].weight!=0&&min>edge[i].weight){
            min = edge[i].weight;
            index  = i;
        }
    }
    return index;
}

void prim(Graph*G,int index){
    Edge*edge = initEdge(G,index);
    int min = MAX;
    //找n-1次 因为第一个节点直接加进来了
    for(int i = 0;i<G->vexNum-1;i++){
        //找到最近的一个点
        min = getMinEdge(edge,G);
        //edge[min]即为源头 G->vexs[min]才是我们getmin到的点
        printf("V%c -> V%c,weight = %d",edge[min].vex,G->vexs[min],edge[min].weight);
        //发现去min最短 就把这一点加入 即把weight改为零
        edge[min].weight = 0 ;
        //既然这一点加入了我们 我们就看这一点能不能为我们的情报本做更新
        for(int j = 0;j<G->vexNum;j++){
            //发现有更小的路径 要更新起点和路程
            if(edge[j].weight!=0&&G->arcs[min][j]<edge[j].weight){
                edge[j].weight = G->arcs[min][j];
                edge[j].vex = G->vexs[min];
            }
           
        }
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
            if(G->arcs[i][j]!=0&&G->arcs[i][j]!=MAX){
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
        if(G->arcs[index][i] >0&&G->arcs[index][i]!=MAX&&!visited[i]){
            DFS(G,visited,i);
        }
    }
    //当 for 循环结束时，函数自然执行完毕，自动 return 回上一层
    //所以不需要写什么终止条件
}

int main(){
    Graph*G = initGraph(6);
    int *visited = (int*)malloc(sizeof(int)*G->vexNum);
    for(int i= 0 ;i<G->vexNum;i++){
        visited[i] = 0;
    }
    int arcs[6][6]={
        0,6,1,5,MAX,MAX,
        6,0,5,MAX,3,MAX,
        1,5,0,5,6,4,
        5,MAX,5,0,MAX,2,
        MAX,3,6,MAX,0,6,
        MAX,MAX,4,2,6,0
    };
    //传入节点和边的情况来创建图
    //也可写(int*)arcs 把二级指针退化为一级指针
    creatGraph(G,"123456",&arcs[0][0]);
    //DFS(G,visited,0);
    prim(G,0);
    printf("\n");
    return 0;
}