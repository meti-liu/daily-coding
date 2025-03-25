#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

const int INF = 10000;
int e[105][105]; // 邻接矩阵
int dist[105];    // 从当前节点到其他节点的最短距离
int s[105];       // 是否已处理过的标记
int line[105];    // 存储输入的边信息
int Max[105];     // 存储每个节点作为起点的最大传播时间

// 输出调试信息，查看每次Dijkstra迭代后的dist[]和Max[]
void debugPrint(int dist[], int n, int Max[]) {
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
    int n; // 股票经纪人数量    
    //ifstream ifs("in.txt");
    cin >> n;

    
    // 初始化邻接矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = INF; // 没有路径时距离为INF
        }
        Max[i] = 0; // 初始最大传播时间设置为INF
    }

    // 读取图的信息
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int p = 1; p <= 2 * num; p++) {
            cin >> line[p];
        }
        for (int p = 1; p <= num; p++) {
            e[i][line[2 * p - 1]] = line[2 * p];
        }
    }

    // 对每个节点作为起点，执行Dijkstra算法
    for (int t = 1; t <= n; t++) 
    {
        // 初始化dist数组，dist[j]为从t到j的距离
        for (int i = 1; i <= n; i++) 
        {
            dist[i] = e[t][i];  // 初始化为起点t到其他节点的距离
            s[i] = 0;           // 标记所有节点为未处理
        }

        dist[t] = 0;  // 起点到自己的距离为0
        s[t] = 1;     // 标记起点已处理

        // 执行Dijkstra算法
        for (int j = 1; j <= n - 1; j++) 
        {
            int u = -1;
            int minDist = INF;

            // 找到未处理的节点中，距离起点最近的一个
            for (int k = 1; k <= n; k++) 
            {
                if (s[k] == 0 && dist[k] < minDist) {
                    minDist = dist[k];
                    u = k;
                }
            }

            if (u == -1) break; // 如果没有未处理的节点，结束

            s[u] = 1; // 标记为已处理

            // 更新距离
            for (int k = 1; k <= n; k++) {
                if (s[k] == 0 && e[u][k] != INF) {
                    if (dist[k] > dist[u] + e[u][k]) {
                        dist[k] = dist[u] + e[u][k];
                    }
                }
            }
        }

        // 计算最远传递时间（最大传播时间）
        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) {
                maxDist = INF; // 存在不可达节点
                break;
            }
            if (dist[i] > maxDist) {
                maxDist = dist[i];
            }
        }
        Max[t] = maxDist;

        debugPrint(dist, n, Max);  // 输出调试信息
    }

    // 找到最小的最大传播时间
    int minMax = INF;
    int bestNode = -1;
    for (int i = 1; i <= n; i++) {
        if (Max[i] < minMax) {
            minMax = Max[i];
            bestNode = i;
        }
    }

    // 输出结果
    if (minMax == INF) {
        cout << "disjoint" << endl;
    } else {
        cout << bestNode << " " << minMax << endl;
    }

    return 0;
}
