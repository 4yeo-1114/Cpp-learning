#include <stdio.h>
#include <stdlib.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int *a = (int *)malloc(sizeof(int) * m);
    int *b = (int *)malloc(sizeof(int) * n);
    int *c = (int *)malloc(sizeof(int) * (m + n));
    for(int i = 0;i<m;i++){
        scanf("%d",&a[i]);
    }
    
    for(int i= 0;i<n;i++){
        scanf("%d",&b[i]);
    }

    int i = 0,j=0,k=0;
    while(i<m&&j<n){
        if(a[i]<=b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
    while(i<m){
        c[k++] = a[i++];
    }
    while(j<n){
        c[k++] = b[j++];
    }
    // 输出合并后的数组 c，空格分隔
    for (int idx = 0; idx < k; idx++) {
        printf("%d%c", c[idx], (idx == k - 1 ? '\n' : ' '));
    }

    // 释放动态内存
    free(a);
    free(b);
    free(c);
    return 0;
}