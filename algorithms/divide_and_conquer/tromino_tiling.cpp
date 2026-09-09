/* C++ | divide and conquer: tromino tiling. */
#include <iostream>

using namespace std;

using ll = long long;

// x, y: 缺失方格的坐标
// a, b: 当前子棋盘的左上角坐标
// l: 当前子棋盘的边长
void solve(ll x, ll y, ll a, ll b, ll l) {
    // 递归边界：如果棋盘只剩 1x1，不需要放骨牌了，直接返回
    if (l == 1) return;

    ll half = l / 2;
    ll center_x = a + half; // 中心点的行坐标
    ll center_y = b + half; // 中心点的列坐标

    // 1. 缺失方格在【左上角】的子棋盘中
    if (x < center_x && y < center_y) {
        // 在中心放置骨牌，覆盖右上、左下、右下三个子棋盘的内角
        cout << center_x << " " << center_y << " 1\n";
        
        solve(x, y, a, b, half);                                  // 递归左上（缺失方格依然在里面）
        solve(center_x - 1, center_y, a, center_y, half);         // 递归右上（新缺失点在骨牌占据的位置）
        solve(center_x, center_y - 1, center_x, b, half);         // 递归左下（新缺失点在骨牌占据的位置）
        solve(center_x, center_y, center_x, center_y, half);      // 递归右下（新缺失点在骨牌占据的位置）
    }
    // 2. 缺失方格在【右上角】的子棋盘中
    else if (x < center_x && y >= center_y) {
        cout << center_x << " " << center_y - 1 << " 2\n";
        
        solve(center_x - 1, center_y - 1, a, b, half);            // 递归左上
        solve(x, y, a, center_y, half);                           // 递归右上（缺失方格在这里）
        solve(center_x, center_y - 1, center_x, b, half);         // 递归左下
        solve(center_x, center_y, center_x, center_y, half);      // 递归右下
    }
    // 3. 缺失方格在【左下角】的子棋盘中
    else if (x >= center_x && y < center_y) {
        cout << center_x - 1 << " " << center_y << " 3\n";
        
        solve(center_x - 1, center_y - 1, a, b, half);
        solve(center_x - 1, center_y, a, center_y, half);
        solve(x, y, center_x, b, half);                           // 递归左下（缺失方格在这里）
        solve(center_x, center_y, center_x, center_y, half);
    }
    // 4. 缺失方格在【右下角】的子棋盘中
    else {
        cout << center_x - 1 << " " << center_y - 1 << " 4\n";
        
        solve(center_x - 1, center_y - 1, a, b, half);
        solve(center_x - 1, center_y, a, center_y, half);
        solve(center_x, center_y - 1, center_x, b, half);
        solve(x, y, center_x, center_y, half);                    // 递归右下（缺失方格在这里）
    }
}

int main() {
    // 提速 cin 和 cout，因为这道题输出量可能非常大
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    ll x, y;
    
    // 输入 k，以及特殊方格的坐标 x, y
    if (cin >> k >> x >> y) {
        // 利用位移快速求 2^k，等价于原代码的 fun() 函数
        ll len = 1LL << k; 
        // 初始调用，起点坐标为 (1, 1)
        solve(x, y, 1, 1, len);
    }
    
    return 0;
}