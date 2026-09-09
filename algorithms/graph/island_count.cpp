/* C++ | graph: island count. */
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int l){
        if(r<0||l<0||r>=grid.size()||l>=grid[0].size()||grid[r][l]=='0'){
            return ;
        }
        grid[r][l]  = '0';
        dfs(grid,r+1,l);
        dfs(grid,r,l+1);
        dfs(grid,r-1,l);
        dfs(grid,r,l-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1'){
                    count ++;//发现新岛屿
                    dfs(grid,i,j); //淹没整个岛屿
                }
                
            }
        }
        return count;
    }
};

/*
================================================================================
                    DFS 解岛屿数量 —— 思想总结
================================================================================

一、核心思想：把网格当作"隐式图"
─────────────────────────────
  不需要建邻接表。网格中每个格子就是一个"节点"，每个格子与上下左右
  四个邻居之间存在边。遍历网格 = 遍历图。

二、DFS 在这里做了什么？
─────────────────────────────
  可以把 DFS 理解成"洪水淹没"：每发现一块陆地，就顺着它把所有相连
  的陆地全部标记成已访问（这里直接改成 '0'），这样同一座岛屿的每一
  块陆地都被一次性处理掉。主循环继续遍历时就不会重复计数。

  具体步骤：
  1. 主循环发现一块 '1'（新岛屿），count++。
  2. 立即调用 DFS，从该格子出发：
     a. 先检查边界 + 是否为水 → 是就 return（递归终止）。
     b. 把当前格子沉没为 '0'（关键！防止死循环和重复计数）。
     c. 向上下左右四个方向递归搜索。
  3. DFS 返回后，整座岛屿已变成 '0'，回到主循环继续扫描。

三、DFS 的 3 个关键点
─────────────────────────────
  ① 终止条件：先判越界，再判是否为水。顺序不能反。
  ② 标记已访问：进入一个格子后立刻置 '0'，否则邻居会搜回来形成死循环。
  ③ 四个方向：上下左右递归。不需要再往上/下/左/右之外的方向。

四、复杂度
─────────────────────────────
  时间：O(m×n) — 每个格子最多被访问一次（DFS 里被淹没，主循环跳过）。
  空间：O(m×n) — 最坏情况整个网格全是陆地，递归栈深度 = m×n。
        可通过 BFS 或迭代 DFS 降低栈深度风险。
        
五、DFS 通用模板（背下来）
─────────────────────────────
  void dfs(参数...){
      if(越界 || 已访问 || 不符合条件) return;
      标记已访问;
      for(每个邻居){
          dfs(邻居);
      }
  }

  其中第一步"标记已访问"必须在递归前执行，不能等递归回来再标记。
================================================================================
*/


// BFS
class SolutionBFS {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1'){
                    count ++;//发现新岛屿
                    grid[i][j] = '0';              // 修复: 0 → '0'
                    q.push({i,j});
                    while(!q.empty()){
                        auto rc = q.front();        // 修复: pair → auto
                        q.pop();
                        int r  = rc.first;
                        int c  = rc.second;
                        //向上看                          // 修复: 方向注释
                        if(r-1>=0&&grid[r-1][c]=='1'){
                            q.push({r-1,c});
                            grid[r-1][c] = '0';
                        }
                        //向下看                          // 修复: 方向注释
                        if(r+1<n&&grid[r+1][c]=='1'){
                            q.push({r+1,c});
                            grid[r+1][c] = '0';
                        }
                        //向左看
                        if(c-1>=0&&grid[r][c-1]=='1'){  // 修复: = → ==
                            q.push({r,c-1});
                            grid[r][c-1] = '0';
                        }
                        //向右看
                        if(c+1<m&&grid[r][c+1]=='1'){
                            q.push({r,c+1});
                            grid[r][c+1] = '0';
                        }

                    }
                }
            }
        }
        return count;
    }
};

