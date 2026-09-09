/* C++ | string: snowden password. */


// 正解
#include<bits/stdc++.h>
using namespace std;
char dic[30][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};//对应
int di[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
unsigned long long int a[10],top,flag;
int i,j;
char s[100];
//bool cmp(const void *a, const void *b){
//	return *(int*)a < *(int*)b;
//} 
int main()
{
     for(i=1;i<=6;i++)
     {
          scanf("%s",&s);//%s读入遇到空格就停止
          for(j=1;j<=26;j++)
          {
               if(!strcmp(s,dic[j]))//strcmp(s1,s2);如果他们相同，返回0
               {
                    a[++top]=di[j];//用数组存储
                    break;//立即停止寻找
               }
          }
      }
      sort(a+1,a+top+1);//贪心，使越小的数越靠前输出
      for(i=1;i<=top;i++)
      {
           if(flag)//如果不是第一位
           {
                printf("%.2d",a[i]);//限制格式输出
           }
           else
           {
                if(a[i])
                { 
                     printf("%d",a[i]);
                     flag=1;
                }
            }
     }
     if(!flag)printf("0");//特判
     return 0;
}
 
 
 //#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>
//int num[10];
//char dic[30][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};//对应
////int di[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
//int cnt  = 0;
//int arr[10];
//long long  min = 10000000000;
//bool num1[110] = {false};
//void fmin(int pos){
//	if(pos==cnt){
//		int ans = 0;
//		for(int i = 0;i<cnt;i++){
//			int p = pow(100,cnt-i-1);
//			ans += arr[i] * p;
//			
//		}
//		if(ans<min){
//			min = ans;
//		}
//		return ;
//	}
//	for(int i = 0;i<cnt;i++){
//		if(!num1[num[i]]){
//		    num1[num[i]] = true;
//			arr[pos] =num[i];
//			fmin(pos+1);
//			num1[num[i]] = false;	
//		}
//	
//	}
//}
//int main(){
//     char s[1000];
//	 fgets(s,sizeof(s),stdin);	
//	 int len  = strlen(s);
//	 for(int i = 0;i<len;i++){
//	 	int j = 0;
//	 	char c[20] = {};
//	 	while(s[i]!=' ' && s[i]!='.'){
//	 		 c[j]  = s[i];
//	 		j++;
//	 		i++;
//		 } 
//	    c[j] = 0;
//	    for(int k = 0;k<20;k++){
//	    	if(strcmp(c,dic[k])==0){
//	    		num[cnt++] = (k*k)%100;
//			}
//			else if(strcmp(c,"another")==0 || strcmp(c,"a")==0||strcmp(c,"first")==0){
//				num[cnt++] = 1;
//			} 
//			else if(strcmp(c,"both")==0||strcmp(c,"second")==0){
//				num[cnt++] = 4;
//			}
//			else if(strcmp(c,"third")==0){
//				num[cnt++]  = 9;
//			}
//		}
//	 }
////	 for(int i = 0;i<cnt;i++){
////	 	printf("%d\n",num[i] );
////	 } 
//    fmin(0);
//    printf("%lld", min);
//	 return 0;
//} 
