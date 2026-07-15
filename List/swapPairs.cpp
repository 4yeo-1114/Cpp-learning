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
    //在head前添加一个哑节点 这样就可以使第一组的操作和后面组的操作都一样 这样就可以做循环
    ListNode* swapPairs(ListNode* head) {
       if(head==NULL||head->next==NULL){
        return head;
       }
       struct ListNode dummyNode ;
       dummyNode.next  = head;
       struct ListNode* temp = &dummyNode;
       //只要temp后有两个就可以交换
       while(temp->next!=NULL&&temp->next->next!=NULL){
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = node1->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        //node1成为新的起点
        temp = node1;
       }
       return dummyNode.next;
    }
   
};