#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //递归的终止条件
        //要么遇到空节点 说明这条路上什么也没有
        //如果是p或者q 说明找到 把这个节点放回给上一层 告诉他遭到其中一个了
        if(root==nullptr||root==p||root==q){
            return root;
        }
        //递归 把任务分配给左右孩子 看在哪
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        //如果两边都有 说明一边有p 一边有q 自己就是最近祖先
        if(left&&right){
            return root;
        }
        //1 如果只有一边有 如都在左边 返回左子树的结果(不一定是左子树！)
        //2 只找到了p q在p下面 此时p就是答案 依旧返回那个值即可 
        else{
            return left?left:right;
        }

    }
};


//用哈希表记录节点祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //记录每个节点的父亲
        unordered_map<TreeNode*,TreeNode*> parentMap;
        //记录p走过的祖先路径
        unordered_set<TreeNode*> visited;

        function<void(TreeNode*)>dfs = [&](TreeNode* node){
            if(node->left){
                parentMap[node->left] = node;
                dfs(node->left);
            }
            if(node->right){
                parentMap[node->right]  = node;
                dfs(node->right);
            }
        };

        if(root){
            //根节点的祖先为nullptr
            parentMap[root] = nullptr;
            //构造映射
            dfs(root);
        }
        //记录p所有的祖先 包括p
        while(p!=nullptr){
            visited.insert(p);
            p = parentMap[p];
        }
        //遍历q的祖先 看有无与p的祖先列表一样的
        while(q!=nullptr){
            if(visited.count(q)){
                return q;
            }
            q = parentMap[q];
        }
        return nullptr;
    }
};