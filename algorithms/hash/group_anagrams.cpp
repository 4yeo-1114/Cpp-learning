/* C++ | hash: group anagrams. */
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution{
    public:
        vector<vector<string>> groupAnagrams(vector<string>&strs){
            unordered_map<string,vector<string>> m;
            for(string&s : strs){
                string sorted_s = s;
                sort(sorted_s.begin(), sorted_s.end());//把s排序作为key
                m[sorted_s].push_back(s);


            }
            vector<vector<string>> ans;
            ans.reserve(m.size()); //预分配空间
            for(auto&[_,value]:m){
                ans.push_back(value);

            }

            return ans;

    }
};
