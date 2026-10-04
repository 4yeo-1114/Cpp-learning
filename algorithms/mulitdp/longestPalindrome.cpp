#include <iostream>
#include <string>
#include <vector>
using namespace std;



//找字串中最长的回文字串 为了能够利用之前已经知道的回文串 使用中心扩散去dp
//但是要分奇偶啊 
class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        if(n==1) return s;
        //用全局变量去保持最大字串的长度和下标 就不用后面再找
        int max_len = 0;
        int max_index = 0;
        //扩展函数 负责dp
        auto expand = [&](int left,int right){
            while(left>=0&&right<n&&s[left]==s[right]){
                left --;
                right ++;
            }
            //目前回文串边界[left+1,right-1]
            int len = right-left-1;
            if(len>max_len){
                max_len = len;
                max_index = left+1;
            }
        };
        //开始遍历字串的中心
        for(int i = 0;i<n;i++){
          expand(i,i); //奇数长度中心
          expand(i,i+1);//偶数长度中心
        }
        return s.substr(max_index,max_len);
    }
};