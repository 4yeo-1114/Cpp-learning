/* C | linked list: recursive merge. */
struct node* mergeList(struct node* list1,struct node* list2){
	//递归终止条件
	if(list1==NUll) return list2;
	if(list2==NULL) return list1;
	
	if(list1->data <= list2->data){
		list1->next = mergeList(list1->next,list2);
		return list1;
	}else{
		list2->next = mergeList(list1,list2->next);
		return list2;
	}
} 
