/* C++ | hash: difference pairs. */
#include <iostream>   // 输入输出流
#include <map>        // 引入map容器
using namespace std;
typedef long long LL; // 将long long简化为LL，方便使用
LL a[200001];         // 存储输入的数组，大小200001可以应对大部分测试用例
map<LL,LL> m;         // map容器：键是数字，值是该数字出现的次数
int main() {
    int n;
    LL c;
    LL ans=0;        // 用于累计符合条件的数对数量
    cin >> n >> c;   // 输入n(数组长度)和c(差值)
    
    // 第一遍遍历：构建map并预处理数组
    for(int i=1;i<=n;i++) {
        cin >> a[i];         // 读取原始数字
        m[a[i]]++;           // 将数字存入map，同时计数（核心操作1）
        a[i]-=c;             // 将数组元素改为a[i]-c，为后续查询做准备
    } 
    
    // 第二遍遍历：统计符合条件的数对
    for(int i=1;i<=n;i++) {
        ans += m[a[i]];      // 累加符合条件的数量（核心操作2）
    }
    
    cout << ans << endl;
    return 0;
}

//重写
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;
typedef long long LL;
LL a[1000000];
map<LL,LL> m //定义一个map为m 
int main(){
	cin>>n>>c;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		map[a[i]]++;
		a[i] -= c;
	}
	int ans;
	for(int i = 0;i<n;i++){
		ans += map[a[i]];
	}
	cout<<ans<<endl;
	return 0;
	
} 
