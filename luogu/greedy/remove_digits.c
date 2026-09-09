/* C | greedy: remove digits. */
//没法ak的 
//#include <stdio.h>
//#include <stdlib.h> 
//#include <string.h>
//int main(){
//	int k;
//	char s[260];
//	scanf("%s", s);
//	scanf("%d", &k);
//    int max = 0 ;
//    int len  = strlen(s);
//	int cnt = 0;
//	for(;cnt<k;){
//		int i ;
//		for(i =0;i<len-1;i++){
//		if(s[i] > s[i+1]){
//			break; // 遇到峰值就跳出 而不是让他变成0 因为本来的数字里面也可能有0 
//		}
//	   }
//	   for(int j = i;j<len-1;j++){
//	   	s[j] = s[j+1]; // 把后面的数字向前移动 
//	   } 
//	   len--;
//	   cnt++; 
//	}
//    int start  =0 ;
//    while(s[start]==0) start++;
//     if (start == len) { //如果全是0 输出0 
//        printf("0\n");}
//    for(int i = start;i<len;i++){
//    	printf("%c",s[i]);
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int num[260]; 
char s[260];
int k,m;
int cnt;
int min = 0;
int main(){
	scanf("%s %d",s,&k);
	int len  = strlen(s);
	for(int i = 1;i<=len;i++){
		num[i]  = s[i-1] - '0';
	}
	int t=1;
	int rest  = len - k; //删完后的位数 
	//：k -= min - t;更新还需要删除的数字个数 k。
	//解释：min 是当前找到的最小数字的位置。
	//t 是当前查找范围的起始位置。
	while(cnt<rest){
		min  = t;
		for(int i = t ;i<t+k+1;i++){
			if(num[i]<num[min]) min = i;
		}
		if(num[min]) printf("%d",num[min]);//输出一位 
		k -= min - t; //更新k 
		t = min + 1;
		cnt++;//有一位就记一次 
	}

	return 0 ;
}
