//将升序数组组成平衡搜索二叉树
//因为数组已经升序了 所以中间值一定是根节点
//然后根节点左子树一定是左半边数组的中间值 右子树同理故可递归
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
 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //传入数组即左右索引即可
        return buildTree(nums,0,nums.size()-1);
    }
    TreeNode* buildTree(vector<int>&nums,int left,int right){
        if(left>right){
            return NULL;
        }
        int mid = left+ (right-left)/2;
        //创建根节点
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums,left,mid-1);
        root->right = buildTree(nums,mid+1,right);
        return root;
    }
};