#include <stdio.h>
#include <stdlib.h>

typedef struct String {
    int len;
    char *data; // data[1] ~ data[len] 存有效字符，data[0] 闲置
} String;

String* initString() {
    String *s = (String*)malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}

void stringAssign(String *s, char *str) {
    if (s->data) {
        free(s->data);
    }
    int len = 0;
    char *temp = str;
    while (*temp != '\0') {
        len++;
        temp++;
    }
    s->len = len;
    if (len == 0) {
        s->data = NULL;
        return;
    }
    // 分配 len + 2 大小：data[1]~data[len] 存字符，data[len+1] 存 '\0'
    s->data = (char*)malloc(sizeof(char) * (len + 2));
    for (int i = 1; i <= len; i++) {
        s->data[i] = str[i - 1];
    }
    s->data[len + 1] = '\0';
}

// 1 索引求 next 数组
int* getNext(String *s) {
    // next[1] ~ next[s->len]，因此分配 s->len + 1 个空间
    int *next = (int*)malloc(sizeof(int) * (s->len + 1));
    int i = 1;
    int j = 0;
    next[1] = 0; // 严蔚敏教材标准：首字符失配置 0

    while (i < s->len) {
        if (j == 0 || s->data[i] == s->data[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j]; // 回退
        }
    }
    return next;
}

// 1 索引 KMP 匹配函数
int kmpMatch(String *master, String *sub, int *next) {
    int i = 1; // 主串从 1 开始
    int j = 1; // 模式串从 1 开始

    while (i <= master->len && j <= sub->len) {
        if (j == 0 || master->data[i] == sub->data[j]) {
            i++;
            j++;
        } else {
            j = next[j]; // 模式串回退
        }
    }

    if (j > sub->len) {
        // 匹配成功，返回在主串中的起始下标（1-based）
        return i - sub->len;
    } else {
        return 0; // 0 表示匹配失败
    }
}



void printNext(int *next, int len) {
    for (int i = 1; i <= len; i++) {
        printf(i == 1 ? "%d" : " -> %d", next[i]);
    }
    printf("\n");
}

int main() {
    String *s = initString();
    String *s1 = initString();
    stringAssign(s, "ABABA");
    stringAssign(s1, "ABA");

    int *next = getNext(s1);
    printf("next array: ");
    printNext(next, s1->len);

    int pos = kmpMatch(s, s1, next);
    if (pos > 0) {
        printf("Match success at index: %d\n", pos);
    } else {
        printf("Match fail\n");
    }

    // 正确释放内存
    free(s->data);
    free(s);
    free(s1->data);
    free(s1);
    free(next);

    return 0;
}