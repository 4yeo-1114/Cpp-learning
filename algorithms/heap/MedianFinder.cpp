#include <vector>         
#include <unordered_map>  
#include <unordered_set>
#include <algorithm>    
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std; 

//实现一个类 既能储存数据流又能随时返回中位数
//如果每次加入新数据都重新排序 要取中位数再计算太麻烦了 我们这里只要完成取中位数
//所以数据内部这么存储只要能便于实现这个功能即可
//把较大的分为一堆 小根堆 较小的分为一堆 大根堆
//这样求中位数只要看两个堆的堆顶即可
//其中如果数量是奇数 A堆多一个即可
class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> A;//小根堆，保存较大的一半
    priority_queue<int, vector<int>, less<int>> B; // 大根堆，保存较小的一半
    MedianFinder() {    
    }
    void addNum(int num) {
        if(A.size()!=B.size()){
            A.push(num);
            B.push(A.top());
            A.pop();
        }   
        else{
            B.push(num);
            A.push(B.top());
            B.pop();
        }
    }
    
    double findMedian() {
        return A.size() != B.size() ? A.top() : (A.top() + B.top()) / 2.0;
    }
};

// 当 m=n（即 N 为 偶数）：需向 A 添加一个元素。
// 实现方法：将新元素 num 插入至 B ，再将 B 堆顶元素插入至 A 。
//反之同理
//为什么：
// 假设插入数字 num 遇到情况 1. 。
// 由于 num 可能属于 “较小的一半” （即属于 B ），因此不能将 nums 直接插入至 A 。
// 而应先将 num 插入至 B ，再将 B 堆顶元素插入至 A 。这样就可以始终保持 A 保存较大一半、 B 保存较小一半。





/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */