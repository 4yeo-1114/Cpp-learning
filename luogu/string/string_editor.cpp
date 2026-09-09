/* C++ | string: string editor. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cal_next(char *str, int *next,int len){
	next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
	int k =-1;//k初始化为-1
	for (int q = 1; q<=len-1;q++){
		while(k>-1 && str[k+1] != str[q]){//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
			k = next[k]; //往前回溯，反正就是让k变小，继续试 
			
		}
		if(str[k+1] == str[q]){ // 如果相同 
			k = k+1;
		}
		next [q] = k; //这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
	}
} 
char* h1(char *s, char *str){
	char* ret = (char*)malloc(100);
	int len1 = strlen(s);
	int len2 = strlen(str);
	for(int i = 0 ; i<len1;i++){
		ret[i] = s[i];
	}
	int j =0;
	for(int i  = len1;i<len1+len2;i++){

		ret[i] = str[j];
		j++;
	}
	strcpy(s,ret);
    return ret;
    free(ret);
}
char* h2(char *s,int a, int b){
	char* ret = (char*)malloc(100);
	//char ret[100];
	int len = strlen(s);
	int k = a;
	for(int i = 0;i<b;i++){
		ret[i]  = s[k];
		k++;
		if(k>=a+b||k>=len){
			break;
		}
	}
	strcpy(s,ret);
	return ret;
	free(ret);
	
}
char* h3(char*s,int a, char*str1){
	char* ret = (char*)malloc(100);
	//char ret[100];
	int start = 0;
	int len  = strlen(s);
	int len2 = strlen(str1);
	for(int i = 0;i<a;i++){
		ret[i] = s[start];
		start++;
	}
	start =0;
	for(int i = a; i<a+len2;i++){
		ret[i] = str1[start];
		start++;
	}
	for(int i = a+len2 ;i<len +len2;i++){
		ret[i] = s[a];
		a++;
	}
	strcpy(s,ret);
	return ret;
	free(ret);
}
int h4(char *str,  char *ptr){
	int slen =strlen(str);
	int plen =strlen(ptr);
	int *next = new int [plen];
	cal_next(ptr, next,plen); // 计算next 数组 
	int k =-1;
	for (int i = 0 ;i<slen ; i++){
		while(k>-1 && ptr[k+1] != str[i]) ////ptr和str不匹配，且k>-1（表示ptr和str有部分匹配！）
		k = next[k]; // 看部分匹配的ptr字符的next为多少，下次直接把ptr移动next[k]位 
		if (ptr[k+1] == str[i])
		k = k+1;
		if (k == plen -1){//说明k移动到ptr的最末端
			return i - plen +1; 
		}
	}
	
	return -1;
} 

int main(){
	int q;
	char s[100];
	char result[100][1000];
	scanf("%d", &q);
	scanf("%s", s);
	for(int i = 0;i<q;i++){
		int n;
		scanf("%d", &n);
		switch(n){
			case 1:{
				char str[100];
				scanf("%s",str);
			    strcpy(result[i], h1(s,str));
				break;
			}     
			case 2: {
				int a, b;
				scanf("%d %d",&a,&b);
				strcpy(result[i], h2(s,a,b));
				break;
			}    
			case 3:     {
				int a;
				scanf("%d", &a);
				char str1[100];
				scanf("%s",str1);
				strcpy(result[i], h3(s,a,str1));
				break;
			}
			case 4:     {
				char str2[100];
				scanf("%s",str2);
			    sprintf(result[i], "%d",h4(s,str2));
				break;
			}
		}
	}
	for(int i = 0;i<q;i++){
		printf("%s\n", result[i]);
	}
	return 0;
}
