/* C | string: find character. */
#include <stdio.h>
#include <string.h>
int main(){
	char k;
	scanf(" %c", &k);
	 // 关键修复：手动清空缓冲区所有残留字符（包括换行符、多余字符）
    while (getchar() != '\n');  // 循环读取缓冲区内容，直到读到换行符（清空完毕）
// while(getchar()!='\n'); 
    
    char c[10000];
    // 2. 用fgets读取整行字符串（比scanf循环更可靠，不会漏读/误读）
    fgets(c, sizeof(c), stdin);  // 最多读取 sizeof(c)-1 个字符，但是会读到‘\n’,自动加'\0'结尾
//或者这样   c[strcspn(c,'\n')] = '\0';
    //fgets(c,sizeof(c),stdin);
	//c[strcspn(c,'\n'0] = '\0'; 
    
    // 3. 去掉fgets读取到的换行符（fgets会把用户输入的回车也读进来，需要手动剔除）
    int i = strlen(c);
    if (i > 0 && c[i-1] == '\n') {
        c[i-1] = '\0';  // 把换行符替换为字符串结束符
    }
	int flag  =  0;
	int max = 0;
	for(int j = 0 ;j<i;j++){
		if(c[j] == k){
			max = j;
			flag = 1;
		}
	} 
	if(!flag) printf("Not Found");
	else{
		printf("index = %d",max);
	}
	return  0 ;
} 
