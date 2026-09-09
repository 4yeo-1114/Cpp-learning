/* C | graph: critical path. */
//AOE网 activity on edge 有向无环图
//事件 顶点
//活动 边

//1 拓扑排序
//2 计算指标
//3 找出关键活动

//事件指标 最早开始时间v 最晚开始时间v
//vi(early)  = Max(vx(early)+weight(x,i))  x是i的前驱
//vi(late)  = Min(vx(late)-weight(i,x))  x是i的后继
//活动指标 最早开始时间l 最晚开始时间l
//l(early)  = vstart(e)  vstart -> vend 中间的边就是活动
//l(late)   = vend(l) - weight

//时间余量 l(late) - l(early) 为0时为关键活动


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
            if(G->arcs[i][j]>0 && G->arcs[i][j]!=MAX){
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
            if(G->arcs[i][j]>0&&G->arcs[i][j]!=MAX)
            //若有以他为尾的边 入度就加一
            inDegrees[j]++;
        }
    }
    return inDegrees;
}

int* topologicalSort(Graph*G){
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
           if( G->arcs[vex][i]>0&&G->arcs[vex][i]>0!=MAX){
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
    return top;
}
//拿到当前节点在拓扑序列中的序号
int getIndex(int *top,Graph *G,int i){
    int j;
    for(j=0;j<G->vexNum;j++){
        if(top[j]==i){
            break;
        }
    }
    return j;
}
void criticalPath(Graph* G){
    int* top = topologicalSort(G);
    int *early = (int*)malloc(sizeof(int)*G->vexNum);
    int *late = (int*)malloc(sizeof(int)*G->vexNum);

    for(int i  =0;i<G->vexNum;i++){
        early[i] = 0;
        late[i] = 0;
    }
    //early 和late中的数组序号都是按拓扑排序来的
    //计算最早发生时间
    //这里的i是按顺序0，1 但是我们关键路径是在拓扑序列上进行的
    //所以要用getIndex函数
    //top[i] 是i在原图中的序号 index是原数组在拓扑排序中的序号
    for(int i  =0;i<G->vexNum;i++){
        int max = 0;
        for(int j = 0;j<G->vexNum;j++){
            if(G->arcs[j][top[i]]>0&&G->arcs[j][top[i]]!=MAX){
                 int index =getIndex(top,G,j);
                if(early[index]+G->arcs[j][top[i]]>max){
                    max  = early[j]+G->arcs[j][top[i]];
                }
            }
        }
        early[i]= max;
    }
    //最后一个节点late  = early
    late[G->vexNum-1] = early[G->vexNum-1];
    for(int i = G->vexNum-2;i>=0;i--){
        int min = MAX;
        for(int j  =0;j<G->vexNum;j++){
            if(G->arcs[top[i]][j]>0&&G->arcs[top[i]][j]!=MAX){
                int index = getIndex(top,G,j);
                if(late[index]-G->arcs[top[i]][j]<min){
                    min  = late[index]-G->arcs[top[i]][j];
                }
            }
        }
        late[i]  = min;
    } 

    //算边的时间余量 输出为0的
    for(int i  =0;i<G->vexNum;i++){
        for(int j = 0;j<G->vexNum;j++){
            if(G->arcs[i][j]>0&&G->arcs[i][j]!=MAX){
                if(late[j]-G->arcs[i][j]==early[i]){
                //要拿到在原图中的索引
                int start = getIndex(top,G,i);
                int end = getIndex(top,G,j);
                    printf("start = %d end = %d",i,j);
                }
            }
        }
    }

}
int main(){
    Graph*G = initGraph(6);
    int *visited = (int*)malloc(sizeof(int)*G->vexNum);
    for(int i= 0 ;i<G->vexNum;i++){
        visited[i] = 0;
    }
    int arcs[6][6]={
        MAX,1,6,1,MAX,MAX,
        MAX,34,4,MAX,6,MAX,
        6,1,4,MAX,1,6,
        MAX,MAX,5,MAX,1,5,
        MAX,MAX,MAX,MAX,MAX,MAX,
        6,2,6,1,1,MAX

    };
    //传入节点和边的情况来创建图
    //也可写(int*)arcs 把二级指针退化为一级指针
    creatGraph(G,"123456",&arcs[0][0]);
    DFS(G,visited,0);
    printf("\n");
     criticalPath(G);
    return 0;
}