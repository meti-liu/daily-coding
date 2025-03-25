#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

const int INF = 7000; // 代表不可达的一个较大数值
int e[105][105];
int dist[105];
int s[105];

int main() {
    ifstream ifs("in.txt"); // 文件输入流，确保你提供了正确的输入文件
    int n, k;
    cin >> n >> k;

    // 初始化
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = INF; // 默认是不可达
        }
        dist[i] = INF; // 先将dist初始化为INF
        s[i] = 0; // 未访问
    }

    // 输入边的信息
    int u, v, w;
    while (cin >> u >> v >> w) {
        e[u][v] = w; // 存储图的边和权重
    }

    // 设置源结点的dist
    dist[k] = 0; // 源结点到源结点的距离为0
    s[k] = 1; // 源结点已经加入最短路径集合

    // 初始化dist数组，从源结点k出发，直接更新dist数组
    for (int i = 1; i <= n; i++) {
        if (e[k][i] != INF) {
            dist[i] = e[k][i]; // 源结点到直接相邻结点的距离
        }
    }

    // Dijkstra 算法
    for (int i = 1; i <= n - 1; i++) {
        int u = -1;
        int minDist = INF;

        // 选择最小的未加入S集合的dist
        for (int j = 1; j <= n; j++) {
            if (s[j] == 0 && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        // 如果没有找到未加入的节点，说明所有节点都已经被处理过了，提前退出
        if (u == -1) break;

        // 将u加入S集合
        s[u] = 1;

        // 更新dist数组
        for (int j = 1; j <= n; j++) {
            // 只有在s[j] == 0（j未处理）且有边存在时（e[u][j] != INF），才进行更新
            if (s[j] == 0 && e[u][j] != INF) {
                if (dist[u] + e[u][j] < dist[j]) {
                    dist[j] = dist[u] + e[u][j];
                }
            }
        }
    }

    // 检查是否有结点不可达，若有则输出-1
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1 << endl;
            return 0; // 如果存在不可达的结点，直接返回
        }
    }

    // 计算最大的时间
    int maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
        }
    }

    cout << maxDist << endl; // 输出最大的传递时间

    return 0;
}
