#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Graham 扫描法（Graham-Scan Convex Hull Algorithm），用于求解一组二维点集的凸包（Convex Hull）。  
//  所谓凸包，你可以想象在平面上钉了一堆钉子（点集），拿一根橡皮筋把所有钉子从最外圈套住，橡皮筋形成的这个凸多边形边界，就是凸包。

struct Point {
    long long x, y;
};

// 向量 (p1->p2) 与向量 (p1->p3) 的叉乘
// 返回值 > 0: 向左拐 (逆时针)
// 返回值 < 0: 向右拐 (顺时针)
// 返回值 = 0: 三点共线
long long crossProduct(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

// 计算两点间距离的平方（用于共线时排序）
long long distSq(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// 凸包算法
vector<Point> grahamScan(vector<Point>& pts) {
    int n = pts.size();
    if (n <= 2) return pts;

    // 步骤 1: 寻找基准点（y 最小，y 相同则 x 最小）
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (pts[i].y < pts[minIdx].y || (pts[i].y == pts[minIdx].y && pts[i].x < pts[minIdx].x)) {
            minIdx = i;
        }
    }
    // 将基准点换到第 0 个位置
    swap(pts[0], pts[minIdx]);
    Point p0 = pts[0];

    // 步骤 2: 按相对于 p0 的极角逆时针排序
    sort(pts.begin() + 1, pts.end(), [&p0](const Point& a, const Point& b) {
        long long cp = crossProduct(p0, a, b);
        if (cp == 0) {
            // 极角相同时，距离近的排前面
            return distSq(p0, a) < distSq(p0, b);
        }
        return cp > 0; // 逆时针排在前面（叉乘 > 0）
    });

    // 步骤 3: 扫描维护凸包栈
    vector<Point> st;
    st.push_back(pts[0]);
    st.push_back(pts[1]);

    for (int i = 2; i < n; i++) {
        // 当栈中至少有两个点，且 新边 不是向左拐时，弹出栈顶
        while (st.size() >= 2) {
            Point p_top = st.back();            // 栈顶 S[k]
            Point p_second = st[st.size() - 2];  // 次栈顶 S[k-1]

            // 判断向量 p_second -> p_top 与 p_second -> pts[i] 的转向关系
            if (crossProduct(p_second, p_top, pts[i]) > 0) {
                break; // 满足左拐，停止出栈
            }
            st.pop_back(); // 向右拐或共线，栈顶点凹进去了，退栈！
        }
        // 当前点入栈
        st.push_back(pts[i]);
    }

    return st; // 返回凸包上的所有顶点
}