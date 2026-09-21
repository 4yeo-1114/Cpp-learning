#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

//输出全排列 回溯算法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> path;
        vector<int> on_path;

        auto dfs = [&](this auto&&  dfs,int i) ->void{
            if(i==n){
                ans.emplace_back(path);
            }
            for(int j = 0;j<n;j++){
                if(!on_path[j]){
                    path[i] = nums[j];
                    on_path[j] = true; //选了就标记为on_path
                    dfs(i+1); //在此基础上继续后面的选择
                    on_path[j] = false; //做完一个排列后 清除之前选过的状态
                }
            }
        };
        dfs(0);
        return ans;
    }
};



//push_back和emplace_back的区别

struct Test {
    int a;
    Test(int x) : a(x) {
        cout << "构造" << endl;
    }
    Test(const Test&) {
        cout << "拷贝构造" << endl;
    }
    Test(Test&&) noexcept {
        cout << "移动构造" << endl;
    }
};
int main(){
    vector<Test> v;
    v.push_back(Test(1));  
    // 输出：构造 → 移动构造（临时Test(1)生成，然后移动进vector）

    v.emplace_back(2);
    // 输出：构造，直接在vector内部构造，没有移动！
}