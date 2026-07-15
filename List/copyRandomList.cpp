#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
    Node(int _val,Node* _next,Node* _random){
        val = _val;
        next= _next;
        random = _random;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        //可以把新链表和旧链表「混在一起」。
        //依次复制每个节点（创建新节点并复制 val 和 next），
        //把新节点直接插到原节点的后面，形成一个交错链表：
        for(Node*cur=head;cur;cur=cur->next->next){
            cur->next = new Node(cur->val,cur->next,nullptr);
        }
        //假如节点 1 的 random 指向节点 3，
        //那么就把节点 1 的 random 指向节点 3 的下一个节点 3 这样就完成了对 random 指针的复制
        for(Node*cur=head;cur;cur=cur->next->next){
            if(cur->random){
                cur->next->random = cur->random->next;
            }
        }
        //分离
        Node dummy(0);
        Node*tail = &dummy;
        for(Node*cur = head;cur;cur=cur->next,tail=tail->next){
            Node*copy = cur->next;
            tail->next = copy;
            //要恢复原链表的next！！
            cur->next = copy->next;
         }
         return dummy.next;
    }
};


//方法二：用map来记录拷贝情况
class Solution {
public:
    unordered_map<Node*, Node*> copyNode;

    Node* copyRandomList(Node* head) {
        //递归终点
        if(head==nullptr){
            return nullptr;
        }
        //如果有个节点还未被拷贝 则进入拷贝环节
        if(!copyNode.count(head)){
            Node* headNew = new Node(head->val);
            copyNode[head] = headNew;
            //递归
            //新拷贝的节点的next和random等于原来节点（head）的next和random 如此递归直到终点
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        //如果这个节点已经被拷贝过了 直接返回
        //如一个节点可能是多个节点的random
        return copyNode[head];
    }
};
