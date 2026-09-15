#include<iostream>
using namespace std;

const int maxn = 10000;

int m;  //命令数 
int n = 0;  //线性表中元素个数（初始为0）
int arr[maxn];

// 1. 在顺序表的第 i 个位置插入元素 x
void Insert(int i, int x){
    // 判断插入位置是否合法 (i 应该在 1 到 n+1 之间)
    if (i < 1 || i > n + 1) return;
    // 判断是否超出数组容量
    if (n >= maxn - 1) return;

    // 将第 i 个位置及之后的元素统一后移一位
    // 注意：必须从后往前移动，否则会覆盖数据
    for (int j = n; j >= i; j--) {
        arr[j + 1] = arr[j];
    }
    
    arr[i] = x; // 在空出的第 i 个位置放入 x
    n++;        // 元素总数加 1
} 

// 2. 删除顺序表第 i 个位置的元素
void DeleteByIndex(int i){
    // 判断删除位置是否合法 (i 应该在 1 到 n 之间)
    if (i < 1 || i > n) return;

    // 将第 i 个位置之后的元素统一前移一位
    // 从前往后移动，覆盖掉要删除的元素
    for (int j = i; j < n; j++) {
        arr[j] = arr[j + 1];
    }
    
    n--; // 元素总数减 1
} 

// 3. 查找元素 x 第一次出现的位置，返回下标
int Find(int x){
    // 遍历下标 1 到 n
    for (int i = 1; i <= n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return 0; // 没找到返回 0
}

// 4. 去除顺序表中所有重复元素，只保留第一次出现的
void EliminateRepeat(){
    // 从第 1 个元素开始遍历
    for (int i = 1; i <= n; i++) {
        // 拿当前元素 arr[i] 与它后面的所有元素进行比较
        for (int j = i + 1; j <= n; ) {
            if (arr[j] == arr[i]) {
                // 发现重复，将 j 后面的元素整体前移一位
                for (int k = j; k < n; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; // 长度减 1
                // 注意：这里不执行 j++，因为前移后 j 位置换成了新元素，需要继续判断
            } else {
                j++; // 没有重复，继续检查下一个
            }
        }
    }
}

// 5. 统计顺序表中值在 [x, y] 范围内的元素个数
int Count(int x, int y){
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] >= x && arr[i] <= y) {
            cnt++;
        }
    }
    return cnt;
}

// 6. 删除顺序表中所有值在 [x, y] 范围内的元素
void DeleteByRange(int x, int y){
    for (int i = 1; i <= n; ) {
        if (arr[i] >= x && arr[i] <= y) {
            // 发现元素在范围内，将其删除（后面元素前移）
            for (int j = i; j < n; j++) {
                arr[j] = arr[j + 1];
            }
            n--; // 长度减 1
            // 同样，这里不执行 i++，因为前移后当前位置是新元素，需要重新判断
        } else {
            i++; // 不在范围内，检查下一个
        }
    }
}

int main(){
	int m,x,y,i;
	cin>>m;
	int choose;
	while(m--){
		cin>>choose;
		switch (choose){
			case 1:
				cin>>i>>x;
				Insert(i,x);
				break;
			case 2:
				cin>>i;
				DeleteByIndex(i);
				break;
			case 3:
				cin>>x;
				cout<<Find(x)<<endl;
				break;
			case 4:
				cin>>x>>y;
				cout<<Count(x,y)<<endl;
				break;
			case 5:
				EliminateRepeat();
				break;
			case 6:
				cin>>x>>y;
				DeleteByRange(x,y);
				break;
		}
	}
	return 0;
}