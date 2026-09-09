/* C++ | string: find word. */

#include <bits/stdc++.h>
using namespace std;
string dan,key,s;
int ans,cur = -1;
int main(){
	cin>>key;
	for(int i = 0;i<key.size();i++){
		key[i] = tolower(key[i]);
	}
	getchar();
	getline(cin,s);
	s += ' ';//这行很重要，关系着最后一个单词会不会扫描到
	for(int i = 0;i<s.size();i++){
		s[i] = tolower(s[i]);
	}
	for(int i = 0;i<s.size();i++){
		if(s[i] == ' '){
			if(dan == key){
				ans++;
				if(cur == -1) cur = i - key.size();
			}
			dan = "";//读到空格归零 
		}
		else dan+= s[i];
	}
   if(ans==0)printf("-1");
    else printf("%d %d",ans,cur);
     return 0;
    
}
/**
getchar(); 的作用
getchar() 是 C 语言风格的输入函数，功能是从标准输入（键盘）读取一个字符（包括空格、换行符 \n 等），并返回该字符的 ASCII 码。它的常见用途是清除输入缓冲区中残留的换行符。
2. getline(cin, s); 的作用
getline(cin, s) 是 C++ 中用于读取字符串的函数，功能是从输入流 cin 中读取一整行内容（包括空格），直到遇到换行符 \n 为止，然后将读取的内容存入字符串 s 中（不包含最后的换行符）。
与 cin >> s 不同，它能读取带空格的字符串（比如完整的句子）。
为什么要组合使用？
当我们先用 cin >> 变量（比如读取整数、单个单词）时，
输入结束后，键盘输入的换行符 \n 会残留在输入缓冲区中。
此时如果直接用 getline(cin, s)，getline 会把缓冲区中残留的 \n 当作 “结束标志”，导致读取到空字符串（实际什么都没读）。
而 getchar(); 的作用就是提前读取并丢弃这个残留的 \n，
确保 getline 能正确读取后续输入的一整行内容。
/

