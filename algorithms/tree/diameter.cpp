/* C++ | tree: diameter. */
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

//链:node子树的叶子节点到node的路径 把node子树中最长链的长度 作为dfs(node)的放回值
//直径:枚举每个node 直径就是两边最长链之和 去更新答案最大值
//dfs(node)返回的是链长度而不是直径 如果是直径再与其他链拼接就不是直径了
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        //返回node子树的最大链长
        auto dfs = [&](this auto&&dfs,TreeNode* node)->int{
            if(node==NULL){
                return -1; //空节点链长是-1
                //这样单个无子树的叶子其链长归并后就是0
            }
            //左边最大链长
            int l_len = dfs(node->left)+1;
            //右边
            int r_len = dfs(node->right)+1;
            //更新答案
            ans = max(ans,l_len+r_len);
            return max(l_len,r_len);//当前子树最大链长
        };

        dfs(root);
        return ans;
    }
};
//其实就是算左右两边最大高度（直径就是高度和） 再遍历每个节点算ans

//写法二：
class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        //边数等于点数减一
        return ans - 1;
    }
};
