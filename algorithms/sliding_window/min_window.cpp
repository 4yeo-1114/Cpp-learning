/* C++ | sliding window: min window. */
//最小覆盖子串
#include <iostream>
#include <string> 

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int t_cnt[128];
        int s_cnt[128];
        //less表示t中不重复字符的个数
        int less = 0;
        int ans_right = 1000000;
        int ans_left = -1;
        int left = 0;
        for(int i = 0 ;i<t.length();i++){
            if(t_cnt[t[i]]==0){
                less ++;
            }
            t_cnt[t[i]]++;
        }
        for(int right = 0 ;right<s.length();right++){
            s_cnt[s[right]]++;
            if(s_cnt[s[right]]==t_cnt[s[right]]){
                less--;
            }
            while(less==0){
                if(right-left<ans_right-ans_left){
                    ans_right = right;
                    ans_left = left;
                }
                if(s_cnt[s[left]]==t_cnt[s[left]]){
                    less++;
                }
                s_cnt[s[left]]--;
                left++;
            }
        }
        return ans_left==-1?"":s.substr(ans_left,ans_right-ans_left+1);
        //return ans_left==-1?"":s.substr(ans_left,ans_right-ans_left+1);
    }
};