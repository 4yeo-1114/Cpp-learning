/* C++ | greedy: remove digits. */
#include <iostream>
#include <string>
using namespace std;
int n,k,a[1000],rest,t = 1,minp,cnt = 0;
bool flag = 0;
string num;
int main(){
    cin>>num>>k;
    n = num.length();
    for(int i = 1;i<=n;i++) a[i] = num[i-1]-'0';
    //rest 表示剩下的位数 也是我们循环的次数
    rest = n-k;
    while(cnt<rest){
        //在取出的k+1个序列中找最小值
        //t为当前搜索起点
        minp = t;
        //在可删范围内找最小值
        for(int i = t;i<=t+k;i++){
            if(a[i]<a[minp]) minp = i;
        }
        //最小值不是零的时候才输出 又因为这里可以有前导零 所以不影响删除
        if(a[minp]) flag = 1;
        //更新要删除的位数和起点
        k -= minp - t;
        t = minp+1;
        cnt++;
    }
    //如果结果全是零 输出零
    if(!flag) cout<<0;
    return 0;
}
/*我们希望从左开始在尽量大的范围内找到一个最小的数作为结果的第一位，然后把左边的删了
但范围不能超过m+1，否则可能删除超过m个数
第一位找到后是第二位，同理，这很贪心*/
//这里我们不用真的删 把筛选出来的最小值输出就行