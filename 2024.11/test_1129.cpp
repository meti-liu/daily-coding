#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1E9;
int dist[105][105];

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化邻接矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;  // 自己到自己的距离是0
            else dist[i][j] = INF;        // 其他初始化为INF
        }
    }

    // 读入边的信息，更新邻接矩阵
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);  // 如果有多条边，取最小的花费
        dist[b][a] = min(dist[b][a], c);  // 无向图
    }

    // 使用 Floyd-Warshall 算法计算最短路径
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 查找最小的回路，回路可以包含任意长度，只要至少经过3个景区
    int mincost = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i != j && j != k && i != k && dist[i][j] != INF && dist[j][k] != INF && dist[k][i] != INF) {
                    mincost = min(mincost, dist[i][j] + dist[j][k] + dist[k][i]);
                }
            }
        }
    }

    // 输出结果
    if (mincost == INF) {
        cout << "It's impossible." << endl;
    } else {
        cout << mincost << endl;
    }

    return 0;
}


