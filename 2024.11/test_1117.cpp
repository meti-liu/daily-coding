#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
const int INF=10000;
int e[105][105];
int dist[105];
int s[105];
int line[105];
int Max[105];

void debugPrint(int dist[], int n, int Max[]) {
    // 输出调试信息，查看每次Dijkstra迭代后的dist[]和Max[]
    cout << "dist[]: ";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;

    cout << "Max[]: ";
    for (int i = 1; i <= n; i++) {
        if (Max[i] == INF) cout << "INF ";
        else cout << Max[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, t; // 以t作为起点, 因此本算法时间复杂度为O(n³)
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        t = i;
        Max[t] = 0;

        // 初始化dist、e、s
        for (int j = 1; j <= n; j++) {
            dist[j] = INF;  // 默认所有的距离为INF
            s[j] = 0;       // 标记节点是否已被访问
            for (int k = 1; k <= n; k++) {
                e[j][k] = INF; // 初始化邻接矩阵为INF
            }
        }

        // 输入图的边
        for (int j = 1; j <= n; j++) { 
            int num;
            cin >> num;
            if (num == 0) continue;  // 如果没有边，直接跳过
            
            for (int p = 1; p <= 2 * num; p++) cin >> line[p];
            for (int p = 1; p <= num; p++) {
                e[j][line[2 * p - 1]] = line[2 * p];  // 构建邻接矩阵
            }
        }

        // Dijkstra初始化
        dist[t] = 0;
        s[t] = 1;

        // 计算最短路径
        for (int j = 1; j <= n - 1; j++) { // 进行n-1轮更新操作
            int u = -1;
            int min = INF;

            for (int k = 1; k <= n; k++) {
                if (s[k] == 0 && dist[k] != INF) {
                    if (dist[k] < min) {
                        min = dist[k];
                        u = k;
                    }
                }
            }
            if (u == -1) break; // 如果没有找到可更新的节点，跳出

            // 标记u为已访问
            s[u] = 1;

            // 更新dist
            for (int k = 1; k <= n; k++) {
                if (s[k] == 0 && e[u][k] != INF) {
                    if (dist[k] > dist[u] + e[u][k]) {
                        dist[k] = dist[u] + e[u][k];
                    }
                }
            }
        }

        // 更新Max数组
        for (int j = 1; j <= n; j++) {
            if (dist[j] == INF) {
                Max[t] = INF;
                break;
            }
            if (dist[j] > Max[t]) Max[t] = dist[j];
        }

        // 调试输出
        debugPrint(dist, n, Max);
    }

    // 查找Max数组中的最小值
    int minMax = INF;
    int Index = -1;
    for (int i = 1; i <= n; i++) {
        if (Max[i] < minMax) {
            minMax = Max[i];
            Index = i;
        }
    }

    // 输出结果
    if (minMax == INF) {
        cout << "disjoint";
    } else {
        cout << Index << " " << minMax;
    }

    return 0;
}
