#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 判断 target 是否是 input 的合法出栈序列
bool isValidStackSequence(const string& input, const string& target) {
    if (input.length() != target.length()) return false;
    
    stack<char> s;
    int targetIdx = 0;
    
    for (char ch : input) {
        s.push(ch); // 元素入栈
        
        // 只要栈顶元素等于当前期望出栈的字符，就立即出栈
        while (!s.empty() && s.top() == target[targetIdx]) {
            s.pop();
            targetIdx++;
        }
    }
    
    // 如果所有元素都能按顺序出栈，栈最后会变为空
    return s.empty();
}

int main() {
    string input = "ABCDEFGH";
    string target = "EDHGFCBA";
    
    if (isValidStackSequence(input, target)) {
        cout << target << " 是合法的 FILO 序列 (可以转换)" << endl;
    } else {
        cout << target << " 不是合法的 FILO 序列 (无法转换)" << endl;
    }
    
    return 0;
}



#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 判断给定的排列 a 能否通过一个栈重排为 1..n
bool canSortUsingStack(const vector<int>& a) {
    stack<int> s;
    int expected = 1; // 期望依次输出 1, 2, 3, ..., n
    
    for (int num : a) {
        s.push(num);
        
        // 贪心：只要栈顶符合期望的递增数字，就输出
        while (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        }
    }
    
    // 如果最后期望输出到了 n + 1，说明成功排成了 (1..n)
    return s.empty();
}

int main() {
    // 示例 1: 包含 231 模式的非法序列 (如 2, 3, 1)
    vector<int> a1 = {2, 3, 1};
    cout << "序列 [2, 3, 1] 能否重排为 1..n: " 
         << (canSortUsingStack(a1) ? "能" : "不能 (包含231禁忌模式)") << endl;

    // 示例 2: 合法序列
    vector<int> a2 = {3, 2, 1, 4};
    cout << "序列 [3, 2, 1, 4] 能否重排为 1..n: " 
         << (canSortUsingStack(a2) ? "能" : "不能") << endl;

    return 0;
}