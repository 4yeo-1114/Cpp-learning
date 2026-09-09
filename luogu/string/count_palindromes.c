/* C | string: count palindromes. */
#include <stdio.h>
#include <string.h>

// 统计以left和right为中心的回文子串数量
int expandAroundCenter(char *s, int left, int right, int len) {
    int count = 0;
    while (left >= 0 && right < len && s[left] == s[right]) {
        count++;
        left--;
        right++;
    }
    return count;
}

// 统计字符串s的回文子串总数
int countPalindromicSubstrings(char *s) {
    int len = strlen(s);
    int total = 0;
    for (int i = 0; i < len; i++) {
        // 奇数长度的回文（中心为单个字符）
        total += expandAroundCenter(s, i, i, len);
        // 偶数长度的回文（中心为两个字符）
        total += expandAroundCenter(s, i, i + 1, len);
    }
    return total;
}

int main() {
    int n;
    scanf("%d", &n);
    char str[100]; // 假设字符串长度不超过100
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        printf("%d\n", countPalindromicSubstrings(str));
    }
    return 0;
}
