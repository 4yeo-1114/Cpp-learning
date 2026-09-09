/* C++ | greedy: merge fruits. */
//本质就是哈夫曼树
//每次合并重量最小的两堆果子即可

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 优化输入输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    if (!(cin >> num)) return 0;

    // 定义一个小根堆（优先队列），它会自动把最小的元素放在最前面 top()
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // 读取输入并放入小根堆
    for (int i = 0; i < num; ++i) {
        int x;
        cin >> x;
        min_heap.push(x);
    }

    long long total_cost = 0; // 养成好习惯：代价总和用 long long 防溢出

    // 只要堆里还有至少两堆果子，就继续合并
    while (min_heap.size() > 1) {
        // 取出当前最小的两个元素
        int first_min = min_heap.top(); 
        min_heap.pop();
        
        int second_min = min_heap.top(); 
        min_heap.pop();

        // 合并代价
        int merged_weight = first_min + second_min;
        total_cost += merged_weight;

        // 将合并后的新重量重新放回堆中，堆会自动将其排到合适的位置
        min_heap.push(merged_weight);
    }

    cout << total_cost << "\n";

    return 0;
}

//用桶排序加双队列
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int k,x,num,n1,n2,a1[30001],a2[30001],t[20001],w,sum;
int main()
{
	scanf("%d",&num);
    /*这里 127/3 等于 42（十六进制 0x2A）。memset 是按字节赋值的，
    这会让 a1 和 a2 数组里的每一个 int 都变成 0x2A2A2A2A（大约是 7 亿多）。这个巨大的数字充当了“哨兵”（无穷大）。
    当数组有效元素取完后，程序读到的就是无穷大，从而避免了繁琐的越界判断。*/
	memset(a1,127/3,sizeof(a1));
	memset(a2,127/3,sizeof(a2));
    //下面两个for实现了桶排序
	for (int i=1;i<=num;i++)
	{
		scanf("%d",&x);
		t[x]++;//桶 统计每个重量出现了多少次
	}
	for (int i=1;i<=20000;i++)
	{
		while (t[i])//桶排序 按顺序展开到数组
		{
			t[i]--;
			a1[++n1]=i;
		}
	}
	//a1 是原始数列 a2是合并结果数列 因为合并结果一定也是递增 所以可以用双队列
	int i=1,j=1;
	k=1; 
	while (k<num)
	{
		if (a1[i]<a2[j])//取最小值
		{
			w=a1[i];
			i++;
		}
		else
		{
			w=a2[j];
			j++;
		}
		if (a1[i]<a2[j])//取第二次
		{
			w+=a1[i];
			i++;
		}
		else
		{
			w+=a2[j];
			j++;
		}
		a2[++n2]=w;//加入第二个队列
		k++;//计算合并次数
		sum+=w;//计算价值
	}
	printf("%d",sum);
}

