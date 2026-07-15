#include <algorithm>
#include <iostream>
using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k<=1){
            return head;
        }
        struct ListNode dummyNode;
        dummyNode.next = head;
        struct ListNode* temp = &dummyNode;
        while(1){
            struct ListNode* test = temp;
            int key = 1;
            //先测试后面有没有k个
            for(int i = 0;i<k;i++){
                test = test->next;
                if(test==NULL){
                    key = 0;
                    break;
                }
            }
            //对后面k个进行反转
            if(key){
                struct ListNode* newstart  = test->next;// 下一阶段的起点
                struct ListNode* pre =newstart;
                struct ListNode* now = temp->next;
                struct ListNode* nxt = NULL;
                // now 最终会变成这 k 个节点的尾巴，也就是下一轮的 temp
                struct ListNode* newtemp = now;
                while(now!=newstart){
                    nxt = now->next;
                    now->next = pre;
                    pre = now;
                    now=nxt;
                }
                //反转后记得接上
                temp->next = pre;
                temp  = newtemp;
            }
            else if(key==0){
                break;
            }
        }
        return dummyNode.next;
    }
};