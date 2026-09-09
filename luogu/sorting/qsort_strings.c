/* C | sorting: qsort strings. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare_string(const void*a,const void*b){
	return strcmp(*(char**)a,*(char**)b); //左减右是升序 
}

int main(){
	char *name[]={"Zoe","Alice","Bob","John"};
	int n = sizeof(name)/sizeof(name[0]);
	qsort(name,n,sizeof(char*),compare_string);
	for(int i =0 ;i<n;i++){
		printf("%s  ",name[i]);
	}
	return 0;
} 

//或者
int compare_string(const void *a,const void *b){
	char *const *arg1= a; //先转为char一个* 在转移到arg上又一个* 
	char *const *arg2= b;
	return strcmp(*arg1,*arg2) 
	
}
