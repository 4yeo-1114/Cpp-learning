/* C | string: letter histogram. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
int num[26];
int main(){
	char s[1000];
	for(int i = 0;i<4;i++){
		fgets(s,sizeof(s),stdin);
		int len = strlen(s);
		for(int i = 0;i<len;i++){
			if(isupper(s[i])){
				num[s[i]-'A']++;
			}
		} 
	}
	int max = 0;
	for(int i = 0;i<26;i++){
		if(num[i]>max) max = num[i]; 
	} 
	for(int i = max;i>0;i--){
		for(int j = 0;j<26;j++){
			if(num[j]<i){
				printf(" ");
			}
			else{
				printf("*");
			}
			if(j!=25){
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	return 0;
} 
