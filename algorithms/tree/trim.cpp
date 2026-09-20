#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

//用二十六叉树实现前缀树 把路径连起来就是一个单词

//定义树的结点 
struct Node{
    Node* son[26]{};
    bool end = false;
};


class Trie {
public:
    Node * root;
    Trie() {
         root  = new Node();
    }

    int find(string word){
        Node* cur = root;
        for(char c:word){
            c -= 'a';
            if(cur->son[c]==nullptr){
                //nullptr表示这个路都没人走过 说明你走错路了 匹配失败
                return 0;
            }
            //移动
            cur = cur->son[c];
        }
        // 看cur是不是终点 2 完全匹配 1 部分匹配
        return cur->end==true?2:1;

    }
    
    void insert(string word) {
        //无论插入什么单词都从root开始
        Node* cur = root;
        for(char c:word){
            c  -= 'a';
            if(cur->son[c]==nullptr){
                //如果还没有这个子节点 就自己new出来
                cur->son[c] = new Node();
            }
            cur = cur->son[c];
        }
        //说明这个节点是word单词的最后一个字母 而且在二十六叉树中是独一无二的
        cur->end = true;
    }
    
    bool search(string word) {
        //完全匹配放回2
        return find(word) == 2;
    }
    
    bool startsWith(string prefix) {
        //部分匹配或者完全匹配 返回非0
        return find(prefix) != 0;
    }
    void destroy(Node*node){
        if(node==nullptr){
            return;
        }
        for(Node* son : node->son){
            destroy(son);
        }
        delete node;
    }
    ~Trie(){
        destroy(root);
    }
};
