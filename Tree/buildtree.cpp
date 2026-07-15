//已知先序遍历和中序遍历 建立一颗二叉树
//先序遍历第一个节点为根节点 在中序中找到该节点 左边个数即为左子树个数 右边为右子树个数
//这样就可递归构造左右子树 关键就在于用哈希表这样在中序中找根节点就很块了
#include <unordered_map>
#include <vector>
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
    unordered_map<int,int> index;
public:
    TreeNode* mybuildTree(const vector<int>&preorder,const vector<int>& inorder,int preorder_left,int preorder_right,int inorder_left,int inorder_right){
        //边界条件
        if(preorder_left>preorder_right){
            return nullptr;
        }
        //前序遍历中第一个就是根
        int preorder_root = preorder_left;
        //利用哈希表中中序中定位
        int inorder_root = index[preorder[preorder_root]];
        //建立根节点
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        //左子树个数
        int size_left = inorder_root - inorder_left;
        //递归构造左子树
        //下标要写左子树在两个序列中对应的边界
        root->left = mybuildTree(preorder,inorder,preorder_left+1,preorder_left+size_left,inorder_left,inorder_root-1);
        //右子树
        root->right = mybuildTree(preorder, inorder, preorder_left + size_left + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0;i<n;i++){
            index[inorder[i]] = i;
        }
        return mybuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};