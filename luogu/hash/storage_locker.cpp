/* C++ | hash: storage locker. */
#include <cstdio> 
#include <map>
using namespace std;
int n,q,i,j,k;
int cnt;
map<long long,int> p;//用map映射 避免了用数组时大量空间被浪费 
int main(){
	scanf("%d %d",&n,&q);
	while(q--){
		scanf("%d %d %d",&cnt,&i,&j);
		if(cnt==1){
			scanf("%d",&k);
			//把二维的数据一维化！（i，j）变为i*1000000+j 
			p[i*1000000+j]  = k;
		}
		else{
			printf("%d\n",p[i*1000000+j]);
		}
	}
	return 0;
	
}
