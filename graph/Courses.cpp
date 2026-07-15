#include <vector>
#include <queue>
using namespace std;

// 检测有向图是否有环 = 拓扑排序能覆盖所有节点则无环
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 建邻接表 + 统计入度
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto &p : prerequisites) {
            int to = p[0];
            int from = p[1];
            adj[from].push_back(to);   // 边 from -> to
            indegree[to]++;            // to 的入度+1
        }

        // 所有入度为0的课入队（无前置依赖，可以直接上）
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS：每上一门课，将它后继节点的入度减1，减到0即可入队
        int taken = 0;   // 已完成的课程数
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            taken++;
            //遍历cur的后继 并且给后继入度减一
            for (int to : adj[cur]) {
                indegree[to]--;
                if (indegree[to] == 0) {
                    q.push(to);
                }
            }
        }

        // 能上完所有课则无环
        return taken == numCourses;
    }
};


// ========== DFS 三色标记法 ==========
// 与BFS的核心区别：DFS通过"是否撞见当前路径上的祖先"来判断环
// BFS是"一层层剥掉入度为0的节点"，DFS是"一条路走到底再回溯"

#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 建邻接表（和BFS一样）
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);   // 边 from -> to
        }

        // 三色：0=未访问  1=访问中（在递归栈里）  2=已完成（所有后继都检查过，安全）
        vector<int> state(numCourses, 0);

        // 图可能不连通，要对每个未访问节点分别启动DFS
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) {
                    return false;   // 任意一个连通分量有环，直接失败
                }
            }
        }
        return true;
    }

    // 返回值：true=发现环  false=从cur出发所有路径安全
    // ⚠️ 易错点1：返回true才是有环，别搞反了
    bool hasCycle(int cur, vector<vector<int>>& adj, vector<int>& state) {
        state[cur] = 1;   // 标记"访问中"——当前节点进入递归栈

        for (int to : adj[cur]) {
            if (state[to] == 1) {
                // 后继节点是"访问中"=它是当前路径上的祖先 → 成环
                // ⚠️ 易错点2：这里返回true不是false
                return true;
            }
            else if (state[to] == 2) {
                // "已完成"的节点已经确认过无环，直接跳过，避免重复搜索
                continue;
            }
            else {
                // state[to]==0，未访问，递归深入
                // ⚠️ 易错点3：必须用to递归，别写成cur（会无限递归）
                // ⚠️ 易错点4：只有发现环才return，没环就continue检查下一个后继
                if (hasCycle(to, adj, state)) {
                    return true;
                }
            }
        }

        state[cur] = 2;   // 回溯：所有后继都检查完且无环，标记"已完成"
        return false;      // 从cur出发无环
    }
};
