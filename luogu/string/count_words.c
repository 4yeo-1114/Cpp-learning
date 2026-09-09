/* C | string: count words. */
#include <stdio.h> 
#include <string.h>
int main(){
	char c[100000];
	int cnt;
	int i  = 0; 
	//这样输入也可以输入含空格的字符串 
	while(1){
		scanf("%c", &c[i]) ;
		if(c[i] == '\n') break;
		i++;
	}
	//while(1) {
	// scanf("%c", &c[i]);
	//if(c[i]=='\n') break;
	//i++;
//}
	cnt  =  0 ;
	if(c[0] != ' ') cnt++;
	for(int j = 0 ;j<i-1;j++){
		if(c[j] == ' ' && c[j+1] != ' ') cnt++;
	}
	printf("%d", cnt);
	return 0 ;
	
}
