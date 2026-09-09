/* C++ | tree: validate bst. */
#include <vector>
#include <iostream>
using namespace std;
  struct TreeNode {
      int val;
    TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
不能只看相邻的父子节点，
而是要在向下递归的过程中，
把允许的值域范围（最小值，最大值）一层层传下去。
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MAX,LONG_MIN);      
    }
    bool valid(TreeNode *root,long long max,long long min){
        if(root==NULL){
            return true;
        }
        if(root->val<=min||root->val>=max){
            return false;
        }
        //递归检查左子树：上限被当前节点卡死（传 node->val 作为最大值）
        //递归检查右子树：下限被当前节点卡死（传 node->val 作为最小值）
        else return valid(root->left,root->val,min) && valid(root->right,max,root->val);
    }
};























/*下面这样写是错的
二叉搜索树的严格定义是——左子树上的所有节点（包括所有的孙子、曾孙）都必须小于根节点，
右子树上的所有节点都必须大于根节点。只检查直接子节点是不够的
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if((root->left!=NULL&&root->left->val>=root->val)||(root->right!=NULL&&root->right->val<=root->val)){
            return false;
        }
        else return isValidBST(root->left)&&isValidBST(root->right);
    }
};