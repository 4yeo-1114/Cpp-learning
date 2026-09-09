/* C++ | tree: huffman tree. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // 用于INT_MAX

// 哈夫曼树结点结构定义
typedef struct {
    int weight;      // 结点的权值
    int parent;      // 双亲结点的下标，0表示无双亲
    int lchild;      // 左孩子结点的下标，0表示无左孩子
    int rchild;      // 右孩子结点的下标，0表示无右孩子
} HTNode, *HuffmanTree;

// 选择两个双亲为0且权值最小的结点
// HT：哈夫曼树数组；n：当前参与选择的结点数量上限；s1、s2：用于存储选中的两个结点下标
void Select(HuffmanTree HT, int n, int *s1, int *s2) {
    int i;
    int min1 = INT_MAX;  // 存储第一个最小权值，初始化为int类型最大值
    int min2 = INT_MAX;  // 存储第二个最小权值，初始化为int类型最大值
    *s1 = *s2 = 0;       // 初始化为0，表示未选中

    for (i = 1; i <= n; i++) {
        if (HT[i].parent == 0) {  // 仅考虑双亲为0的结点（即未被合并的结点）
            if (HT[i].weight < min1) {  // 找到比min1更小的权值
                min2 = min1;            // 原来的min1变为第二小
                *s2 = *s1;              // 原来的s1变为第二小的下标
                min1 = HT[i].weight;    // 更新min1为当前最小权值
                *s1 = i;                // 更新s1为当前最小权值的下标
            } else if (HT[i].weight < min2) {  // 找到比min2小但比min1大的权值
                min2 = HT[i].weight;          // 更新min2为当前权值
                *s2 = i;                      // 更新s2为当前权值的下标
            }
        }
    }
}

// 构建哈夫曼树
// HT：哈夫曼树（引用传递，用于修改其指向）；n：叶子结点的数量；weights：存储叶子结点权值的数组
void CreateHuffmanTree(HuffmanTree &HT, int n, int weights[]) {
    if (n <= 1) return;  // 只有一个结点时无需构建哈夫曼树
    int m = 2 * n - 1;   // 哈夫曼树的总结点数（叶子结点数n，非叶子结点数n-1）

    // 动态申请m+1个结点的内存（0号单元未使用）
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    if (HT == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }

    int i, s1, s2;

    // 初始化所有结点的双亲、左孩子、右孩子为0
    for (i = 1; i <= m; i++) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    // 给前n个叶子结点赋值权值
    for (i = 1; i <= n; i++) {
        HT[i].weight = weights[i - 1];
    }

    // 循环n-1次，合并创建新的非叶子结点
    for (i = n + 1; i <= m; i++) {
        Select(HT, i - 1, &s1, &s2);  // 选择两个权值最小的结点

        // 将选中的两个结点的双亲设为当前新结点i
        HT[s1].parent = i;
        HT[s2].parent = i;

        // 设置新结点i的左右孩子为选中的两个结点（新节点就是非叶子节点） 
        HT[i].lchild = s1;
        HT[i].rchild = s2;

        // 新结点i的权值为两个孩子权值之和
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

// 计算哈夫曼树的带权路径长度（WPL）
// HT：哈夫曼树；n：叶子结点的数量
int CalculateWPL(HuffmanTree HT, int n) {
    int wpl = 0;          // 存储带权路径长度
    int m = 2 * n - 1;    // 哈夫曼树的总结点数
    for (int i = 1; i <= m; i++) {
        // 判断是否为叶子结点（无左右孩子）
        if (HT[i].lchild == 0 && HT[i].rchild == 0) {
            int depth = 0;  // 存储当前叶子结点的路径长度
            int j = i;     // 用于向上遍历双亲结点
            while (HT[j].parent != 0) {  // 当存在双亲结点时
                depth++;                 // 路径长度加1
                j = HT[j].parent;        // 指向双亲结点
            }
            wpl += HT[i].weight * depth; // 累加“权值×路径长度”
        }
    }
    return wpl;
}

// 释放哈夫曼树的内存
// HT：哈夫曼树（引用传递，释放后置为NULL）
void FreeHuffmanTree(HuffmanTree &HT) {
    if (HT != NULL) {
        free(HT);
        HT = NULL;
    }
}

int main() {
    // 测试数据：题目中的权值数组
    int weights[] = {5, 29, 7, 8, 14, 23, 3, 11};
    int n = sizeof(weights) / sizeof(weights[0]);  // 计算叶子结点数量
    HuffmanTree HT = NULL;                         // 哈夫曼树指针初始化

    CreateHuffmanTree(HT, n, weights);  // 构建哈夫曼树
    int wpl = CalculateWPL(HT, n);      // 计算带权路径长度
    printf("哈夫曼树的带权路径长度（WPL）为：%d\n", wpl);

    FreeHuffmanTree(HT);  // 释放内存
    return 0;
}
