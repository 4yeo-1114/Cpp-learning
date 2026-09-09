/* C | sorting: bubble sort strings. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
void swap(char **a,char**b){
	//**a 表示指向s[j]这个字符串指针的指针 
     char *temp = *a; // 用temp去保存s[j]的地址
	 //交换a,b指向的字符串地址，达到交换字符串数组的目的 
     *a = *b;
     *b = temp;
}
void px(char **s,int len){
	for(int i = 0;i<len-1;i++){
		for(int j = 0;j<len-i-1;j++){
			if(strcmp(s[j],s[j+1])>0){
				swap(&s[j],&s[j+1]);
			}
		}
	}
	
}

int main(){
	char *s[100];
	char buf[100];
	int n; 
	scanf("%d", &n);
	getchar(); //吸收换行符 
	for(int i = 0;i<n;i++){
		fgets(buf,sizeof(buf),stdin);
		buf[strcspn(buf,"\n")] = '\0';
		s[i] = (char *)malloc(strlen(buf) + 1);
		strcpy(s[i],buf);
	}
	px(s,n);
	for(int i = 0;i<n;i++){
		printf("%s\n",s[i]);
		free(s[i]);
	}
	return 0;
}
