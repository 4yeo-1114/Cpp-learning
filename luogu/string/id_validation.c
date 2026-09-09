/* C | string: id validation. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char c[19];
int num[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; 
char zz[11] = {'1', '0', 'X', '9','8','7','6','5','4','3','2'};
bool qwq(char c[]){
	int sum = 0;
	for(int i = 0;i<17;i++){
		sum += (c[i] - '0') * num[i];
	}
	int z ;
	z = sum%11;
	if(c[17] == zz[z]) return true;
	else return false;
}
int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0;i<n;i++){
		scanf("%s", c); 
		if(!qwq(c)){
			printf("%s\n",c);
		}
		else{
			cnt++;
		}
	}
	if(cnt==n){
		printf("All passed");
	}
	return 0 ;
} 
