# Recursion Notes

原文件为学习笔记或伪代码，不作为独立编译单元。

```text
//递归
void p(参数表){
	if(递归结束条件成立) 可直接求解;
	else p(较小的参数); 
} 

//当递归条件结束时只执行return操作
void p(参数表){
	if(递归结束的条件不成立)
	p(较小的参数); 
} 
// 如输出链表的元素
void TraverseList(LinkList p){
	if(p){
		printf("%d",p->data);
		TraverseList(p->next);
	}
}

// Hanoi塔的递归问题
void hanoi(int n,char A,chae B,char C){
	//把塔座A上的n个圆盘按规则移动到C上，B作为辅助圆盘； 
	if(n==1) move(A,1,C) //如果只有一个 直接把编号为1的圆盘移动到C上
	else{ //否则 
		hanoi(n-1,A,C,B); //把A上编号为1-n-1的圆盘移动到B上，C作为辅助圆盘
		 move(A,n,C); //把编号为n的圆盘直接移动到C
		 hanoi(n-1,B,A,C); // 再把编号1-n-1的圆盘从B移动到C 
	} 
} 

```
