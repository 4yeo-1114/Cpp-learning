/* C++ | string: assignment parser. */
//#include <cstdio>
//using namespace std;
//int  s[3];
//char s1,s2;
//int main(){
//	//利用scanf格式输入 
//	while(scanf("%c:=%c;",&s1,&s2) == 2){
//		s[s1-'a']=s2>='0'&&s2<='9'? s2-'0' : s[s2-'a'];
//	}
//	printf("%d %d %d",s[0],s[1],s[2]);
//	return 0;
//}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main(){
	int a[3];
	string s;
	getline(cin,s);
	for(int i = 0;i<s.length()-1;i++){
		if(s[i] == '='){
			if(s[i+1]>='0'&&s[i+1]<='9'){
				a[int(s[i-2] - 97)] = int(s[i+1] - '0');
			}
			else{
				a[int(s[i-2] - 97)] = a[int(s[i+1] - 97)];
			}
		}
	}
	cout<<a[0]<<" "<<a[1]<<" "<<a[2];
	return 0;
} 


