/* C | graph: dijkstra. */
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

//找到d数组中的最小值 并且要还未找到最小路径的
int getmin(int *d,int *s,Graph* G){
    int min  = MAX;
    int index  =-1;
    for(int i  =0;i<G->vexNum;i++){
        if(!s[i]&&d[i]<min){
            min = d[i];
            index  =i;
        }
    }
    return index;
}

void dijstra(Graph* G,int index){
    //index表示起点

    //s记录有没有找到最短路径
    //p记录找到到该点最短路径的前驱节点
    //d记录最短路径长度
    int *s = (int*)malloc(sizeof(int)*G->vexNum);
    int *p = (int*)malloc(sizeof(int)*G->vexNum);
    int *d = (int*)malloc(sizeof(int)*G->vexNum);
    //对s初始化
    for(int i = 0;i<G->vexNum;i++){
        if(i==index){
            s[i] = 1;
        }
        else{
            s[i]  =0;
        }
    }
    //对p初始化
     for(int i = 0;i<G->vexNum;i++){
        //起点能直接到这个点 最短路径的前驱节点就是起点
       if(G->arcs[index][i]>0&&G->arcs[index][i]!=MAX){
        p[i] = index;
       }
       else{
        p[i] = -1;
       }
    }
    //对d初始化
     for(int i = 0;i<G->vexNum;i++){
        //起点能直接到这个点 
       if(G->arcs[index][i]>0&&G->arcs[index][i]!=MAX){
       d[i] = G->arcs[index][i];
       }
       else{
        d[i]  =MAX;
       }
       if(i==index){
        d[i] = 0;
       }
    }
    for(int i = 0;i<G->vexNum-1;i++){
        //取到最小值
        int index = getmin(d,s,G);
        //标记为找到最短路径
        s[index] = 1;
        //再以该点为中转点去更新我们的数组
        for(int j  = 0 ;j<G->vexNum;j++){
            if(!s[j]&&d[index]+G->arcs[index][j]<d[j]){
                d[j]  = d[index]+G->arcs[index][j];
                p[j]  =index;
            }
        }
    }
    //输出结果
    for(int i = 0;i<G->vexNum;i++){
        printf("%d %d %d\n",s[i],p[i],d[i]);
    }
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
    return 0;
}