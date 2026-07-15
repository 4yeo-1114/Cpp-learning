#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ==================== 工具函数：合并两个有序链表 ====================
// 提示：利用哑节点模板，O(n+m)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode *cur = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;          // ⚠️ 推进 l1，否则死循环
        } else {
            cur->next = l2;
            l2 = l2->next;          // ⚠️ 推进 l2
        }
        cur = cur->next;
    }
    // 接上剩余部分（最多只有一个非空）
    cur->next = l1 ? l1 : l2;
    return dummy.next;
}

class Solution {
public:
    // ==================== 方法一：顺序合并 ====================
    // 思路：ans = list[0]，然后 ans = merge(ans, list[1])，依此类推
    // 时间复杂度：O(k²·n)，第一遍合并 n 和 n，第二遍 2n 和 n，...，第k-1遍 (k-1)n 和 n
    //           总 = (1+2+...+(k-1))n = O(k²·n)，不够优
    ListNode* mergeKLists_sequential(vector<ListNode*>& lists) {
        // 逐个合并
        if(lists.size() ==0) return nullptr;
        ListNode* ans = lists[0];
        for(int i = 1;i<lists.size();i++){
            ans = mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }

    // ==================== 方法二：分治合并（归并思想） ====================
    // 思路：两两配对合并，像归并排序的合并过程
    //             [l0, l1, l2, l3, l4, l5]
    //        合并 → [ 01 ,   23 ,   45  ]    第1轮：相邻两两合并
    //        合并 → [   0123   ,   45   ]    第2轮
    //        合并 → [      012345        ]    第3轮
    // 时间复杂度：O(nk·log k) ← 每轮合并总量 O(nk)，共 log k 轮
    // 空间复杂度：O(1)（不算递归栈的话是 O(log k)）
    ListNode* mergeKLists_divide(vector<ListNode*>& lists) {
        // TODO: 分治合并
        // 提示——每次把区间长度减半 即每次步长乘二
        if(lists.size() ==0) return nullptr;
        for(int interval = 1;interval<lists.size();interval  *= 2){
            for(int i = 0;i+interval<lists.size();i += interval*2){
                lists[i] = mergeTwoLists(lists[i],lists[i+interval]);
            }
        }
        return lists[0];
    }

    // ==================== 方法三：小根堆（优先队列） ====================
    // 思路：k 个链表的头节点放入小根堆，每次 pop 最小的接到结果尾部，
    //       然后把 pop 节点的 next 再 push 回堆
    // 时间复杂度：O(nk·log k)  ← 每个节点入堆+出堆各一次，堆大小 ≤ k
    // 空间复杂度：O(k)        ← 堆中最多 k 个元素
    ListNode* mergeKLists_heap(vector<ListNode*>& lists) {
        // 自定义比较器：按节点值建小根堆
        // 注意：和 sort 反的！return a->val > b->val 表示"值大的优先级低"= 小根堆
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;     // >  → 小根堆（值小的优先级高）
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // 初始化：每个非空链表的头节点入堆
        for (ListNode* head : lists) {
            if (head) pq.push(head);
        }

        ListNode dummy;
        ListNode* tail = &dummy;        // tail 始终指向结果链表的最后一个节点

        // 循环：每次取堆顶（当前全局最小值）
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;          // 接到结果链表尾部
            tail = tail->next;          // tail 后移

            if (node->next) {           // 该链表还有后续节点 → 入堆
                pq.push(node->next);
            }
        }
        return dummy.next;
    }
};

// ==================== 辅助函数 ====================

// 从初始化列表创建链表（方便测试）
// 用法：auto head = buildList({1, 4, 5});
ListNode* buildList(initializer_list<int> vals) {
    ListNode dummy;
    ListNode* cur = &dummy;
    for (int v : vals) {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    return dummy.next;
}

// 打印链表
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << "]" << endl;
}

// 释放链表内存（养成好习惯！）
void freeList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

// ==================== 测试 ====================
int main() {
    // 构造测试数据：lists = [[1,4,5], [1,3,4], [2,6]]
    vector<ListNode*> lists = {
        buildList({1, 4, 5}),
        buildList({1, 3, 4}),
        buildList({2, 6})
    };

    cout << "原始链表: " << endl;
    for (int i = 0; i < lists.size(); i++) {
        cout << "  list[" << i << "] = ";
        printList(lists[i]);
    }
    cout << "期望输出: [1, 1, 2, 3, 4, 4, 5, 6]" << endl << endl;

    // 注意：因为方法一/二会修改 lists，测试时只测其中一种
    // 这里用堆方法测试（不会修改原 lists）

    Solution sol;

    // 测试方法三：小根堆
    cout << "方法三（小根堆）: ";
    ListNode* result = sol.mergeKLists_heap(lists);
    printList(result);
    freeList(result);       // 结果链表是新链，用完释放

    // ====== 边界测试 ======

    // 空输入
    cout << "\n--- 边界测试 ---" << endl;

    vector<ListNode*> empty;
    cout << "空输入: ";
    result = sol.mergeKLists_heap(empty);
    printList(result);      // 期望：空，输出 []

    // 全空链表
    vector<ListNode*> allNull = {nullptr, nullptr};
    cout << "全空链表: ";
    result = sol.mergeKLists_heap(allNull);
    printList(result);      // 期望：空

    // 单链表
    vector<ListNode*> single = {buildList({7, 8, 9})};
    cout << "单链表 [7,8,9]: ";
    result = sol.mergeKLists_heap(single);
    printList(result);      // 期望: [7, 8, 9]
    freeList(result);
    freeList(single[0]);    // 这里 single[0] 没有被修改，手动释放

    // 释放测试数据
    // lists 中的原链表已被堆方法 pop 时拆散（node->next 入堆后原链已断开），
    // 不用再单独释放

    return 0;
}

// ==================== 复杂度对比 ====================
//
//               | 顺序合并  | 分治合并  | 小根堆
//   时间        | O(k² n)  | O(nk log k) | O(nk log k)
//   空间        | O(1)     | O(1)     | O(k)
//   实现难度     | ★☆☆☆☆   | ★★★☆☆   | ★★★☆☆
//   推荐        |    ❌     | 面试写这个  | 面试写这个
//
// ==================== 关键边界条件提示 ====================
//
//   1. lists 为空 → return nullptr
//   2. lists 中所有链表都为空 → return nullptr
//   3. k = 1 → return lists[0]
//   4. 链表长度差异很大（有的很长有的为空）→ 分治和堆不受影响
//   5. 分治时两个链表合并后可能比原来长很多，但不影响正确性
