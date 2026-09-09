/* C++ | graph: rotting oranges. */
#include <vector>
#include <queue>
using namespace std;

// LeetCode 994. 腐烂的橘子
// 多源 BFS：初始所有烂橘子同时入队，逐层扩散

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // 1. 初始化：统计新鲜橘子数量，将所有烂橘子入队（多源BFS的起点）
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});          // 烂橘子作为 BFS 第 0 层
                } else if (grid[i][j] == 1) {
                    fresh++;                 // 统计还需感染的数量
                }
            }
        }

        // 2. 边界：没有新鲜橘子，不需要任何时间
        if (fresh == 0) return 0;

        // 四个扩散方向：右、下、左、上
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // 3. 多源 BFS：逐层扩散
        int minute = -1;                      // 初始 -1，第 0 层处理完后变为 0
        while (!q.empty()) {
            int size = q.size();              // 关键：记录本层元素个数，区分层级
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    // 越界检查
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    // 只感染新鲜橘子
                    if (grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;     // 感染（原地修改，省空间）
                        fresh--;
                        q.push({nx, ny});     // 新烂的橘子进入下一层
                    }
                }
            }
            minute++;                         // 当前层处理完毕，时间 +1
        }

        // 4. 仍剩新鲜橘子 → 不可能全部腐烂
        return fresh > 0 ? -1 : minute;
    }
};
