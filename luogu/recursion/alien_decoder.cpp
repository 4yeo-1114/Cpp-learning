/* C++ | recursion: alien decoder. */
#include<bits/stdc++.h>//万能头棒棒哒
using namespace std;
string jieya(){
    int k;//压缩的次数
    char ch;//输入的字符
    string s="",str="";//s是最终答案，str是被压缩的字串，别忘了初始化
    /*注意：ch,s,str应该定义在函数内部，才能在每次递归中初始化，否则会导致一堆RE，可能还有几个MLE，总之没法AC，我就因为这个错了好几回*/
	while(cin>>ch){//不断输入字符
		if(ch=='['){//如果找到了被压缩的字串
			cin>>k;//输入压缩次数
			str=jieya();//递归调用
			while(k--){
				s+=str;//把解压后的字串复制k次后添加到原来的字符串上
			}
		}
		else if(ch==']'){//如果找到了压缩的字串的末尾
			return s;//结束这一层递归并返回已经被解压的字串
		}
		else{//如果没有被压缩
			s+=ch;//直接在最后添上这个字符。
		}
		return s;
	}
}
int main(){
	cout<<jieya();
	return 0;//完结撒花～
}
//重写 
#include<bits/stdc++.h>
using namespace std;
string jieya(){
	int k;
    char ch;
    string ans="",s="";
    while(cin>>ch){
    	if(ch =='['){
    	cin>>k;
    	s = jieya();
    	while(k--) 	ans += s;
	}
	else if (ch ==']'){
		return ans;
	}
	else ans += ch;
	}
	return ans;
    
}
int main(){

	cout<<jieya();
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
string px(){
	int k;
	char ch;
	string s = "";
	string str = "";
	while(cin>>ch){
		if(ch=='['){
			cin>>k;
			str = px();
			while(k>0){
			s += str;
			k--;	
			}
		}
		else if(ch== ']'){
			return s;
		}
		else{
			s += ch;
		}
	}
	return s;
}

int main(){ 
	 cout<<px();
	 return 0;
} 
