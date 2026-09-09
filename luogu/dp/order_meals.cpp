/* C++ | dp: order meals. */
#include <stdio.h>
#include <stdlib.h>
int a[105];//储存价格 
int f[1000][1000] = {0};//f[i][j] 就是点i盘菜刚好花j元 
int main(){
	int n,m;//n道菜 m元 
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i =0;i<=n;i++ ) 
	   f[i][0] = 1;//初始化 没菜没钱也是1种 
	for(int i =1;i<=n;i++){
		for(int j = 0;j<=m;j++){
			if(j < a[i])  f[i][j] = f[i-1][j];//如果不够点目前这盘菜 方案就和点i-1盘一样 
			else{
				f[i][j] = f[i-1][j] + f[i-1][j-a[i]];//可以不点（f[i-1][j]） 也可以点（f[i-1][j-a[i]]） 
		        //如果刚好j == a[i] 那么点了这盘菜方案就剩一种即f[i-1][0] = 1;所以前面要初始化 
		
			} 
		}
	}
	printf("%d",f[n][m]);
	return 0;
} 
// 改为一维数组
int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	f[0] =1; //初始化为1 不然结果永远是0 
	for(int i = 1;i<=n;i++){
		//为什么可以用一维 因为对每一个更新的i下的j循环f[j]其实就是i-1时的值所以可以直接+= 
		//若j<a[i]f(j)就保持上一轮的结果所以不用理 所以反着来 
		for(int j = m;j>=a[i];j--){
			f[j] += f[j-a[i]]; 
		} 
	}
	cout<<f[m];
	return 0;
} 


//记忆化搜索
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL f[105][10005],n,m,v[105],ans;
LL dfs(LL c,LL k)//c表示当前盘 k表示目前有多少钱 
{
    if(f[c][k])return f[c][k];
    if(v[c]>k)return 0;
    if(v[c]==k)return 1;//刚好够买 就加一
	//钱多了 就买下再向后买 依旧遍历后面所有的起点 
    for(LL i=c+1;i<=n;i++)f[c][k]+=dfs(i,k-v[c]);
    return f[c][k];
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++)scanf("%lld",&v[i]);
    //遍历所有的起点 
    for(LL i=1;i<=n;i++)ans+=dfs(i,m);
    printf("%lld\n",ans);
    return 0;
}


//dp：
// 确定初始情况
//确定递推关系 
