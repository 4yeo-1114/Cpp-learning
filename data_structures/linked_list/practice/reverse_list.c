/* C | linked list: reverse list. */
#include <stdio.h>
#include <stdlib.h>
//反转链表 
void reverse(node *head){
	node *now = head->next;
	node * pre = NULL;
	while(now){
		if(now->next==NULL){
			head->next = now;
			now->next = pre;
			break;
		}
		node * nxt = = now->next;
		now->next = pre;
		pre = now;
		now = nxt;
	}
}
//反转从l到r的链表
void reverseIndes(node *head, int left,int  right){
	node *Lpre = head;
	node *Lnow = head->next;
	while(l--){
		Lpre = Lnow;
		Lnow = Lnow->next;
		right--;
	}
	node* Rpre = Lpre;
	node* Rnow = Lnow;
	node* nxt  = Lnow->next;
	while(right){
		Rpre = Rnow;
		Rnow = Rnxt;
		Rnow->next = Rpre;
		Rnxt  = Rnxt->next;
	}
	Lpre->next = Rnow;
	Lnow->next = Rnxt;
} 
