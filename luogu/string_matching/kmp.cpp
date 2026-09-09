/* C++ | string matching: kmp. */
#include <stdio.h>
void cal_next(char *str, int *next,int len){
	next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
	int k =-1;//k初始化为-1
	for (int q = 1; q<=len-1;q++){
		while(k>-1 && str[k+1] != str[q]){//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
			k = next[k]; //往前回溯，反正就是让k变小，继续试 写k--是一样的 
			
		}
		if(str[k+1] == str[q]){ // 如果相同 
			k = k+1;
		}
		next [q] = k; //这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
	}
} 
//比如我们已经知道ababab，q=4时，next[4]=0（k=0，表示该字符串的前5个字母组成的子串ababa存在相同的最长前缀和最长后缀的长度是1，所以k=0,next[4]=0。这个结果可以理解成我们自己观察算的，也可以理解成程序自己算的，这不是重点，重点是程序根据目前的结果怎么算next[5]的）.，那么对于字符串ababab，我们计算next[5]的时候，此时q=5, k=0（上一步循环结束后的结果）。那么我们需要比较的是str[k+1]和str[q]是否相等，其实就是str[1]和str[5]是否相等！，为啥从k+1比较呢，因为上一次循环中，我们已经保证了str[k]和str[q]（注意这个q是上次循环的q）是相等的（这句话自己想想，很容易理解），所以到本次循环，我们直接比较str[k+1]和str[q]是否相等（这个q是本次循环的q）。
//如果相等，那么跳出while()，进入if()，k=k+1，接着next[q]=k。即对于ababab，我们会得出next[5]=2。 这是程序自己算的，和我们观察的是一样的。
//如果不等，我们可以用”ababac“描述这种情况。 不等，进入while、
//里面，进行k=next[k]，这句话是说，在str[k + 1] != str[q]的情况下，我们往前找一个k，使str[k + 1]==str[q]，是往前一个一个找呢，还是有更快的找法呢？ 一个一个找必然可以，即你把 k = next[k] 换成k- -也是完全能运行的。但是程序给出了一种更快的找法，那就是 k = next[k]。 程序的意思是说，一旦str[k + 1] != str[q]，即在后缀里面找不到时，我是可以直接跳过中间一段，跑到前缀里面找，next[k]就是相同的最长前缀和最长后缀的长度。（这个解释能懂不？）

int KMP(char *str, int slen, char *ptr,int plen){
	int *next = new int [plen];
	cal_next(ptr, next,plen); // 计算next 数组 
	int k = -1;
	for (int i = 0 ;i<slen ; i++){
		while(k>-1 && ptr[k+1] != str[i]) ////ptr和str不匹配，且k>-1（表示ptr和str有部分匹配！）
		k = next[k]; // 看部分匹配的ptr字符的next为多少，下次直接把ptr移动next[k]位 
		if (ptr[k+1] == str[i])
		k = k+1;
		if (k == plen -1){//说明k移动到ptr的最末端
			return i - plen +1; //如下例就是16-7+1. 
		}
	}
	
	return -1;//匹配失败就-1 
}
int main(){
	char *str = "bacbababadababaca";
	char *ptr = "ababaca";
	int a = KMP(str,17,ptr,7);
	printf("%d",a);
	return 0;
}
