/* C++ | string: reverse words. */
//#include <bits/stdc++.h>
//#include <algorithm>
//using namespace std;
//int main(){
//	string s;
//	getline(cin,s);
//    string c = "";
//    int i = 0;
//    while(s[i]!='\0'){
//    	if(s[i]==' '){
//    		reverse(c.begin(),c.end());
//    		cout<<c<<" ";
//    		c.clear();
//		}else{
//		c += s[i];	
//		}
//		
//		i++;
//	}
//	reverse(c.begin(),c.end());
//    cout<<c<<" ";
//	return 0;
//	
//}
//用c语言写
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <algorithm>
int main(){
	char s[10000];
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")] = '\0';
	char sub[1000];
	int top = -1 ;
	for(int i = 0;s[i]!='\0';i++){
		if(s[i]==' '){
			for(int j = top;j>=0;j--){
				printf("%c",sub[j]); 
				sub[j] = 0;
			}
			top = -1;
			printf(" ");
		}
		else{
			sub[++top] = s[i];
		}
	}
	for(int j = top;j>=0;j--){
				printf("%c",sub[j]); 
				sub[j] = 0;
			}
			printf(" ");
			return 0;
} 
