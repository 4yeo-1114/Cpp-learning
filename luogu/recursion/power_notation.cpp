/* C++ | recursion: power notation. */
#include <bits/stdc++.h>
using namespace std;
void dg(int n){
    if(n == 1){
		cout<<"2(0)";
	}
	else if(n == 2){
		cout<<"2";
	}
	else{
		int i = 1;
		int cnt = 0;//找到最接近n的2的cnt次方，便于后面分解 
		while(n>i*2){
			i *= 2;
			cnt ++;
		}
		int rest  = n - i;//剩余部分 
//		return "2(dg(cnt))+dg(rest)";
        // 要对cnt=0 =1 特殊处理 
        if(cnt == 0){
        	cout<<"2(0)";
		}
		else if(cnt==1){
			cout<<"2";
		}
		else {
		cout<<"2(";
		dg(cnt);// 递归分解幂次cnt
		cout<<")"; 
		}
		// 处理剩余部分（rest≠0时才添加+和递归）！ 
        if (rest != 0) {
            cout << "+";
            dg(rest);
        }
	}
}
int main(){
	int n;
	scanf("%d", &n);
    dg(n);
	return 0;
} 
