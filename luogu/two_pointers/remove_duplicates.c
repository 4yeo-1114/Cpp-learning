/* C | two pointers: remove duplicates. */
#include <stdio.h>
#include <stdlib.h>
int removeDuplicates(int *num, int numSize){
	if(numSize == 0) return 0;
	int fast = 1;
	int slow = 1;
	while(fast < numSize){
		if(num[fast] != num[fast-1]){
			num[slow] = num[fast];
			++slow;
		}
		++fast;
	}
	return slow;
} 
int main(){
	int num[] = {0,0,0,1,1,2,3,3,4,4};
	int numSize = sizeof(num)/sizeof(int);
	printf("%d\n", removeDuplicates(num, numSize));
	printf("%d\n",num[2]);
	return 0;
}
