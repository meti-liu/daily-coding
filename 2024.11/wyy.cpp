#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<sstream>
#include<fstream>
using namespace std;

const int MAXV = 100;
const int INF = 0x3f3f3f3f;

class MatGraph {
public:
    int edges[MAXV][MAXV];
    int n, e;
    string vexs[MAXV];
    
    void CreateMatGraph(int a[][MAXV], int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                this->edges[i][j] = a[i][j];
            }
        }
    }
};

int Dijkstra(MatGraph& g, int v) {
    int dist[MAXV];  // dist[i] stores the shortest distance from v to i
    int S[MAXV];     // S[i] is 1 if i is included in the shortest path tree, else 0
    int pathmax = -1;  // Initialize pathmax as -1 to represent unreachable nodes
    
    // Initialize dist and S
    for (int i = 0; i < g.n; i++) {
        dist[i] = INF;  // Initially set all distances to INF
        S[i] = 0;       // Initially no node is included in the shortest path tree
    }
    dist[v] = 0;  // The distance to the source node is 0
    S[v] = 1;     // Include the source node in the shortest path tree
    
    // Dijkstra algorithm
    for (int i = 0; i < g.n - 1; i++) {
        int mindis = INF;
        int u = -1;
        
        // Find the node with the smallest distance that is not yet in the shortest path tree
        for (int j = 0; j < g.n; j++) {
            if (S[j] == 0 && dist[j] < mindis) {
                u = j;
                mindis = dist[j];
            }
        }
        
        S[u] = 1;  // Mark node u as included in the shortest path tree
        
        // Update the distance for all nodes adjacent to u
        for (int j = 0; j < g.n; j++) {
            if (S[j] == 0 && g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j];
            }
        }
    }
    
    // Find the maximum distance among all nodes
    for (int k = 0; k < g.n; k++) {
        if (dist[k] == INF) {
            return -1;  // If any node is not reachable, return -1
        }
        pathmax = max(pathmax, dist[k]);
    }

    return pathmax;  // Return the longest time
}

int main() {
    MatGraph g;
    ifstream ifs("in.txt");
    int N, K;
    int a[MAXV][MAXV];
    
    // Initialize the adjacency matrix with INF and 0 on the diagonal
    for (int i = 0; i < MAXV; i++) {
        for (int j = 0; j < MAXV; j++) {
            if (i == j) {
                a[i][j] = 0;  // Distance from a node to itself is 0
            } else {
                a[i][j] = INF;  // Distance between different nodes is INF initially
            }
        }
    }
    
    // Read N (number of nodes) and K (starting node)
    ifs >> N >> K;
    
    // Read edges from the input file and populate the adjacency matrix
    for (int i = 0; i < N; i++) {
        int u, v, w;
        ifs >> u >> v >> w;
        a[u - 1][v - 1] = w;  // Adjust for 0-based indexing
    }
    
    // Create the graph with the adjacency matrix
    g.CreateMatGraph(a, N);
    
    // Compute and output the result
    cout << Dijkstra(g, K - 1) << endl;
    
    return 0;
}
