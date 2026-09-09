/* C | binary search: split array. */
#include <stdio.h>
#include <stdbool.h>
int a[3000000];
int n,m;
bool check(int x){
	int tot =  0;
	int num =  0 ;
	for(int i = 0;i<n;i++){
		if(tot+a[i]<=x){
			tot += a[i];
		}
		else{
			num++;
			tot  = a[i];
		}
	}
	return num >= m; //>=m这表示check不通过 这么贪心分还比m大肯定不行 
} 
int main(){
	scanf("%d %d", &n,&m);
	int max = 0;
	int r = 0 ;
	for(int i = 0;i<n;i++){
		scanf("%d", &a[i]);
		r+=a[i];
		if(a[i]> max){
			max = a[i];
		}
	}
	int l = max;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(check(mid)){ //mid太小了不可以 边界左移 
			l=mid+1;
		}
		else{ //mid可以 边界右移 找最小值 
			r = mid-1;
		}
	}
	printf("%d",l);
	return 0 ;
}
