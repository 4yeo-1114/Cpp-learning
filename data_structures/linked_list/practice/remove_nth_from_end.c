/* C | linked list: remove nth from end. */
struct Node * removeNthFromend(struct Node* head,int n){
	// 创建哑节点，简化头节点删除
	struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
	dummy->next =  head;
	struct Node *fast = dummy;
	struct Node*slow = dummy;
	for(int i = 0;i<n;i++){//提前移动快指针 
		if(fast == NUll) 
		return head ;//n不合法 
		fast = fast->next;
	} 
	while(fast!=NULL){
		fast = fast->next;
		slow = slow->next; 
	}
	//slow后面那个就是倒数第n个 
	struct Node* temp = slow->next;
	slow ->next = temp->next;
	free(temp);
	struct Node * newhead =  dummy->next;
	free(dummy);
	return newhead;
}
