/* C++ | dp: order dishes. */
#include <stdio.h>
int a[105];  // 菜品种类N≤100，数组大小足够
int f[105][10005] = {0};  // M≤10000，数组大小足够
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 关键初始化：前0种菜品凑0元，有1种方案
    f[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {  // j从0开始遍历（虽然j=0只有初始化的情况有效，但逻辑更统一）
            if (j < a[i]) {
                f[i][j] = f[i-1][j];  // 不选第i种菜品，方案数继承自前i-1种
            } else {
                // 选或不选第i种菜品，方案数相加
                f[i][j] = f[i-1][j] + f[i-1][j - a[i]];
            }
        }
    }

    printf("%d", f[n][m]);
    return 0;
}
//用一维数组
int f[10005];
int  main(){
	int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    f[0] = 1;//没钱就一种
	for(int i = 1;i<=n;i++){ 
		for(int j = m;j>=m-a[i];j--){//递减 如果钱不够买第i盘菜，那么j元的方案就保持i-1盘菜的结果
		// 否则 加上f[j-a[i]] 表示我可以买这第i盘菜或者不买（所以是+=）。 
			f[j] += f[j-a[i]];
		}
	} 
	printf("%d",f[m]);
} 
//递归 f[i][j]表示点第i盘菜时（必须点）（这样才可以把情况全递归遍）还剩j元 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL f[105][10005],n,m,v[105],ans;
LL dfs(LL c,LL k)
{
    if(f[c][k])return f[c][k];
    if(v[c]>k)return 0;
    if(v[c]==k)return 1;
    for(LL i=c+1;i<=n;i++)f[c][k]+=dfs(i,k-v[c]);
    return f[c][k];
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++)scanf("%lld",&v[i]);
    for(LL i=1;i<=n;i++)ans+=dfs(i,m);
    printf("%lld\n",ans);
    return 0;
}
 
//重写
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[110][100050],n,m,v[110],ans;
ll dsf(int c,int j){ //第c盘菜还剩j元 
	if(f[c][j]) return f[c][j];
	if(v[c] == j) return 1;
	if(v[c]>j) return 0;
	//如果j>v[c] 就可以往后点，递归记得钱要变少 
	for(int i = c+1;i<=n;i++) f[c][j] += dfs(i,j-v[c]);
	return f[c][j]; //记忆化搜索 	 
}
int main(){
	scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++)scanf("%lld",&v[i]);
    for(ll i=1;i<=n;i++) ans += dfs(i,j);//从第i盘菜开始点的情况加起来
	printf("lld",ans);
	return 0; 
}
