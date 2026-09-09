/* C++ | string: reverse number. */
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	char  p  =  0;//记录符号
	cin>>s;
	int cnt = 0; //记录长度和符号的位置 
	for(int i  = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') cnt++;
		else{
			p = s[i];
			break; 
		}
	} 
	int x = cnt; //符号的位置 
	cnt--; // 前半个数字的末尾
	//去除前导零
	while(s[cnt] == '0' &&cnt>0) cnt--;
	for(int i  = cnt;i>=0;i--){
		cout<<s[i];
	} 
	if(p == 0 ){
		return  0 ; // 没有符号 
	}
	else{
		if(p == '%'){
			cout<<p;
			return   0 ;
		}
		else{
			cout<<p;
			int m = s.size() - 1;//后半数字的末尾 
			x += 1;
			//同时x<m 而不是《= 保证了如果只有一个0就输出0 
			while(s[x] == '0' && x<m) x++;//去到前面的零 
			while(s[m] == '0' && m>x) m--;//去到后面的零 
			for(int  i  = m;i>=x;i++){
				cout<<s[i];
			}
			return 0;
		}
	} 
}



#include <string>
#include <iostream>
#include <algorithm>
using namespace std; 
// 自己写的反转函数，返回反转并去掉前导零之后的字符串
string reverse1(string s) {
	int zeroCount = 0;
	reverse(s.begin(), s.end()); // 反转
    // 范围 for 循环，用于统计前导零个数
   	//for (auto i : s)
//		if (i == 48) ++zeroCount;
//		else break;
    for(int i = 0;i<s.size();i++){
    	if(s[i] == '0') zeroCount ++;
    	else break;
	}
	s.erase(s.begin(), s.begin() + zeroCount);
	return (s != "" ? s : "0"); // 特判
}

// 用于去掉后导零
string deleteTail(string s) { 
	int zeroCount = 0;
	for (int i = s.size() - 1; i >= 0; --i)
		if (s[i] =='0') ++zeroCount;
		else break;
	s.erase(s.end() - zeroCount, s.end());
	return (s != "" ? s : "0");
}

int main() {
	string s;
	cin >> s;
	if (s.back() == '%') { //如果最后一个字符是% 
		cout << reverse1(s.substr(0, s.size() - 1)) << "%" <<endl;
		return 0;
	}
	for (auto i : s) {
		string left, right;
        // 其实还有一种不需要遍历字符串的做法，直接 find() 即可，但是当时没想到
		if (i == '/') {
			left = s.substr(0, s.find("/"));//左闭右开 
			right = s.substr(s.find("/") + 1);
			cout << reverse1(left) << "/" << reverse1(right) << endl;
			return 0;
		}
		if (i == '.') {
			left = s.substr(0, s.find("."));
			right = s.substr(s.find(".") + 1);
			cout << reverse1(left) << "." << deleteTail(reverse1(right)) << endl;
			return 0;
		}
	}
    // 最后剩下的一种情况是正整数
	cout << reverse1(s) << endl;
	return 0;
}

