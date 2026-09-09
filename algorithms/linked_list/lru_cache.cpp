/* C++ | linked list: lru cache. */
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//用链表写 这不是lru 最近最少使用 而是FIFO
//也做不到O(1)
//所以下面的不对
typedef struct Node{
    int key;
    int value;
    struct Node* next;
}Node;
Node* initList(){
    Node* head = (Node*)malloc(sizeof(Node));
    head ->next =nullptr;
    return head;
}
void tailinsert(Node* head,int key,int value){
    Node* tail = head;
    while(tail->next!=nullptr){
        tail = tail->next;
        if(tail->key==key){
            tail->value=value;
            return ;
        }
    }
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->key = key;
    newnode->value = value;
    tail->next = newnode;
    return ;
}
void deletenode(Node*head){
    if(head->next==nullptr){
        return ;
    }
    else{
        Node* p = head->next;
        head->next = head->next->next;
        free(p);
    }
}
int getvalue(Node* head,int key){
    Node* p = head;
    p = p->next;
    while(p!=nullptr){
        //先判断再往后走 避免访问nullptr
        if(p->key==key){
            return p->value;
        }
        p = p->next;
    }
    return -1;
}
class LRUCache {
public:
    LRUCache(int capacity) {
        list = initList();
        //不能写capacity = capacity 编译不知道哪个是哪个
        this->capacity  = capacity;
        cur_len = 0;
    }
    
    int get(int key) {
       return  getvalue(list,key);
    }
    
    void put(int key, int value) {
        tailinsert(list,key,value);
        cur_len++;

        if(cur_len>capacity){
            deletenode(list);
        }
    }
private:
    int capacity;
    int cur_len;
    Node* list;
};

//使用哈希表和双向节点
//一旦这个节点被添加或者改动 就移动到链表的安全的头部 删除时就删除尾部
//将一个节点移到链表尾部 可分为删除该节点和在头部添加该节点两步 可以在O(1)时间内完成

//双向链表节点
struct DLinkedNode{
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};

class LRUCache{
    private:
        unordered_map<int ,DLinkedNode*> cache;
        //两个头尾哑节点 方便我们删除和插入
        DLinkedNode* head;
        DLinkedNode* tail;
        int size;
        int capacity;
        public:
        LRUCache(int _capacity): capacity(_capacity),size(0){
            head = new DLinkedNode();
            tail = new DLinkedNode();
            head->next = tail;
            tail->prev = head;
        }
        int get(int key){
            if(!cache.count(key)){
                return -1;
            }
            //如果key存在 先通过哈希表定位 再接到头部
            DLinkedNode* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        void put(int key,int value){
            if(!cache.count(key)){
                //如果key不存在 创建一个新的节点 并移动到头部
                DLinkedNode*node  = new DLinkedNode(key,value);
                //添加进哈希表
                cache[key] = node;
                //添加到链表头部
                addTohead(node);
                ++size;
                //如果超出容量 要删除尾部节点
                if(size>capacity){
                    //拿到尾部节点
                    DLinkedNode* removed  = getTail();
                    //删除哈希表中对应项
                    cache.erase(removed->key);
                    //防止内存泄露 
                    delete removed;
                    --size;
                }
            }
            else{
                //如果key存在 更新value 移动到头部
                DLinkedNode *node  = cache[key];
                node->value = value;
                moveToHead(node);
            }
        }
        void addTohead(DLinkedNode*node){
            node->prev = head;
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
        }
        void removeNode(DLinkedNode* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;

        }
        void moveToHead(DLinkedNode* node){
            //先删再移动 这里的删除不会把节点从内存删除
            removeNode(node);
            addTohead(node);
        }
        DLinkedNode* getTail(){
            DLinkedNode* node = tail->prev;
            removeNode(node);
            return node;
        }
};