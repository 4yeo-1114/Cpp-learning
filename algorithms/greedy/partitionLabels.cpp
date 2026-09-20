#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


//我的写法 有点繁琐
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int start = 0;
        map<char, int> last;
        //记录每个字母的最远位置
        for(int i = 0;i<n;i++){
            char c = s[i];
            auto it = last.find(c);
            //存在过就更新最远位置
            if (it != last.end()){
                last[c] = i;
            }
            else{
                last[c] = i;
            }
        }
        vector<int> ans;
        int end = -1;
        while(end!=n-1){
            char c = s[start];
            int new_end = last[c];
            for(int i  =  start+1;i<=new_end;i++){
                if(last[s[i]]>new_end){
                    new_end = last[s[i]];
                }
            }
            end = new_end;
            ans.push_back(end-start+1);
            start = end+1;
        }
        return ans;
    }
};


//最佳写法 用列表保存每个字母的最远位置 动态扩展右边界 到达右边界就记为一个片段
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        // 1. 记录每个字符最后出现的位置（用数组替代 map，性能更高）
        vector<int> last(26, 0);
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0;
        int end = 0;

        // 2. 线性扫描，动态扩展右边界
        for (int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']); // 不断扩展当前片段所需的最远边界
            
            // 当到达当前片段所有字符的最远位置时，即可切分一个片段
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1; // 下一个片段的起点
            }
        }

        return ans;
    }
};