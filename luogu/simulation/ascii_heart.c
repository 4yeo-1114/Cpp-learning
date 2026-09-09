/* C | simulation: ascii heart. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int c = 8;
	char str[] = "I LOVE YOU!";
	int len = strlen(str);
	system("color 0b");
	for(float i = 2.5;i> -2.0;i -= 0.12){
		for(float j = -2.5;j< 2.1;j+= 0.05){
			float a = i*i + j*j -4;
			a*a*a -j*j*i*i*i<-0.0?
			putchar(str[c%len]),c++:putchar(' '); 
		}
		putchar('\n');
	}
	system("pause");
	return 0;
} 
