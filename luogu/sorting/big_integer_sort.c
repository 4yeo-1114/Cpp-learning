/* C | sorting: big integer sort. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct s {
	char vote[100];
	int num;
}s[100]; 
int cmp(const void*a, const void*b){
	//要先将void型改为struct s型 不能直接上strcmp函数 
	struct s *sa = (struct s*)a;
	struct s *sb = (struct s*)b;
	int lenA = strlen(sa->vote);
	int lenB = strlen(sb->vote);
	//先按长度排序 
	if(lenA!=lenB){
		return lenB - lenA;
	} 
	//长度一样再用strcmp函数 
	else {
		return strcmp(sb->vote,sa->vote);
	}
} 
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0;i <n;i++){
		scanf("%s",&s[i].vote);
		s[i].num = i+1;
	}
	qsort(s,n,sizeof(struct s),cmp);
	printf("%d\n%s",s[0].num,s[0].vote);
	return 0 ;
} 
