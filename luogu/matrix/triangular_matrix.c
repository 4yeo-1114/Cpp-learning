/* C | matrix: triangular matrix. */
#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int a[100][100];
	int k = 1;
	int L; // L表示第几斜行 斜着来赋值
	int j; //列
	int i; //行
	for(L = 0; L<n;L++){
		for(j = 0 ; j<n && L+j< n;j++){
			a[L+j][j] = k++;
		} 
	} 
	// 输出
	for(int i = 0; i<n; i++){
		for(j = 0 ; j<n; j++){
		 printf("%2d", a[i][j]);
		}
		printf("\n"); // 一行结束换行 
	} 
}
