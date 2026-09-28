#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 判断回文串函数
    bool is_palindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;

       //dfs(i,start)的意思是目前字串的开始在start 要不要在i和i+1处切一刀
        auto dfs = [&](this auto&& dfs, int i, int start) -> void {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            //不切 i等于n-1的话就必须切
            if (i < n - 1) {
                dfs(i + 1, start);
            }
            // 切：需先满足当前子串为回文
            if (is_palindrome(s, start, i)) {
                path.emplace_back(s.substr(start, i - start + 1));
                dfs(i + 1, i + 1);
                path.pop_back(); //回溯
            }
        };

        dfs(0, 0);
        return ans;
    }
};