#include <vector>
#include <iostream>
#include <stack>
using namespace std;
  struct TreeNode {
      int val;
    TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//搜索二叉树加中序遍历就是升序排列 这样就可以找到第k小的元素了
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        //这套逻辑想象成“在一座满是房间的城堡里探险”，栈（stack）就是你的“备忘录”。
        //外层大循环:只要你当前还没走到死胡同（root 不为空），
        //或者备忘录里还有没退回的房间（栈不为空）就继续。
        while(root!=NULL||s.size()>0){
            //栈顶就是当前树最小值
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root = s.top();
            s.pop();
            k--;
            //刚好数到了第 k 个，目标出现！直接 break 
            if(k==0){
                break;
            }
            //如果当前节点还不是第 k 个，那接下来该去哪？
            //根据“左-中-右”的规则，当前节点（中）处理完了，
            //比它稍微大一点点的元素，一定藏在它的右子树里！所以把指针指向 root->right，
            //在下一次外层大循环时，程序又会重复“疯狂向左钻”的动作，去挖掘那片新区域的最小值。
            root = root->right;
        }
        return root->val;
    }
};