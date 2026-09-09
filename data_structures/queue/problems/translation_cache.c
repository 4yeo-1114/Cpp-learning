/* C | queue: translation cache. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
	int m,n;
	scanf("%d %d", &m,&n);
	int k = 0;
	int ans = 0 ;
	bool visit[10000]  ={0};
	int num[10000];
	for(int i = 1;i<=n;i++){
		scanf("%d", &num[i]);
	}
	//用数组模拟队列 
	int queue[10001];
	int queue_size = 0;
	int front  = 0;
	for(int i = 1;i<=n;i++){
		int num1  = num[i];
	    if(!visit[num1]){
	    	ans ++;
	    	if(queue_size == m){
	    		//队满了就出队 
	    		int old_num = queue[front];
	    		visit[old_num] = false;
	    		front  = (front+1)%m;
				queue_size --; 
			}
	    	//入队
			int pos = (front+queue_size)%m; 
			queue[pos] = num1;
			//入队了就标记为出现 
			visit[num1]  = true;
			queue_size++;
	    	
		}
	}
	printf("%d",ans);
	return 0;
}


//用c++内置queue函数
//#include <bits/stdc++.h>
//using namespace std;
//queue<int> a; //初始化队列 
//int main(){
//	
//	int m,n;
//	scanf("%d %d", &m,&n);
//	int k = 0;
//	int ans = 0 ;
//	bool visit[10000]  ={0};
//	int num[10000];
//	for(int i = 1;i<=n;i++){
//		scanf("%d", &num[i]);
//	}
//	int queue_size = 0;
//	for(int i = 1;i<=n;i++){
//		int num1 = num[i];
//		if(!visit[num1]){
//			ans++;
//		if(queue_size == m){
//			int oldnum  =  a.front();
//			visit[oldnum] = false;
//			a.pop();//出队 
//			queue_size--;
//		}
//		//入队
//		a.push(num1);
//		queue_size++;
//		visit[num1] = true;	 
//		}
//		
//	} 
//	printf("%d",ans);
//	return 0;
//} 
