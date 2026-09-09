/* C++ | binary search: college admission. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int n,m;
// 比较函数，用于排序
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int main(){
	scanf("%d %d",&m,&n);
	int sch[1000010];
	int std[1000010];
	for(int i= 0;i<m;i++){
		scanf("%d", &sch[i]);
	}
	for(int i= 0;i<n;i++){
		scanf("%d",&std[i]);
	}
	// 对学校分数线排序
    qsort(sch, m, sizeof(int), compare);
	long long  ans = 0;
	for(int i= 0;i<n;i++){
		int target = std[i];
        int left = 0, right = m ;
        int min_diff = abs(target - sch[0]);  // 初始化为第一个学校的差值
        while(left<right){
        	int mid  = left +(right-left)/2;
        	int diff = abs(target-sch[mid]);
        	if(diff<min_diff) min_diff = diff;
        	if(sch[mid]>target){
        		right = mid;
			}else{
				left =  mid +1;
			}
		}
		ans += min_diff; 
	}
	printf("%lld",ans);
	return 0; 
} 
