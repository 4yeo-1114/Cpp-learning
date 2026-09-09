/* C++ | string: multiline input. */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
int  main(){
	char star[7];
	char group[7];
    fgets(star, sizeof(star), stdin);
    star[strcspn(star, "\n")] = '\0';  // 用strcspn找到换行符位置，替换为结束符
    
    // 读取小组名并去掉换行符
    fgets(group, sizeof(group), stdin);
    group[strcspn(group, "\n")] = '\0';
	int num1 =1;
	int num2  = 1; 
	int len1,len2;
	len1   = strlen(star);
	len2 = strlen(group);
	for(int i = 0;i<len1;i++){
		num1 *= (star[i]-'A'+ 1);
	}
	for(int i = 0;i<len2;i++){
		num2 *= (group[i]-'A'+1);
	}
	if(num1%47 == num2%47){
		printf("GO");
	}
	else{
		printf("STAY");
	}
	return 0;
}

#include <iostream>
int main()
{
	using namespace std;
	int a = 1 , b = 1;
	char v;
	//只用字符实现多行输入  while((c=getchar())!='\n')
	while ( (v = cin.get() ) != '\n') a *= v - 'A' + 1;
	while ( (v = cin.get() ) != '\n') b *= v - 'A' + 1;
	if (a % 47 == b % 47) cout << "GO";
	else cout << "STAY";
	return 0;
}

