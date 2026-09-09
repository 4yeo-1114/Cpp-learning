/* C++ | greedy: kings game. */
#include<bits/stdc++.h>  // 万能头文件，包含所有常用STL头文件（初学者可以用，比赛中常用）
using namespace std;     // 标准命名空间，避免每次写std::
int read() //（替代scanf，更快）
{
    char s;
    int k=0,base=1;  // k存储数字的绝对值，base存储符号（正为1，负为-1）
    // 跳过非数字、非负号的字符（比如空格、换行、制表符）
    while((s=getchar())!='-'&&s!=EOF&&!(s>='0'&&s<='9'));
    if(s==EOF)exit(0);  // 如果读到文件末尾，直接退出程序
    if(s=='-')base=-1,s=getchar();  // 读到负号，标记为负数，再读下一个字符
    // 读取数字的每一位，组装成整数
    while(s>='0'&&s<='9')
    {
        k=k*10+(s-'0');  // 字符转数字：'0'的ASCII码是48，所以s-'0'得到数字值
        s=getchar();
    }
    return k*base;  // 返回带符号的整数
}
void write(int x) //（替代printf，处理整数的递归输出）
{
    if(x<0)  // 处理负数：先输出负号，再递归处理绝对值
    {
        putchar('-');
        write(-x);
    }
    else
    {
        if(x/10)write(x/10);  // 递归：先输出高位（比如x=123，先递归处理12，再处理1）
        putchar(x%10+'0');    // 输出当前位的数字（字符形式）
    }
}
//全局变量定义 
int n,A,B;  // n是物品数量，A/B是初始值（B看起来没用到，可能是题目残留）
struct node  // 定义结构体，存储每个物品的x和y属性
{
    int x,y;
} a[1010];   // 结构体数组，最多存1010个物品
int sum[1010];  // 高精度数组，存储大整数（用于乘法运算）
int ans[1010],ls;  // ans存储当前的除法结果，ls是ans的长度
int p[1010],lp;    // p存储目前找到的最大值，lp是p的长度
int m;  // sum数组的长度（大整数的位数）
int P;  // 高精度除法中的余数临时变量
//排序函数 用于结构体排序 
bool cmp(node aa,node bb)
{
    if (aa.x*aa.y==bb.x*bb.y) return aa.y<bb.y;  // 乘积相等时，按y升序排
    return (aa.x*aa.y)<(bb.x*bb.y);  // 否则按x*y的乘积升序排
}
//ans数组的排序是正常的 因为除法函数，
//而sum是倒序的 
bool Max()//返回true表示ans>p，false表示p>=ans
{
    int i=1;
    while (p[i]==0&&i<=lp) i++;// 跳过p前面的0（前导0），找到有效数字的起始位置
    int j=1;
    while (ans[j]==0&&j<=ls) j++;// 跳过ans前面的0
    // 先比较位数：位数多的数更大
    if (lp-i+1>ls-j+1) return false;// p的有效位数更多，p更大
    if (lp-i+1<ls-j+1) return true;// ans的有效位数更多，ans更大
    // 位数相同，逐位比较（从高位到低位）
    while (i<=lp&&j<=ls)
    {
        if (p[i]<ans[j]) return true;// ans当前位更大，ans更大
        if (p[i]>ans[j]) return false;// p当前位更大，p更大
        i++;
        j++;
    }
    return false;// 所有位都相同，ans不大于p
}
void cheng(int d) //高精位乘法 +四位分段法 比如 12345678 存为[5678,1234] 
{
    // 第一步：逐位相乘（sum的每个元素乘以a[d].x）
    for (int i=1;i<=m;i++)
        sum[i]*=a[d].x;
    // 第二步：处理进位（四位分段法，每一位的范围是0~9999，超过的部分进位到下一位）
    for (int i=1;i<=m;i++)
    {
        sum[i+1]+=sum[i]/10000;  // 高位加上当前位的商（进位）
        sum[i]%=10000;           // 当前位保留余数（0~9999）
    }
    // 如果最高位有进位，数组长度加1
    if (sum[m+1]!=0) m++;
}
void div(int d)
{
    memset(ans,0,sizeof(ans));  // 清空ans数组（memset是按字节赋值，这里置0）
    ls=1;  // ans的长度初始化为1
    while (m>0&&sum[m]==0) m--;  // 跳过sum前面的0，找到有效位数
    P=0;  // 余数临时变量，初始为0
    int flag=0;  // 标记是否开始记录有效数字（避免前导0）
    // 模拟竖式除法：从高位到低位除（因为sum是高位在后？不，这里sum的存储是低位在前？需要看实际存储）
    for (int i=m;i>=1;i--)
    {
        P=P*10000+sum[i];  // 余数乘以10000，加上当前位的数字
        ans[++ls]=P/a[d].y;  // 商的当前位
        // 处理前导0：如果当前位是0且还没遇到有效数字，就减少长度
        if (ans[ls]==0&&!flag) ls--; else flag=1;
        P%=a[d].y;  // 更新余数为当前余数对除数取模
    }
}
int main()
{
    n=read();  // 读入物品数量
    A=read();  // 读入初始值A
    B=read();  // 读入B（未使用，可能是题目残留）
    // 读入每个物品的x和y
    for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
    // 按自定义规则排序
    sort(a+1,a+n+1,cmp);
    // 初始化高精度数组sum：sum[1]=A，长度m=1
    m=1;
    sum[1]=A;
    // 遍历每个物品，先除后乘，记录最大值
    for (int i=1;i<=n;i++)
    {
        div(i);  // 将sum除以a[i].y，结果存在ans中
        if (Max())  // 如果ans比当前最大值p大
        {
            lp=ls;  // 更新p的长度
            memcpy(p,ans,sizeof(ans));  // 将ans复制到p中（memcpy是内存拷贝，比循环快）
        }
        cheng(i);  // 将sum乘以a[i].x，更新sum
    }
    // 输出最大值p（处理前导0，按四位分段输出）
    int i=0;
    while (i<=lp&&p[i]==0) i++;  // 跳过前导0
    printf("%d",p[i]);i++;
    for (;i<=lp;i++)
    {
        // 按四位补0输出（因为是四位分段，不足四位的要补前导0）
        if (0<=p[i]&&p[i]<=9) printf("000%d",p[i]);
        else if (10<=p[i]&&p[i]<=99) printf("00%d",p[i]);
        else if (100<=p[i]&&p[i]<=999) printf("0%d",p[i]);
        else printf("%d",p[i]);
    }
    return 0;
}
