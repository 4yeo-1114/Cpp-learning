#include <stdio.h>
#include <stdlib.h>
//反转链表 
typedef struct Node{
	int val;
	struct Node *next;
}node;


void reverse(node * head){
    node *now = head->next;
    node * pre = NULL;
    while(now){
        if(now->next==NULL){
            head->next = now;
            now->next = pre;
            break;
        }
        //先存nxt 再改now
        node* nxt = now->next;
        now->next = pre;
        pre = now;
        now = nxt;
    }
}

//反转从left到right
void reversei(node *head,int left,int right){
    if (!head || left >= right) return;

    node*Lpre = head;
    node*Lnow = head->next;
    while(--left){
        Lpre = Lnow;
        Lnow =Lnow->next;
        right -- ; 
    }
    //循环出来得到的right就相当于反转次数了
    
    node *Rpre =NULL;
    node *Rnow  = Lnow;
    node* nxt = NULL;
    while(--right){
        nxt = Rnow->next;
        Rnow->next =Rpre;
        Rpre = Rnow;
        Rnow = nxt;

    }
    Lpre->next =Rpre;
    Lnow->next = Rnow;

}