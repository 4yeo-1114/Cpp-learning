/* C++ | divide and conquer: tromino tiling. */
#include<cstdio>
typedef long long ll;
ll x,y,len; int k;
ll fun(int k)
{
    ll sum=1;
    for(int i=1;i<=k;++i) sum*=2;
    return sum;
}
// a,b是当前左上角 
void solve(ll x,ll y,ll a,ll b,ll l)
{  
    if(l==1) return;
    if(x-a<=l/2-1 && y-b<=l/2-1)
    { // 这些if条件具体要不要-1 就看最简单的l=2 
        printf("%lld %lld 1\n",a+l/2,b+l/2);
        //对一个大块做完之后就分成四个小块 以此类推 
        solve(x,y,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else if(x-a<=l/2-1 && y-b>l/2-1)
    {
        printf("%lld %lld 2\n",a+l/2,b+l/2-1);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(x,y,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else if(x-a>l/2-1 && y-b<=l/2-1)
    {
        printf("%lld %lld 3\n",a+l/2-1,b+l/2);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(x,y,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else
    {
        printf("%lld %lld 4\n",a+l/2-1,b+l/2-1);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(x,y,a+l/2,b+l/2,l/2);
    }
}
int main()
{
    scanf("%d %lld %lld",&k,&x,&y);
    len=fun(k);
    solve(x,y,1,1,len);
    return 0;
}


