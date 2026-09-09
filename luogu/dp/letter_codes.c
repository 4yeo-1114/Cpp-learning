/* C | dp: letter codes. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long numDecoding(char *s){ //算出有多少解码情况的函数 
	int n = strlen(s);
    long long dp[n+1];
	dp[0] = 1; //空字符只有一种解码
	dp[1] = (s[0] != '0')?1:0; // 如果第一个字符就是0，则记为0，否则为1；
	for(int i = 2;i<=n;i++){
		dp[i] = 0; //先初始化
		// 单独解码就是和n-1一样 新加的字符不会影响之前字符的编码数 
		if(s[n-1] != '0'){
			dp[i] += dp[i-1];
		} 
		int twodigit =(s[i-2] - '0')* 10 +(s[i-1] - '0');
		// 前两个绑在一起 
		if(twodigit >= 10 && twodigit <=26){
			dp[i] += dp[i-2];
		} 
	}
	return dp[n]; 
}
int main(){
	char inputs[1000][1000]; //用一个二维数组来存储输入的数组
	int inputCount = 0; 
		while(1){
			char s[1000];
			scanf("%s",s);
			if(strcmp(s,"0") == 0){
				break;
			}
		   strcpy(inputs[inputCount],s); //把输入的数组放到瓶子里 
		   inputCount++; //加一个新瓶子 
		}
		for(int i = 0;i<inputCount;i++){
			printf("%lld\n",numDecoding(inputs[i]));
		}
			return 0;
	}

