/* C | sliding window: min fixed sum. */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main(){
//	int n,m;
//	scanf("%d %d", &n,&m);
//	int a[30010];
//	for(int i = 0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	int min = 100000;
//	for(int i = 0;i<=n-m;i++){
//		int ans = 0;
//		for(int j =0;j<m;j++){
//			ans += a[i+j];
//		}
//		if(ans<min) min =ans;
//	}
//    printf("%d",min);
//	return 0;	
//} 

//优化
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,m;
	scanf("%d %d", &n,&m);
	int a[30010];
	int ans  = 0;
	int min = 0;
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		if(i<m) {
			ans += a[i] ;
			if(i == m-1) min = ans;
		}
		else {
			ans = ans+a[i]-a[i-m];
			if(ans<min)  min = ans;	
		}
	}
	printf("%d",min);
	return 0;
} 
