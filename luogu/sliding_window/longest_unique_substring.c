/* C | sliding window: longest unique substring. */
#include <stdlib.h> 
#include <string.h>
int lengthoflongeststring(char *s){
	int last[128];//记录字符上一次出现的位置 
	for(int i =0 ;i<128;i++){
		last[i] = -1;
	}
	int left = 0;
	int maxlen = 0;
	for(int right = 0;s[right]!='\0';right++){
		char c = s[right];
		if(last[c]>=left){ // 如果上次出现的位置在目前这个子串里的话 
			left = last[c] + 1;//移动左边界 
			
		}
		last[c] = right; // 无论如何都要更新位置 
		int currentlen = right - left+1;
		if(currentlen>maxlen){
			maxlen = currentlen;
		}
	}
	return maxlen; 
}
//也可以用map来存储每个字符上一次出现的位置 

int lengthofstring(char *s){
	int last[128];
	for(int i = 0;i<128;i++){
		last[i] = -1;
	}
	int left = 0;
	maxlen = 0;
	for(int right = 0;s[right]!='\0';right++){
		char c = s[right];
		if(last[c]>=left){
			left  = last[c]+1;
		}
		last[c] = right;
		currentlen  = right - left;
		if(currentlen>maxlen) maxlen = currentlen;
	}
	return maxlen;
}
