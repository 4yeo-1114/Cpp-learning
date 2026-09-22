#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    static constexpr string_view map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        int n  = digits.length();
        if(n==0){
            return {};
        }
        vector<string> ans;
        string path(n,0);

        //递归函数 i表示path的第i个填上对应的字母然后在这个状态下继续递归深入直i==n
        auto dfs  = [&](this auto&&dfs,int i)  -> void{
            if (i==n){
                ans.emplace_back(path);
                return;
            }
            else{
                for(char c:map[digits[i]-'0']){
                    path[i] = c;
                    dfs(i+1);
                }
            }

        };
        dfs(0);
        return ans;
    }
};
//虽然说时间复杂度和写循环是一样的 但是全程只有一个path储存当前递归终点状态 所以空间复杂度大大降低