/* C++ | tree: huffman codes. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// 哈夫曼树结点结构
typedef struct {
    int weight;      // 权值
    int parent;      // 双亲下标
    int lchild;      // 左孩子下标
    int rchild;      // 右孩子下标
} HTNode, *HuffmanTree;

// 哈夫曼编码表结构（存储每个字符的编码字符串）
typedef char** HuffmanCode;

// 选择两个双亲为0且权值最小的结点
void Select(HuffmanTree HT, int n, int *s1, int *s2) {
    int i, min1 = INT_MAX, min2 = INT_MAX;
    *s1 = *s2 = 0;
    for (i = 1; i <= n; i++) {
        if (HT[i].parent == 0) {  // 仅考虑未被合并的结点（双亲为0）
            if (HT[i].weight < min1) {
                min2 = min1;
                *s2 = *s1;
                min1 = HT[i].weight;
                *s1 = i;
            } else if (HT[i].weight < min2) {
                min2 = HT[i].weight;
                *s2 = i;
            }
        }
    }
}

// 构建哈夫曼树
void CreateHuffmanTree(HuffmanTree &HT, int n, int weights[]) {
    if (n <= 1) return;
    int m = 2 * n - 1;  // 哈夫曼树总结点数（叶子n个，非叶子n-1个）
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));  // 0号单元未用

    // 初始化所有结点的双亲、左右孩子为0
    for (int i = 1; i <= m; i++) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    // 给前n个叶子结点赋值权值
    for (int i = 1; i <= n; i++) {
        HT[i].weight = weights[i - 1];
    }

    // 循环n-1次，合并创建新结点
    for (int i = n + 1; i <= m; i++) {
        int s1, s2;
        Select(HT, i - 1, &s1, &s2);  // 选两个最小权值的结点
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;  // 新结点权值为子结点权值和
    }
}

// 生成哈夫曼编码
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) {
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));  // 分配n个字符的编码表空间
    char *cd = (char*)malloc(n * sizeof(char));        // 分配临时编码存储数组（长度为n）
    cd[n - 1] = '\0';  // 编码结束符

    for (int i = 1; i <= n; i++) {  // 逐个字符生成编码
        int start = n - 1;  // start指向编码结束符的前一位（初始为编码末尾位置）
        int c = i;          // 当前待编码的叶子结点下标
        int f = HT[i].parent;  // 当前结点的双亲下标

        while (f != 0) {  // 回溯到根结点（双亲为0时结束）
            --start;  // 编码位置向前移动一位
            if (HT[f].lchild == c) {  // 当前结点是双亲的左孩子，编码为'0'
                cd[start] = '0';
            } else {  // 当前结点是双亲的右孩子，编码为'1'
                cd[start] = '1';
            }
            c = f;    // 向上回溯到双亲结点
            f = HT[f].parent;
        }

        // 为第i个字符分配编码空间，并复制临时编码cd到HC[i]
        HC[i] = (char*)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);  // 释放临时编码数组
}

// 打印哈夫曼编码
void PrintHuffmanCode(HuffmanCode HC, int n, int weights[]) {
    printf("字符权值\t哈夫曼编码\n");
    for (int i = 1; i <= n; i++) {
        printf("%d\t\t%s\n", weights[i - 1], HC[i]);
    }
}

// 释放哈夫曼树和编码表的内存
void FreeHuffman( HuffmanTree &HT, HuffmanCode &HC, int n) {
    if (HT != NULL) {
        free(HT);
        HT = NULL;
    }
    if (HC != NULL) {
        for (int i = 1; i <= n; i++) {
            if (HC[i] != NULL) {
                free(HC[i]);
            }
        }
        free(HC);
        HC = NULL;
    }
}

int main() {
    int weights[] = {5, 29, 7, 8, 14, 23, 3, 11};  // 题目中的权值数组
    int n = sizeof(weights) / sizeof(weights[0]);  // 叶子结点数量
    HuffmanTree HT = NULL;
    HuffmanCode HC = NULL;

    CreateHuffmanTree(HT, n, weights);  // 构建哈夫曼树
    CreateHuffmanCode(HT, HC, n);       // 生成哈夫曼编码
    PrintHuffmanCode(HC, n, weights);   // 打印编码

    FreeHuffman(HT, HC, n);  // 释放内存
    return 0;
}
