/* C++ | string matching: palindrome. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 验证回文串函数
bool isPalind(char *s){
	int n  = strlen(s);
	int left  = 0 ; 
	int right = n-1;
	while(left < right){
		while(left < right && !isalnum(s[left])){
			left ++; //跳过左边非字母数字字符 
		}
		while(left < right && !isalnum(s[right])){
			right--; //跳过右边非字母数字字符 
		}
		// 比较字符（忽略大小写）
		if(tolower(s[left]) != tolower(s[right])){
			return false; // 只要有一组不匹配 就不是 
		} 
		left++;
		right--; 
	}
	return true;
} 

int main(){
	char str[1000];
	printf("请输入字符串：");
	scanf("%s", str);
	if(isPalind(str)){
		printf("%s是回文串\n",str);
	}
	else{
		printf("%s不是回文串\n",str);
	}
	return 0;
}
// 重写
bool isPaling(char *s){
	int n = strlen(s);
	int left = 0;
	int right = n-1;
	while(left<right){
		while(left<right && !isalnum(s[right])){
			right--;
		}
		while(left<right && !isalnum(s[left])){
			left++;
		}
		if(tolower(s[left] )!= tolower(s[right])){
			return false;
		}
		left++;
		right--;
		
	} 
	return true;
} 
