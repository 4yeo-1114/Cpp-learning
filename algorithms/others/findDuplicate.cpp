class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0; // 0 一定不在环上，适合作为起点
        while (true) {
            slow = nums[slow]; // 等价于 slow = slow.next
            fast = nums[nums[fast]]; // 等价于 fast = fast.next.next
            if (fast == slow) { // 快慢指针移动到同一个节点
                break;
            }
        }
        //这里得到的slow不是环入口 而是环内某个点而已

        // 从链表起点 head=0，和刚才环内相遇点的 `slow`，**两个指针同速一步一步往前走**；
        // 直到两者相遇，相遇位置就是**环的入口**，也就是我们要找的重复数字。

        int head = 0; // 再用一个指针，从起点出发
        while (slow != head) {
            slow = nums[slow];
            head = nums[head];
        }
        return slow; // 入环口即重复元素
    }
};

