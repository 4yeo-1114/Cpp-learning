/* C | sequential list: insert. */
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
int main(){
	SeqList L;
	L.length = 0; //初始化长度为零
	InsertSeqList(&L, 1, 10); 
    InsertSeqList(&L, 2, 20); 
	InsertSeqList(&L, 2, 15);
	InsertSeqList(&L, 8, 15); // 8超过顺序表“此时”的长度了 
	printf("顺序表内容");
	PrintfSeqList(L); //输出：10 15 20 
	return 0; 
} 
