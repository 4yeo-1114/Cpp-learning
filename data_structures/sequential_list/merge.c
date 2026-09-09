/* C | sequential list: merge. */
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 100
//顺序表结构定义
typedef struct{
	int data[MAXSIZE];
	int length;
}sqList;

//获取长度
int ListLength(sqList L){
	return L.length; 
}
// 获取顺序表第i个元素
bool GetElem(sqList L,int i, int *e){
	if(i<1 || i>L.length){
		return false;
	}
	*e = L.data[i-1];
	return true;
} 

// 在顺序表中查找元素e, 存在返回true,否则返回False
bool LocateELem(sqList L, int e){
	for(int i = 0; i<L.length;i++){
		if(L.data[i] == e){
			return  true;
		}
	}
	return false;
} 

//在顺序表LA末尾插入元素
bool ListInsert(sqList *LA, int e ){
	if(LA->length >= MAXSIZE){
		return false;
	}
	LA->data[LA->length] = e; //在末尾插入
	LA->length++;
	return true; 
} 

// 合并两个元素，删除重复元素
void MergeList(sqList *LA, sqList *LB){
	int m = ListLength(*LA); //外函数传入的是地址 内函数要传这个结构体本身 所以要加* 
	int n = ListLength(*LB);
	int e;
	for(int i = 1; i<n;i++){
		GetElem(*LB,i,&e); //取出元素
		if(!LocateELem(*LA,e)){
			ListInsert(LA,e);
		} 
	}
} 
// 打印
void PrintfSeqList(sqList L){
	for(int i  = 0; i< L.length;i++){
		printf("%d ", L.data[i]);
		
	}
	printf("\n");
} 

int main(){
	sqList LA,LB;
	LA.length = 4;
	//初始化
	LA.data[0] = 7;
	LA.data[1] = 5;
	LA.data[2] = 3;
	LA.data[3] = 11; 
	LB.length  = 3;
	LB.data[0] = 2;
	LB.data[1] = 6;
	LB.data[2] = 3;
	
	MergeList(&LA , &LB);   
	printf("合并后："); 
    PrintfSeqList(LA);
	return 0;	
		
	}
	
