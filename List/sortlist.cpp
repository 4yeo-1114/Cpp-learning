#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//自顶向下进行并归排序
//找到链表中点（快慢指针）拆分为两个链表
//递归对这两个链表排序
//合并这两个链表
//递归的终止条件是链表的节点个数小于或等于 1
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head,nullptr);
    }
    ListNode* sortList(ListNode*head,ListNode* tail){
        if(head==nullptr){
            return head;
        }
        //因为sortList是左闭右开的！
        if(head->next==tail){
            head->next = nullptr;
            return head;

        }
        ListNode*slow=head,*fast=head;
        while(fast!=tail){
            slow = slow->next;
            fast = fast->next;
            if(fast!=tail) fast=fast->next;
        }
        ListNode* mid = slow;
        //递归加合并写在一起
        return merge(sortList(head,mid),sortList(mid,tail));
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
            //凭空造一个“假头节点”，随便给个值比如 0。它作为锚点，死死钉在原地不动！
            ListNode* dummyNode = new ListNode(0);
            //l3，负责往后移动拼接
            ListNode* l3 = dummyNode;
            while(l1!=nullptr&&l2!=nullptr){
                if(l1->val<=l2->val){
                    l3->next =l1;
                    l1 = l1->next; 
                }
                else{
                    l3->next = l2;
                    l2 = l2->next;
                }
                //l3记得向后走一步！
                l3=l3->next;
            }
            if(l1==nullptr){
                l3->next = l2;
            }
            else{
                l3->next = l1;
            }
            //这里不是return l3 l3已经走到后面了!
            return dummyNode->next;
    }
};

//方法二：自底向上的并归排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        if(head->next==nullptr){
            return head;
        }
        ListNode* node = head;
        int length = 0;
        while(node!=nullptr){
            node = node->next;
            length ++;
        }
        int sublength = 1;
        //弄一个哑节点
        ListNode* dummy = new ListNode(0,head);
        //每一次循环sublength就*2.
        for(;sublength<=length;sublength<<=1){
            ListNode* pre = dummy,* cur  = dummy->next;
            while(cur!=nullptr){
                ListNode* head1 = cur;
                //cur走到第一段的结尾 或者这一段根本就没有sublength长 即cur->next=nullptr
                for(int i = 1;i<sublength&&cur->next!=nullptr;i++){
                    cur = cur->next;
                } 
                ListNode* head2 =cur->next;
                //让第一段结尾为null
                cur->next = nullptr;
                //cur再成为第二段的开头
                cur = head2;
                //cur有可能为nullptr（当head1已经把剩下的全包进去了，没有第二段了）
                //所以for里面要加一个判断
                for(int i = 1;i<sublength&&cur != nullptr&&cur->next!=nullptr;i++){
                    cur = cur->next;
                } 
                ListNode*next = nullptr;
                if(cur!=nullptr){
                    //记录下一段开头
                    next = cur->next;
                    //给第二段结尾
                    cur->next=nullptr;
                }
                //合并
                ListNode*merged = merge(head1,head2);
                pre->next = merged;
                //pre移动到第二段结尾 为下一次合并做准备
                 while (pre->next != nullptr) {
                    pre = pre->next;
                }
                cur = next;
            }
        }
        return dummy->next;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
            //凭空造一个“假头节点”，随便给个值比如 0。它作为锚点，死死钉在原地不动！
            ListNode* dummyNode = new ListNode(0);
            //l3，负责往后移动拼接
            ListNode* l3 = dummyNode;
            while(l1!=nullptr&&l2!=nullptr){
                if(l1->val<=l2->val){
                    l3->next =l1;
                    l1 = l1->next; 
                }
                else{
                    l3->next = l2;
                    l2 = l2->next;
                }
                //l3记得向后走一步！
                l3=l3->next;
            }
            if(l1==nullptr){
                l3->next = l2;
            }
            else{
                l3->next = l1;
            }
            //这里不是return l3 l3已经走到后面了!
            return dummyNode->next;
            delete dummyNode;
    }
    
};