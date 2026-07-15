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
    //改为long long 避免溢出
    long long  valid(TreeNode* root,long long  targetSum){
        if(root==nullptr){
            return 0;
        }
        long long  count = 0;
        //哪怕当前节点等于target也不能return 因为后面可能和为零
        if(root->val==targetSum){
            count++;
        }
        count+= valid(root->left,targetSum-root->val);
        count+= valid(root->right,targetSum-root->val);
        return count;

    }
    int pathSum(TreeNode* root, int targetSum) {
      if(root==nullptr){
        return 0 ;
      }
      return valid(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};


//前缀和做法
#include <unordered_map>
using namespace std;
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        // 哈希表记录：<前缀和, 该前缀和出现的次数>
        unordered_map<long long, int> prefixMap;
        // 初始化：前缀和为 0 的路径有 1 条（代表从根节点直接开始的路径）
        prefixMap[0] = 1;
        return dfs(root, 0, targetSum, prefixMap);
    }

private:
    int dfs(TreeNode* root, long long currSum, int targetSum, unordered_map<long long, int>& prefixMap) {
        if (root == nullptr) {
            return 0;
        }

        // 1. 更新当前路径的前缀和
        currSum += root->val;

        // 2. 检查哈希表中是否存在 currSum - targetSum
        int count = 0;
        if (prefixMap.count(currSum - targetSum)) {
            count = prefixMap[currSum - targetSum];
        }

        // 3. 将当前前缀和加入哈希表，为后续子节点提供查阅
        prefixMap[currSum]++;

        // 4. 继续递归左右子树，累加符合条件的路径数
        count += dfs(root->left, currSum, targetSum, prefixMap);
        count += dfs(root->right, currSum, targetSum, prefixMap);

        // 5. 关键步骤：回溯（Backtracking）！
        // 当我们结束当前子树的遍历准备退回父节点时，必须把当前节点带来的前缀和记录抹除
        // 否则它会“污染”平行分支（例如左子树的节点不能和右子树的节点组合成一条向下的路径）
        //即不能让左子树影响右子树
        prefixMap[currSum]--;

        return count;
    }
};