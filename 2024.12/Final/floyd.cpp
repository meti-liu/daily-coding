#include <iostream>
using namespace std;

const int Max = 100;
const int INF = 1e8;

void Floyd(int graph[Max][Max], int n) {
    int dist[Max][Max]; // 最短路径距离矩阵
    int path[Max][Max]; // 路径矩阵

    // 初始化 dist 和 path
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
            if (i != j && graph[i][j] < INF) path[i][j] = i; // 路径初始化
            else path[i][j] = -1;
        }
    }

    // Floyd 核心算法
    for (int k = 0; k < n; k++) { // 中间点
        for (int i = 0; i < n; i++) { // 起点
            for (int j = 0; j < n; j++) { // 终点
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // 更新最短路径
                    path[i][j] = path[k][j]; // 更新路径
                }
            }
        }
    }

    // 输出最短距离矩阵
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // 输出路径
    cout << "\nPaths:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Path from " << i << " to " << j << ": ";
            if (dist[i][j] == INF) cout << "No path";
            else {
                int current = j;
                cout << current;
                while (path[i][current] != -1) {
                    current = path[i][current];
                    cout << " <- " << current;
                }
            }
            cout << endl;
        }
    }
}

int main() {
    int n = 4; // 图的顶点数
    int graph[Max][Max] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    // 调用 Floyd 算法
    Floyd(graph, n);

    return 0;
}
