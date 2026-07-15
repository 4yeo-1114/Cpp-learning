#include <vector>         
#include <unordered_set>  
#include <algorithm>    
#include <stack>
using namespace std;  

//会超时的递归
class Solution {
    int dfs(int i) {
        if (i <= 1) { // 递归边界
            return 1;
        }
        return dfs(i - 1) + dfs(i - 2);
    }

public:
    int climbStairs(int n) {
        return dfs(n);
    }
};

//记忆化搜索
//如果一个状态第一次遇到 就在返回前 把状态及结果记录到memo数组中
//如果一个状态不是第一次遇到 就直接放回memo中的结果
//memo的初始值一定不能等于要记忆化的值 一般初始化为-1 这里初始化为1
class Solution {
    vector<int> memo;
    int dfs(int i){
        if(i<=1){//递归边界
            return 1;
        }
        //这里是引用才可修改memo的值
        int& res = memo[i];
        if(res){//之前计算过
            return res;
        }
        else{
            //记忆化并放回  
            return res= dfs(i-1) +dfs(i-2);
        }
    }
public:
    int climbStairs(int n) {
        memo.resize(n+1);
        return dfs(n);
    }
};

//自底向上归
class Solution{
    public:
    int climbStairs(int n){
        vector<int> f(n+1);
        f[0]= f[1]  =1;
        for(int i = 2;i<=n;i++){
            f[i] = f[i-1] +f[i-2];
        }
        return f[n];
    }

};

//优化空间
//每次循环只需要知道上一个状态和上上个状态的f值为多少即可
class Solution{
    public:
    int climbStairs(int n){
        int f0 =1,f1 = 1;
        int new_f;
        for(int i=2;i<=n;i++){
            //计算结果
            new_f = f1+f0;
            //更新状态
            f0 = f1;
            f1 = new_f;
        }
        //放回的是f1 因为更新过了
        return f1;
    }

};

//大数加法
#include <iostream>
#include <vector>

using namespace std;

// 数组低位存个位，高位存大位（例如 123 存为 [3, 2, 1]）
void add(const vector<int>& a, const vector<int>& b, vector<int>& res) {
    res.clear(); // 清空旧的结果，替代 C 语言中的 memset
    int carry = 0; // 进位标志
    
    // 只要 a 还没加完，或者 b 还没加完，或者还有进位，就继续加
    int n = max(a.size(), b.size());
    for (int i = 0; i < n || carry > 0; ++i) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        
        res.push_back(sum % 10); // 把当前位的个位数存入结果（vector 会自动扩容）
        carry = sum / 10;        // 计算进位
    }
}

// 求解台阶数（斐波那契大数版）
void solve(int n) {
    // 替代原有的 int dp0[MAX_DIGIT] = {1};
    vector<int> dp0 = {1};  
    vector<int> dp1 = {1};  
    vector<int> dp2;        
    
    // 核心逻辑和原来一样
    for (int i = 2; i <= n; i++) {
        add(dp1, dp0, dp2); 
        
        // C++ 的魔法：直接赋值！
        // vector 重载了 = 运算符，底层会自动完成内存分配和深拷贝，完美替代 memcpy
        dp0 = dp1; 
        dp1 = dp2; 
    }
    
    // 输出结果（因为个位在索引 0，最高位在末尾，所以倒序输出）
    // vector 自动记录了正确的长度 (dp1.size())，不需要再像 C 语言那样用 while 去跳过前导 0
    for (int i = dp1.size() - 1; i >= 0; i--) {
        cout << dp1[i];
    }
    cout << "\n";
}

int main() {
    // C++ 加速输入输出的常规操作
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (cin >> n) {
        solve(n);  
    }
    return 0;
}