/* C | sorting: largest number. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 交换两个指针的位置（修正swap）
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// 排序规则：比较a+b和b+a的大小（修正排序逻辑）
void px(char **num, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {  // 修正冒泡循环条件
            // 拼接两个字符串
            int len1 = strlen(num[j]);
            int len2 = strlen(num[j+1]);
            char *ab = (char *)malloc(len1 + len2 + 1);
            char *ba = (char *)malloc(len1 + len2 + 1);
            strcpy(ab, num[j]);
            strcat(ab, num[j+1]);
            strcpy(ba, num[j+1]);
            strcat(ba, num[j]);
            
            // 若ab < ba，则交换j和j+1
            if (strcmp(ab, ba) < 0) {
                swap(&num[j], &num[j+1]);
            }
            free(ab);
            free(ba);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char **num = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        // 先分配内存（假设每个数不超过20位）
        num[i] = (char *)malloc(20);
        scanf("%s", num[i]);
    }
    px(num, n);
    // 输出结果
    for (int i = 0; i < n; i++) {
        printf("%s", num[i]);
    }
    // 释放内存
    for (int i = 0; i < n; i++) {
        free(num[i]);
    }
    free(num);
    return 0;
}
