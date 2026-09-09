/* C | simulation: toy puzzle. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct People {
    int direct;  // 0 顺时针，1 逆时针
    char role[20];
};

struct Order {
    int side;  // 0 左边，1 右边
    int num;
};

int main() {
    // 关闭输入输出缓冲，大幅提升效率
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    int n, m;
    // 使用 faster input 方式读取
    scanf("%d %d", &n, &m);

    // 动态分配内存，适应更大的输入规模
    struct People* s = (struct People*)malloc(n * sizeof(struct People));
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &s[i].direct, s[i].role);
    }

    struct Order* k = (struct Order*)malloc(m * sizeof(struct Order));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &k[i].side, &k[i].num);
    }

    int current = 0;
    for (int j = 0; j < m; j++) {
        int step = k[j].num % n;  // 取模减少无效循环（如移动n步等价于0步）
        if (step == 0) continue;  // 跳过0步移动

        if (s[current].direct == 0) {  // 顺时针
            if (k[j].side == 0) {  // 左边
                current = (current - step + n) % n;
            } else {  // 右边
                current = (current + step) % n;
            }
        } else {  // 逆时针
            if (k[j].side == 0) {  // 左边
                current = (current + step) % n;
            } else {  // 右边
                current = (current - step + n) % n;
            }
        }
    }

    printf("%s\n", s[current].role);

    // 释放动态内存
    free(s);
    free(k);
    return 0;
}

