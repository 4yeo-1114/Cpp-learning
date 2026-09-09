/* C | matrix: reshape. */
#include <stdio.h>
#include <stdlib.h>

// 矩阵重塑函数
int** matrixReshape(int** mat, int matRowSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    // 计算原矩阵的总元素个数
    int m = matRowSize;
    int n = matColSize[0];
    // 判断重塑是否可行
    if (m * n != r * c) {
        // 不可行，返回原矩阵相关信息
        *returnSize = matRowSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    // 可行，初始化返回矩阵的大小信息
    *returnSize = r;
    *returnColumnSizes = (int*)malloc(r * sizeof(int));//这是一个数组 用于记录每一行的列数 所以有r项 
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
    }

    // 分配返回矩阵的内存
    int** ans = (int**)malloc(r * sizeof(int*)); //给二维数组分配内存！ 
    for (int i = 0; i < r; i++) {
        ans[i] = (int*)malloc(c * sizeof(int)); //再给每一行分配内存 
    }

    // 进行矩阵重塑
    for (int x = 0; x < m * n; x++) {
        // 计算原矩阵中的行和列索引
        int originalRow = x / n;
        int originalCol = x % n;
        // 计算新矩阵中的行和列索引
        int newRow = x / c;
        int newCol = x % c;
        // 赋值
        ans[newRow][newCol] = mat[originalRow][originalCol];
    }

    return ans;
}

// 打印矩阵函数
void printMatrix(int** matrix, int rowSize, int* colSize) {
    printf("[");
    for (int i = 0; i < rowSize; i++) {
        printf("[");
        for (int j = 0; j < colSize[i]; j++) {
            printf("%d", matrix[i][j]);
            if (j < colSize[i] - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < rowSize - 1) {
            printf("\n");  // 输出完一行就换行 
        }
    }
    printf("]\n");
}

int main() {
    // 示例：原矩阵 mat = [[1,2], [3,4]]
    int matRowSize = 2;
    int matColSizeArr[] = {2, 2};
    int* matColSize = matColSizeArr;
    int** mat = (int**)malloc(matRowSize * sizeof(int*));
    mat[0] = (int*)malloc(2 * sizeof(int));
    mat[1] = (int*)malloc(2 * sizeof(int));
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    int r = 1, c = 4;
    int returnSize;
    int* returnColumnSizes;

    int** result = matrixReshape(mat, matRowSize, matColSize, r, c, &returnSize, &returnColumnSizes);

    printf("原矩阵：\n");
    printMatrix(mat, matRowSize, matColSize);

    printf("重塑后的矩阵（r = %d, c = %d）：\n", r, c);
    printMatrix(result, returnSize, returnColumnSizes);

    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    for (int i = 0; i < matRowSize; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
