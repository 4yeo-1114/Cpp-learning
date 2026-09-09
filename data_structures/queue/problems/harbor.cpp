/* C++ | queue: harbor. */
#include <bits/stdc++.h>
using namespace std;
int ans,x,t,num[1000000];
typedef struct{
	int x;
	int t;
}node;
queue<node> q;
int main(){
	int n,k ;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>t>>k;
	    for(int j = 0;j<k;j++){
	    	cin>>x;
	    	q.push({x,t});
	    	ans+=(++num[x]==1);
		}
		for(node h=q.front();q.size()&&h.t+86400<=t;q.pop(),h=q.front()){
			ans-=(--num[h.x]==0);
		}
		cout<<ans<<endl; 
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int x;
	int t;
}node;
int ans,x,t;
//num桶来记录每个国家有多少人 当刚好为一个人时ans++为零人时ans--； 
int num[100001];
//用结构体数组模拟队列 当队首的时间不合要求时 left（队头指针）++ 桶也对应改变 
node q[300001]; 
int main(){
	int n;
	int t,k;
	int  p =0;
	int  left = 0; 
	scanf("%d", &n);
	for(int i = 0;i<n;i++){
		//输入当前船只的时间，人数。 
		scanf("%d %d",&t,&k);
		for(int j = 0;j<k;j++){
			scanf("%d", &x);
			//入队 
			q[p].x = x;
            q[p].t = t;
            p++;
			ans+=(++num[x]==1);
		}
		//出队 
		for(;left<p&&q[left].t+86400<=t;left++){
				ans-=(--num[q[left].x]==0);
			}
		printf("%d\n",ans);
	}
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#define limit 86400
//typedef struct{
//	int time;
//	int num;
//	int p[100010];
//}ship;
//int main(){
//	int n;
//	scanf("%d", &n);
//    ship *s = (ship*)malloc(sizeof(ship)*n);
//    for(int i  = 0;i<n;i++){
//    	scanf("%d %d",&s[i].time,&s[i].num);
//    	for(int j = 0;j<s[i].num;j++){
//    		scanf("%d",&s[i].p[j]);
//		}
//	} 
//	//滑动窗口 
//	int left = 0;
//	int right = 0;
//	bool flag = 0;
//	int ans = 0 ;
//	bool visit[100010] = {0};
//	for(int i = 0 ;i<n;i++){
//		flag = 0;
//		while(s[left].time+limit<=s[right].time){
//			left++;
//			flag = 1;
//		}
//		//左窗口动了 重新统计 
//		if(flag){
//		visit[100010] = {0};
//		ans = 0;
//		for(int j = left;j<=right;j++){
//			for(int k = 0;k<s[j].num;k++){
//				if(!visit[s[j].p[k]]){
//					ans++;
//				}
//				visit[s[j].p[k]] = true;
//			}
//		}
//		}
//		//如果左窗口没动就只统计新来的船怎么样就好了 
//		else{
//			for(int k = 0;k<s[right].num;k++){
//				if(!visit[s[right].p[k]]){
//					ans++;
//				}
//				visit[s[right].p[k]] = true;
//			}
//		}
//		printf("%d\n",ans);
//		right++;
//	}
//	return  0 ;
//} 
