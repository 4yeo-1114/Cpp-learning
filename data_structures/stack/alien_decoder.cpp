/* C++ | stack: alien decoder. */
#include<iostream>
#include<string>
using namespace std;
struct stack{
    int t;
    string s;
}st[20]; //t来存之后找到时要循环的次数，s就是之后的字符串
int x;
string s;
int main(){
    cin>>s;
    int lens=s.size(),len=0;//len是层数 
    for (int i=0;i<lens;i++){
        if (s[i]<='Z'&&s[i]>='A')
            st[len].s+=s[i];//压到第0栈 即要输出的那层 
        else if (s[i]=='['){ // 压到新的一栈 
            st[++len].s="";//初始化 
            st[len].t=0; //记得清零，防止出现[xxxx][xxxx]的情况 
        }
        else if (s[i]<='9'&&s[i]>='0')
        st[len].t=st[len].t*10+s[i]-'0';  //不止一位数！ 
        else if (s[i]==']'){
            for (int j=1;j<=st[len].t;j++)
                st[len-1].s+=st[len].s;
            len--; //解压一层后层数减一 
        }
    }
    cout<<st[0].s<<endl;//直接输出最开始的字符串 
    return 0;//标准的退出，记得写 
}
//重写
#include<iostream>
#include<string>
using namespace std;
struct stack{
    int t;
    string s;
}st[20]; 
int x;
string s; 
int main(){
	cin>>s;
	int lens = s.size();
	int len = 0;
	for(int i = 0;i<lens;i++){
		if(s[i]<='Z'&&s[i]>='A'){
			st[len].s += s[i];
		}
		else if(s[i] =='['){
			st[++len].s = "";//先初始化
			st[len].t = 0; 
		}
		else if(s[i]<='9'&&s[i]>='0'){
			st[len].t = st[len].t*10 + s[i]-'0';
		}
		else if(s[i] ==']'){
			for(int j = 1;j<=st[len].t;j++){
				st[len-1].s += st[len].s;
			}
			len--;
		}
	}
	cout<<st[0].s<<endl;
	return 0; 
} 

