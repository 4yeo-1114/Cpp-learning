/* C++ | sliding window: longest unique substring. */
#include <vector>         
#include <unordered_map>  
#include <unordered_set>
#include <algorithm>    
#include <string>
using namespace std; 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         //用哈希表记录字符出现次数
        unordered_map<char,int> cnt;
        int n = s.length();
        int ans  =0;
        int left = 0;
        for(int right=0;right<n;right++){
            char c = s[right];
            cnt[c]++;
            while(cnt[c]>1){
                cnt[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
//用哈希集合
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //维护从下标left到下标right的字符
        unordered_set<char> window;
        int n = s.length();
        int left = 0;
        int ans = 0;
        for(int right = 0;right<n;right++){
            char c = s[right];
            //和哈希表不一样
            //先检查再插入 想想插入第一个元素就知道了
            while(window.count(c)){
                window.erase(s[left]);
                left++;//缩小窗口
            }
            window.insert(c);
            ans = max(ans,right-left-1);
        }
        return ans;
    }
};