/*
================================================================================
                    BFS 解岛屿数量 —— 思想总结
================================================================================

一、BFS vs DFS 的本质区别
─────────────────────────────
  DFS：用递归（系统栈）深入到底再回溯  →  一条路走到黑
  BFS：用队列（自己管理）一层层往外扩  →  水波纹扩散
  两种算法的"淹没"效果完全一样，差别只在于遍历顺序。

二、BFS 在这里做了什么？
─────────────────────────────
  1. 主循环发现 '1' → count++，标记为 '0'，将该坐标入队。
  2. while 队列非空：
     a. 弹出队首元素 (r, c)。
     b. 检查上下左右四个邻居：没越界 && 是 '1' → 标记为 '0'，入队。
     c. 循环直到队列为空（整座岛屿淹没完毕）。
  3. 回到主循环继续扫描下一个格子。

三、BFS 的 3 个关键易错点（你踩过的坑）
─────────────────────────────
  ① 入队前就要标记为 '0'，不能 pop 后再标。
     否则同一个格子可能被多次入队，导致重复处理。

  ② pair 模板参数必须写全：pair<int,int>，或直接用 auto。

  ③ 四方向判断：= 是赋值，== 才是比较！

四、复杂度
─────────────────────────────
  时间：O(m×n) — 每个格子最多入队一次。
  空间：O(m×n) — 最坏队列存一整层。但没有递归爆栈风险。

五、BFS 通用模板（背下来）
─────────────────────────────
  queue<类型> q;
  标记起点;
  q.push(起点);
  while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (每个邻居) {
          if (没越界 && 没访问过 && 满足条件) {
              标记已访问;        // 入队前就标！
              q.push(邻居);
          }
      }
  }

六、什么时候用 BFS 而不是 DFS？
─────────────────────────────
  - 网格巨大、形状呈长条状 → DFS 可能爆栈，BFS 更安全。
  - 求最短路径 / 最少步数 → BFS 天然支持（层数 = 距离）。
  - 只是遍历连通分量 → DFS 代码更短，一般优先用 DFS。
================================================================================
*/

//并查集 关键做法 路径压缩
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    // 【知识点：各自为王（初始化）】
                    // 一开始，每个陆地格子都是一个独立的岛屿，每个人都是自己的终极老大。
                    // 此时世界上没有“小弟”，全都是“光杆司令”。
                    parent.push_back(i * n + j);
                    ++count; // 初始记录一共有 count 个独立的小岛（帮派）
                }
                else {
                    parent.push_back(-1); // 水域不参与帮派斗争
                }
                // 【知识点：初始化树高（rank）】
                // 因为大家都是光杆司令，底下没有小弟，所以帮派层级（树高）统统为 0
                rank.push_back(0);
            }
        }
    }

    // 【疑问解答：find函数到底在干什么？】
    // 目的只有一个：顺藤摸瓜，查出节点 i 的“终极老大”到底是谁。
    int find(int i) {
        if (parent[i] != i) { // 如果我的直接老大不是我自己，说明我上面还有人
            // 【知识点：路径压缩】
            // 在去问“老大的老大”是谁的同时，直接把自己的老大改成那个“终极老大”。
            // 下次再查，就不用一层层往上问了，一步到位！
            parent[i] = find(parent[i]);
        }
        return parent[i]; // 返回终极老大
    }

    // 【疑问解答：unite函数的逻辑是什么？】
    void unite(int x, int y) {
        int rootx = find(x); // 找出 x 的终极老大
        int rooty = find(y); // 找出 y 的终极老大
        
        // 【疑问解答：为什么是老大不同才合并？】
        // 如果 rootx == rooty，说明两人早就拜在同一个老大门下，已经是同一个岛屿了，不需要操作。
        // 只有老大不同，才说明这是两个之前没发现连在一起的不同岛屿，现在必须合并！
        if (rootx != rooty) { 
            
            // 【疑问解答：rank的作用是什么？】
            // rank 代表树的高度。为了防止找老大时层级太深（退化成链表），
            // 我们必须让“矮树（等级低的帮派）”挂到“高树（等级高的帮派）”下面。
            // 这里比较 rank，如果 x 的帮派比较矮，就把 x 和 y 互换，确保 rootx 始终是高的那个！
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            
            // 【疑问解答：小弟是怎么诞生的？】
            // 致命一句：让 rooty（小帮派的老大）认 rootx（大帮派的老大）作父。
            // 就在这一刻，rooty 被降级成了“小弟”，他手下的人也都跟着归顺了 rootx。
            parent[rooty] = rootx;
            
            // 只有当两个帮派原本一样高时，大帮派吞并小帮派后，总层级才会被迫增加 1 层。
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            
            // 两个不同的帮派合并成了一个大帮派，所以世界上的总岛屿数量减少 1 个！
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent; // 记录每个人的直接老大是谁
    vector<int> rank;   // 记录以当前节点为老大的帮派，层级有多深（树高）
    int count;          // 记录当前世界上的总帮派（独立岛屿）数量
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid); // 启动并查集引擎，所有陆地各自为王
        int num_islands = 0; // （注：原代码这里定义了但没用到，实际返回的是 uf.getCount()）
        
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0'; // 走过的陆地标记为 '0'，防止后续重复判断
                    
                    // 只要发现上下左右相邻的也是陆地（'1'），就立刻呼叫并查集把它们所在的帮派合并！
                    // 把二维坐标 (r, c) 转换为一维索引：r * nc + c
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        // 遍历完毕，所有挨着的陆地都完成了认亲合并，剩下的就是真正的岛屿总数
        return uf.getCount();
    }
};