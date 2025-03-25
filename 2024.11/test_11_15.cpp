#include <iostream>
#include <climits>
using namespace std;

const int INF = 7000;

int e[105][105]; // 邻接矩阵
int dist[105];    // 存储从起点到各个结点的最短距离
int s[105];       // 标记结点是否已经访问过

int main() {
    int n, k;
    cin >> n >> k;

    // 初始化邻接矩阵和dist数组
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = INF; // 先把所有的边都初始化为无穷大
        }
        dist[i] = INF;  // 初始化所有结点的距离为无穷大
        s[i] = 0;       // 初始化所有结点为未处理
    }

    // 输入边的信息，直到文件结束（直到没有更多的输入）
    int u, v, w;
    while (cin >> u >> v >> w) {
        e[u][v] = w; // 给邻接矩阵填充边的信息
    }

    // 初始化dist数组：从起始结点k到所有结点的初始距离
    for (int i = 1; i <= n; i++) {
        dist[i] = e[k][i];  // dist[k] 到 dist[i]的初始值等于边的权值
    }

    dist[k] = 0; // 起始结点的距离为0
    s[k] = 1;    // 起始结点已被处理

    // Dijkstra 算法
    for (int i = 1; i <= n - 1; i++) {
        int u = -1;
        int minDist = INF;

        // 找到当前未处理的结点中最小的dist值
        for (int j = 1; j <= n; j++) {
            if (s[j] == 0 && dist[j] < minDist) {
                minDist = dist[j];
                u = j; // 记录最小dist的结点
            }
        }

        // 如果找不到符合条件的结点，退出循环
        if (u == -1) break;

        s[u] = 1; // 将找到的结点标记为已处理

        // 更新dist数组
        for (int v = 1; v <= n; v++) {
            if (s[v] == 0 && e[u][v] != INF && dist[u] + e[u][v] < dist[v]) {
                dist[v] = dist[u] + e[u][v];
            }
        }
    }

    // 打印 dist 数组
    cout << "dist array: ";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    // 计算最大传递时间
    int maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1 << endl; // 如果有结点无法到达，返回 -1
            return 0;
        }
        maxDist = max(maxDist, dist[i]); // 找到最大最短距离
    }

    cout << maxDist << endl; // 输出最大时间
    return 0;
}
