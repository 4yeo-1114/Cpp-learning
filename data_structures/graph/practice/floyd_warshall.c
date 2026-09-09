/* C | graph: floyd warshall. */
#include <stdio.h>
#include <stdlib.h>
#define MAX 1234235
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
            if(G->arcs[i][j]!=0 && G->arcs[i][j]!=MAX){
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
        if(G->arcs[index][i]>0&&G->arcs[index][i]!=MAX&&!visited[i]){
            DFS(G,visited,i);
        }
    }
    //当 for 循环结束时，函数自然执行完毕，自动 return 回上一层
    //所以不需要写什么终止条件
}
void floyd(Graph *G){
    int n = G->vexNum;
    //d数组记录长度
    int **d = (int **)malloc(n * sizeof(int *));
    //记录前驱
    int **p = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        d[i] = (int *)malloc(n * sizeof(int));
        p[i] = (int *)malloc(n * sizeof(int));
    }
    //初始化两个数组
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            d[i][j] = G->arcs[i][j];
            if(G->arcs[i][j]>0&&G->arcs[i][j]!=MAX){
                p[i][j] = i;
            }
            else{
                p[i][j] = -1;
            }
            
        }
    }
    //暴力遍历每个i 以i为中转 看是否比直接从j到k近 如果是进行更新
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                if(d[j][i]+d[i][k]<d[j][k]){
                    d[j][k] = d[j][i]+d[i][k];
                    p[j][k] = p[i][k];
                }
            }
        }
    }
}

int main(){
    Graph*G = initGraph(4);
    int *visited = (int*)malloc(sizeof(int)*G->vexNum);
    for(int i= 0 ;i<G->vexNum;i++){
        visited[i] = 0;
    }
    int arcs[4][4]={
        0,1,MAX,3,
        1,0,2,2,
        MAX,2,0,8,
        3,2,8,0
    };
    //传入节点和边的情况来创建图
    //也可写(int*)arcs 把二级指针退化为一级指针
    creatGraph(G,"1234",&arcs[0][0]);
    DFS(G,visited,0);
    printf("\n");
    return 0;
}