/* C++ | tree: is symmetric. */
//检查二叉树是否轴对称
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
public:
//递归注意点 边界条件判断只考虑当前层就好了 下面的交给递归
    bool isequal(TreeNode* l,TreeNode* r){
        // 第一步：如果两个都为空，说明到底了且一直对称，返回 true
        if(l==NULL&&r==NULL){
            return true;
        }
        //第二步：如果有一个为空另一个不为空，或者两个值不相等，绝对不对称，返回 false
        if((l != NULL && r == NULL) || (l == NULL && r != NULL) || (l->val != r->val)){
            return false;
        }
        // 说明 l 和 r 都不为空，且 l->val == r->val,当前层已经检查完毕.
        // 接下来，不要去管它们的 left 和 right 具体是什么值，直接把它们外包给下一轮的 isequal 去判断！
        return isequal(l->left, r->right) && isequal(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isequal(root->left,root->right);
    }
};