/* C++ | greedy: barn repair. */
#include<cstdio> 
#include<algorithm> 
#include<iostream> 
#define MAXN 205
using namespace std; 
int m,s,c,ans;
int a[MAXN],C[MAXN];
bool cmp(int x,int y)
{
    return x>y;//降序排列 
}
int main() 
{ 
    scanf("%d %d %d",&m,&s,&c);
    for(int i=1;i<=c;i++)
        scanf("%d",&a[i]);
    if(m>c) { //特判，如果木板数大于牛数，那么每只牛可以有一块木板
        printf("%d\n",c);
        return 0;
    }
    sort(a+1,a+c+1);
    ans=a[c]-a[1]+1;//假设只有一块木板连续地铺着
    for(int i=2;i<=c;i++)
        C[i-1]=a[i]-a[i-1];
    sort(C+1,C+c,cmp);//左闭右开 
    for(int i=1;i<=m-1;i++)//减去差最大的//将木板从差最大的地方减去
        ans=ans-C[i]+1;
    printf("%d\n",ans);
} 
//https://www.luogu.com.cn/problem/P1209

