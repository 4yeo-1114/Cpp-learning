/* C | linked list: reverse list. */
#include <stdio.h>
#include <stdlib.h>
//反转链表 
typedef struct Node{
	int val;
	struct Node *next;
}node;

void reverse(node *head){
	node *now = head->next;
	node * pre = NULL;
	while(now){
		if(now->next==NULL){
			head->next = now;
			now->next = pre;
			break;
		}
		node * nxt = now->next;
		now->next = pre;
		pre = now;
		now = nxt;
	}
}
//反转从 left 到 right 的链表（带头节点，1-indexed）
void reverseIndes(node *head, int left, int right) {
    if (!head || left >= right) return;

    node *Lpre = head;
    node *Lnow = head->next;

    // 1. 定位到第 left 个节点（移动 left - 1 次）
    while (--left) {
        Lpre = Lnow;
        Lnow = Lnow->next;
        right--;
    }
	 //循环出来得到的right就相当于反转次数了

    // 2. 局部反转区间 [left, right]
    node *Rpre = NULL;
    node *Rnow = Lnow;
    node *nxt = NULL;

    // 区间长度为修改后的 right 步（共需反转 right 次）
    while (right--) {
        nxt = Rnow->next;   // 保存下一个节点
        Rnow->next = Rpre;  // 指针转向
        Rpre = Rnow;        // 前移
        Rnow = nxt;
    }

    // 3. 缝合前后两端
    Lpre->next = Rpre;      // 左前驱指向反转后的新表头
    Lnow->next = Rnow;      // 反转后的尾节点接上后续未反转部分
}