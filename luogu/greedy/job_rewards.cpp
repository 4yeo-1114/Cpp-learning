/* C++ | greedy: job rewards. */
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct f {
  long long d;// 任务的截止时间
  long long p;// 完成任务可获得的收益
} a[100005];// 存储所有任务的数组
//比较函数 
bool cmp(f A, f B) { return A.d < B.d; }

// 小根堆维护最小值
priority_queue<long long, vector<long long>, greater<long long> > q;
// 小根堆维护最小值
priority_queue<long long, vector<long long>,greater<long long> > q; 
int main() {
  long long n, i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i].d >> a[i].p; //依次读取每个任务的截止时间和收益
  }
  sort(a + 1, a + n + 1, cmp);//按截至时间从小到大排序 
  long long ans = 0;
  for (i = 1; i <= n; i++) {
  	// 如果当前任务的截止时间 <= 已选任务数量（无法直接加入）
    if (a[i].d <= (int)q.size()) {  // 超过截止时间
     // 如果当前任务收益比已选任务中最小的收益高
	  if (q.top() < a[i].p) {       // 后悔
        ans += a[i].p - q.top();
        q.pop();
        q.push(a[i].p);
      }
    } else {  // 直接加入队列
      ans += a[i].p;
      q.push(a[i].p);
    }
  }
  cout << ans << endl;
  return 0;
}

