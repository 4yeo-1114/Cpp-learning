/* C++ | tree: flatten. */
//将二叉树展开为链表
#include <algorithm>
#include <math.h>
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



//方法一 先遍历再改变
class Solution {
public:
    void preorder(TreeNode* root,vector<TreeNode*>& list){
        if(root!=NULL){
            list.push_back(root);
            preorder(root->left,list);
            preorder(root->right,list);
        }
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        vector<TreeNode*> list;
        //先把先序遍历顺序存入列表中
        preorder(root,list);
        //现在列表中的节点关系还是乱的 但是这时候去修改就不用怕乱套 因为我们已经用list存起来了
        for(int i = 1;i<list.size();i++){
            TreeNode* pre = list[i-1];
            TreeNode* cur = list[i];
            pre->left = nullptr;
            pre->right = cur;
        }
    }
};

//方法二：既然前序遍历在修改当前节点时会把右孩子弄丢 反过来 右->左->根开始串连
//先递归到最右子树 及链表的结尾 在用pre记录上一个访问过的节点

class Solution {
public:
    TreeNode* prev =nullptr;
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        //前面的节点已经递归压入栈中了 所以可以对当前节点随意修改
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
