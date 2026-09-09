/* C | graph: kruskal. */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define MAX 1234235
//1.维护一个边的数组并排序
//2.判断图是否联通 需要一个辅助数组 记录当前索引的节点属于哪个联通分量


typedef struct Graph{
    char *vexs;//节点
    int** arcs;//边
    int vexNum; // 节点数量
    int arcNum;//边的数量

}Graph;
//维护一个边 以便我们后面排序
typedef struct Edge{
    int start;
    int end;
    int weight;
}Edge;

Edge* initEdge(Graph* G){
    int index  = 0;
    Edge* edge = (Edge*)malloc(sizeof(Edge)*G->arcNum);
    for(int i = 0;i<G->vexNum;i++){
        for(int j = i+1;j<G->vexNum;j++){
            if(G->arcs[i][j]!=MAX){
            edge[index].start = i;
            edge[index].end = j;
            edge[index].weight = G->arcs[i][j];
            index++;
         }  
    }
        
    }
    return edge;
}
//对边进行排序
void sortEdge(Edge* edge,Graph* G){
    Edge temp;
    for(int i = 0;i<G->arcNum-1;i++){
        for(int j = 0;j<G->arcNum-i-1;j++){
            if(edge[j].weight>edge[j+1].weight){
                temp = edge[j];
                edge[j]  = edge[j+1];
                edge[j+1] = temp;

            }
            
        }
    }

}
void kruskal(Graph *G){
    //联通分量数组来判断图有没有联通
    int* connected = (int*)malloc(sizeof(int)*G->vexNum);
    for(int i = 0;i<G->vexNum;i++){
        connected[i] = i;
    }
    Edge* edge  = initEdge(G);
    sortEdge(edge,G);
    for(int i = 0;i<G->arcNum;i++){
        int start = connected[edge[i].start];
        int end = connected[edge[i].end];
        //没联通才可以加入最小生成树
        if(start!=end){
            printf("v%c -> v%c weight= ",G->vexs[edge[i].start],G->vexs[edge[i].end],edge[i].weight);
            //更新联通分量
            for(int j = 0;j<G->vexNum;j++){
                if(connected[j] ==end){
                    connected[j] = start;
                }
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
    DFS(G,visited,0);
    printf("\n");
    kruskal(G);
    return 0;
}