/* C++ | linked list: reverse list. */
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        struct ListNode* pre = NULL;
        struct ListNode* now = head;
        struct ListNode* nxt = now->next;
        while(now!=NULL){
            now->next = pre;
            pre = now;
            now = nxt;
            if(nxt!=NULL) nxt = nxt->next;
        }
        return pre;
    }
};