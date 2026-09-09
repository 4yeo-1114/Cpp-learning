/* C | linked list: polynomial sum. */
#include <stdio.h>
#include <stdlib.h>

typedef struct PNode{
	int coef; // 系数
	int expn; //指数
	struct PNode* next; 
}PNode, *Polynomial;

// 创建多项式
void CreatePolyn(Polynomial *p , int n){
	*p = (Polynomial)malloc(sizeof(PNode));
	(*p)->next  =NULL; //初始化头节点的后继NULL;
	for (int i = 1; i<=n;i++){
		//生成新节点
		PNode *s = (PNode *)malloc(sizeof(PNode));
		printf("请输入第%d项的系数和指数", i);
		scanf("%d %d", &s->coef, &s->expn);
		
		PNode *pre = *p; //前驱指针 初始指向头节点
		PNode *q = (*p)->next; // 用于遍历的指针 初始指向首元节点
		
		// 找到一个指数大于当前项指数的节点的前驱位置
		while(q && q->expn < s->expn){
		     pre  = q ;
		     q = q->next;
	}
		// 插入新节点到pre 和 q之间
		s->next = q;
		pre->next = s; 
	} 
} 

// 多项式相加
void AddPolyn(Polynomial *Pa , Polynomial Pb){
	PNode *p1 = (*Pa)->next; //p1指向Pa的首元节点
	PNode *p2 = Pb->next;
	PNode *p3 = *Pa; // p3指向和多项式的当前节点（初始为Pa的头节点）
	// 当p1 和p2 都非空时， 循环比较并处理
	while(p1 && p2){
		if(p1->expn == p2->expn){
			int sum = p1->coef + p2->coef; // 计算系数和 
		
		if(sum != 0){ // 系数和不为零 
			p1->coef = sum; // 修改pa当前节点的系数值
			p3->next  = p1; // 将p1连接到p3后面
			p3 =p1; //p3仍在最后 其实就是尾节点 
			p1 = p1->next; //p1后移 
			
			// 删除pb当前节点并后移
			PNode *r  = p2;
            p2  = p2->next;
			free(r);			 
		}
		else { //系数和为零 全删了 
		  PNode  *r = p1;
		  p1 = p1->next;
		  free(r); 
		  r  = p2;
          p2  = p2->next;
		  free(r);
			
		}
      }
      
    else if(p1->expn < p2->expn){ //系数小的尾接到p3后面 
    	p3->next = p1;
    	p3 = p1;
    	p1 = p1->next;
	}
	 else if(p1->expn > p2->expn){ //系数小的尾接到p3后面 
    	p3->next = p2;
    	p3 = p2;
    	p2 = p2->next;
	}
	
	} 
	// 接上剩余的非空段 
	p3->next  = p1?p1:p2;
	
	//释放Pb的头节点
	free(Pb); 
} 

// 打印多项式
void PrintPolyn(Polynomial P) {
    PNode *p = P->next; //指向首元节点 
    int isFirst = 1; // 标记是否是第一项，用于处理符号

    while (p) {
        if (isFirst) {
            // 第一项系数为正的话，不需要符号；为负则输出负号
            if (p->coef < 0) {
                printf("-");
            }
            isFirst = 0;
        } else {
            // 非第一项，系数为正输出+，为负输出-
            if (p->coef > 0) {
                printf("+");
            }
            else {
            	printf("-");
			} 
        }

        // 处理系数（系数绝对值为1且指数不为0时，系数1可省略）
        if (abs(p->coef) != 1 || p->expn == 0) {
            printf("%d", abs(p->coef));
        }

        // 处理指数
        if (p->expn > 0) {
            printf("x");
            if (p->expn > 1) {
                printf("^%d", p->expn);
            }
        }

        p = p->next;
    }
    printf("\n");
}

int main() {
    Polynomial Pa, Pb;
    int n1, n2;

    printf("请输入多项式A的项数：");
    scanf("%d", &n1);
    CreatePolyn(&Pa, n1);

    printf("请输入多项式B的项数：");
    scanf("%d", &n2);
    CreatePolyn(&Pb, n2);

    printf("多项式A：");
    PrintPolyn(Pa);

    printf("多项式B：");
    PrintPolyn(Pb);

    AddPolyn(&Pa, Pb);

    printf("多项式A + 多项式B 的结果：");
    PrintPolyn(Pa);

    // 释放多项式Pa的内存（简单处理，实际应遍历释放所有节点）
    PNode *p = Pa, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }

    return 0;
}
