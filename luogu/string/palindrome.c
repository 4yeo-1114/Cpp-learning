/* C | string: palindrome. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char c[100];
	int i = 0;
	while(1){
		scanf("%c", &c[i]) ;
		if(c[i] == '\n') break;
		i++;
	}
	int l = 0;
	int r = i-1;
	int flag = 0;
	while(l<=r){
		if(c[l] != c[r]){
			flag = 1;
			break;
		} 
		l++;
		r--;
	}
	if(flag) {
		for(int j = 0;j<i;j++){
			printf("%c",c[j]);
		}
		printf("\n");
    	printf("No");	
	}
	else {
	for(int j = 0;j<i;j++){
			printf("%c",c[j]);
		}
		printf("\n");	
	printf("Yes");	
	}
	return 0 ;
} 
