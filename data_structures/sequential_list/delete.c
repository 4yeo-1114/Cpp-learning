/* C | sequential list: delete. */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 // 顺序表最大容量

typedef struct{
	int data[MAXSIZE]; //储存元素的数组
	int length; 
}SeqList;
int InsertSeqList(SeqList *L, int i , int e){
	if(i<1 || i> L->length+1) return 0;
	if(L->length > MAXSIZE) return 0;
	for(int j  = L->length; j>=i;--j){
		L->data[j] = L->data[j-1];
		
	}
	L->data[i - 1] = e; //插入 
	L->length++; //长度加一 
	
} 
void PrintfSeqList(SeqList L){
	for(int i  = 0; i< L.length;i++){
		printf("%d ", L.data[i]);
		
	}
	printf("\n");
}
int DeleteSeqList(SeqList *L,int i,int*e){
	if(i<1 || i > L->length){
		return 0; 
	}
	*e  = L->data[i-1]; // 保留被删除的元素；
	 // 从被删除位置的下一个元素开始 依次向前移动
	 for(int j =i; j<L->length;++j){
	 	L->data[j-1] = L->data[j];
	 } 
	 L->length--; // 长度减一
	 return 1; 
}
int main(){
	SeqList L;
	L.length  = 0;
	InsertSeqList (&L,1,10);
	InsertSeqList (&L,2,20);
	InsertSeqList (&L,3,30);
	int delVal;
	if(DeleteSeqList(&L,2,&delVal)){
		printf("删除成功，删除的值是：%d\n", delVal);
	}
	PrintfSeqList(L);
	return 0;
	
}
