#include <iostream>
#include <string>
using namespace std;

const int INF = 1e8;
const int Max = 100;

void Dijkstra(int graph[Max][Max], int n, int v0, int dist[Max]) {
    int S[Max] = {0}; // 是否已访问
    for (int i = 0; i < n; i++) {
        dist[i] = graph[v0][i];
    }
    S[v0] = 1;

    for (int i = 0; i < n - 1; i++) {
        int minD = INF, u = -1;
        for (int j = 0; j < n; j++) {
            if (!S[j] && dist[j] < minD) {
                minD = dist[j];
                u = j;
            }
        }
        if (u == -1) break; // 无法找到新的最短路径
        S[u] = 1;

        for (int j = 0; j < n; j++) {
            if (!S[j] && graph[u][j] != INF && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
}

int main() {
    int n, v0;
    cin >> n >> v0;

    int graph[Max][Max];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string value;
            cin >> value;
            if (value == "INF") graph[i][j] = INF;
            else graph[i][j] = stoi(value);
        }
    }

    int dist[Max];
    Dijkstra(graph, n, v0, dist);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
