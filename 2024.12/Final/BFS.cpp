#include <iostream>
#include <queue>
using namespace std;

const int Max = 100;
const int INF = 1e8;

void BFS(int graph[Max][Max], int n, int v) {
    bool visited[Max] = {false};
    queue<int> q;

    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // 访问当前节点

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[u][i] != INF) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n = 5; // 节点数
    int graph[Max][Max] = {
        {0, 1, INF, 1, INF},
        {1, 0, 1, INF, INF},
        {INF, 1, 0, 1, 1},
        {1, INF, 1, 0, INF},
        {INF, INF, 1, INF, 0}
    };

    cout << "BFS Traversal: ";
    BFS(graph, n, 0); // 从节点 0 开始 BFS
    cout << endl;

    return 0;
}
