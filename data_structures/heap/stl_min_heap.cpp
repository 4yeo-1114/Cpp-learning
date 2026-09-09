/* C++ | heap: stl min heap. */
#include <iostream>
#include <queue>    // 包含priority_queue
#include <functional> // 包含greater

using namespace std;

int main() {
    // 定义小根堆：存储int类型，底层用vector实现，比较方式为greater<int>
    priority_queue<int, vector<int>, greater<int> > minHeap;

    // 向堆中插入元素
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(8);
    minHeap.push(1);
    minHeap.push(2);

    // 输出堆的基本信息
    cout << "堆的大小: " << minHeap.size() << endl;       // 输出：5
    cout << "堆顶元素(最小值): " << minHeap.top() << endl; // 输出：1

    // 遍历并弹出所有元素（从小到大输出）
    cout << "弹出所有元素: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // 获取当前最小值
        minHeap.pop();                // 弹出最小值
    }
    // 输出：1 2 3 5 8 

    return 0;
}

