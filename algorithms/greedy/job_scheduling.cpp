/* C++ | greedy: job scheduling. */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 结构体定义，保持简洁
struct Task {
    long long d; // 截止时间
    long long p; // 收益
};

int main() {
    // 优化标准输入输出的性能
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    //使用 std::vector 动态分配内存
    vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].d >> tasks[i].p;
    }

    // 现代 C++ 风格：使用 Lambda 表达式代替独立的 cmp 函数
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.d < b.d;
    });

    long long ans = 0;
    // 定义小根堆，用于存储已接取任务的收益
    priority_queue<long long, vector<long long>, greater<long long>> min_heap;

    // 使用基于范围的 for 循环遍历所有任务
    for (const auto& task : tasks) {
        // 判断条件转换：当前时间配额是否还能容纳这个任务
        if (task.d > min_heap.size()) {
            ans += task.p;
            min_heap.push(task.p);
        } 
        // 如果不能容纳，且当前收益大于堆顶（历史最差），则进行“反悔替换”
        else if (!min_heap.empty() && min_heap.top() < task.p) {
            ans += task.p - min_heap.top(); // 补上新老任务收益的差价
            min_heap.pop();                 // 踢出那个最差的历史任务
            min_heap.push(task.p);          // 把当前更赚钱的任务加进来
        }
    }

    // 使用 \n 换行，endl 会强制刷新缓冲区，导致性能下降
    cout << ans << "\n";
    
    return 0;
}