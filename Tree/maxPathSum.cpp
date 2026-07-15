/**
 * LeetCode 124. 二叉树中的最大路径和
 * 目标：找一条路径（沿父子连接），使节点值之和最大
 * 复杂度：时间 O(N)，空间 O(H)（递归栈，H 为树高）
 */
#include <algorithm>
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int maxSum = INT_MIN;  // 全局最大路径和，INT_MIN 处理全负数情况

public:
    // 后序遍历：返回从 root 向下延伸的"最大单边路径和"（左或右只能选一边）
    int maxGain(TreeNode* root) {
        if (!root) {
            return 0;                         // 空节点贡献 0
        }
        // 递归左右子树，负数则舍弃（取 0）
        int leftgain  = max(maxGain(root->left),  0);
        int rightgain = max(maxGain(root->right), 0);

        // 以当前节点为拐弯点，左右都取，更新全局答案
        int pathnowsum = root->val + leftgain + rightgain;
        maxSum = max(maxSum, pathnowsum);

        // 返回给父节点：当前值 + 左右中较大的一边（只能选一条路向上）
        return root->val + max(leftgain, rightgain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

// ============================================================
// 总结
// ============================================================
// 1. DFS 做两件事：
//    - 返回"单边最大贡献"给上层（继续往上延伸）
//    - 用"双边贡献"（左+根+右）更新答案（路径在此拐弯）
//
// 2. max(gain, 0) 是关键：子树贡献为负时直接舍弃，不走那边
//
// 3. maxSum 初始化为 INT_MIN 而非 0：树上全是负数时，必须选一个
//
// 4. 本质是树形 DP：每个节点维护"传递值"和"更新值"，后序遍历自底向上
//
// 5. 同类模板题：LC 543（二叉树直径）、LC 687（最长同值路径）
//    —— 都是"单边返回 + 双边更新答案"的套路
