#include <iostream>
#include <algorithm>  // swap
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        //存储复制次数的栈
        stack<int> count_stack;
        //存储字符串的栈
        stack<string> s_stack;

        //存储当前层字符串
        string current;
        //存储次数s
        int count;
        for(char ch:s){
            //记录数字 处理多位数
            if(isdigit(ch)){
                count = count*10 + (ch - '0');
            }
            else if(ch=='['){
                //进入新一层 次数和字符串入栈
                count_stack.push(count);
                s_stack.push(current);

                //重新开始
                count = 0;
                current.clear();

            }
            else if(ch==']'){
                int repeat = count_stack.top();
                count_stack.pop();

                string previous = s_stack.top();
                s_stack.pop();

                for(int i = 0;i<repeat;i++){
                    previous += current;
                }

                current = previous;

            }
            else {
                //普通字母
                current += ch;
            }
        }
        return current;
    }
};