/* C++ | greedy: floor tiling. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int d[1000010];
long long cnt = 0;

// 计算[l, r]区间内的最小天数
void qwq(int l, int r, int base) {//引入base(已经削减过的部分，就不用去改变数组的元素了) 
    if (l > r) return; // 区间无效，直接返回
    if (l == r) {
        // 单个元素：需要的天数是当前深度减去基准值（已削减的部分）
        cnt += d[l] - base;
        return;
    }
    
    // 找到当前区间内的最小值（用于确定能统一削减的层数）
    int min_val = d[l];
    for (int i = l; i <= r; i++) {
        if (d[i] < min_val) {
            min_val = d[i];
        }
    }
    
    // 统一削减 (min_val - base) 层，这部分是当前区间能共享的天数
    cnt += min_val - base;
    
    // 按最小值位置拆分区间（最小值处会先减到0，拆分后递归处理左右）
    int last = l;
    for (int i = l; i <= r; i++) {
        if (d[i] == min_val) {
            // 递归处理[last, i-1]区间，基准值更新为min_val
            qwq(last, i - 1, min_val);
            last = i + 1; // 下一段的起点
        }
    }
    // 处理最后一段（如果有）
    qwq(last, r, min_val);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    qwq(0, n - 1, 0); // 初始基准值为0（还未削减）
    printf("%lld", cnt);
    return 0;
}


/*
假设现在有一个坑，但旁边又有一个坑。
你肯定会选择把两个同时减1；
那么小的坑肯定会被大的坑“带着”填掉。
大的坑也会减少a[i]-a[i-1]的深度，可以说是“免费的”；*/
#include <stdio.h>
const int MAXN = 1000010;
int d[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    long long cnt = 0;
    // 初始时前一个深度为0，从第一个区域开始遍历
    int pre = 0;
    for (int i = 0; i < n; i++) {
        // 如果当前深度大于前一个深度，差值需要计入总天数
        if (d[i] > pre) {
            cnt += d[i] - pre;
        }
        pre = d[i];
    }
    printf("%lld\n", cnt);
    return 0;
}

/*递归版：如果a[i]<=a[i-1]，那么在填a[i-1]时就可以顺便把a[i]填上，这样显然更优，所以f[i]=f[i-1];

否则的话，那么在填a[i-1]时肯定要尽量把a[i]一块填上，a[i]剩余的就单独填。。

所以，f[i]=f[i-1]+(a[i]-a[i-1])。*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,a[110000],f[110000];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]<=a[i-1])
			f[i]=f[i-1];
		else f[i]=f[i-1]+(a[i]-a[i-1]);
	}
	cout<<f[n]<<endl;
	return 0;
}

