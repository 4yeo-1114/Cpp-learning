/* C | string: replace word. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int boy = 0; 
	int girl = 0;
	char s[256];
	scanf("%s",s);
	int len = strlen(s); 
	for(int i = 0;i<len;i++){
	 if(s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y') boy++;
	 if(s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r'||s[i+3] == 'l') girl++;	
	} 
	printf("%d\n%d",boy,girl);
	return 0 ;
} 
