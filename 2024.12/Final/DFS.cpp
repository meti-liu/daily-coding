#include <iostream>
using namespace std;

const int Max = 100;
const int INF = 1e8;

void DFS(int graph[Max][Max], int n, int v, bool visited[Max]) {
    cout << v << " "; // 访问当前节点
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[v][i] != INF) {
            DFS(graph, n, i, visited); // 递归访问邻接点
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

    bool visited[Max] = {false}; // 初始化访问数组

    cout << "DFS Traversal: ";
    DFS(graph, n, 0, visited); // 从节点 0 开始 DFS
    cout << endl;

    return 0;
}
