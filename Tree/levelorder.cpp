#include <vector>
#include <iostream>
#include <algorithm>

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
    typedef struct Node{
        TreeNode* data;
        struct  Node*pre;
        struct  Node*next;
    }Node;
    Node* initQueue(){
        Node* q = (Node*)malloc(sizeof(Node));
        q->data = NULL;
        q->pre = q;
        q->next = q;
        return q;
    }
    void enQueue(TreeNode* data,Node* q){
        Node *n = (Node*)malloc(sizeof(Node));
        n->data = data;
        n->pre = q->pre;
        n->next = q;
        q->pre->next = n;
        q->pre = n;
    }
    int isEmpty(Node* q){
        if(q->next==q){
            return  1;
        }
        else return 0;
    }
    Node* deQueue(Node*q){
        if(isEmpty(q)){
            return NULL;
        }
        else{
            Node* node = q->next;
            q->next->next->pre = q;
            q->next = q->next->next;
            return node;
        }

    }
    int getQueueSize(Node* q){
        int size = 0;
        Node* curr = q->next;
        while(curr!=q){
            size++;
            curr = curr->next;
        }
        return size;
    }
     vector<vector<int>> levelOrder(TreeNode* root) {
        Node *q  = initQueue();
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        enQueue(root,q);
        while(!isEmpty(q)){
            //先获取当前层的元素个数
            int  currsize  =  getQueueSize(q);
            vector<int> currlevel;
            for(int i = 0;i<currsize;i++){
                Node *node = deQueue(q);
                currlevel.push_back(node->data->val);
                if(node->data->left){
                    enQueue(node->data->left,q);
                }
                if(node->data->right){
                    enQueue(node->data->right,q);
                }
                //deQueue没删内存
                 free(node);
            }
            //再把当前层的数组入队
           ans.push_back(currlevel);
        }
        //释放队列头节点
        free(q);
        return ans;
    }
};


//调用queue写

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans; // 提前拦截空树，防止崩溃
        }

        // 使用 C++ 标准库中的队列，存放节点指针
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int currentLevelSize = q.size(); // 核心：获取当前层的节点总数
            vector<int> currentLevel;        // 用来存放当前层的值

            // 仅仅循环当前层的节点数次
            for (int i = 0; i < currentLevelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                // 把下一层的节点塞入队列，它们不会影响当前这轮 for 循环
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // 当前层处理完毕，将这一层的数组整体放入最终答案中
            ans.push_back(currentLevel);
        }

        return ans;
    }
};