#include <iostream>
#include <fstream>
using namespace std;

const int MAXV = 1001;
const int INF = 0x3f3f3f3f;
int A[MAXV][MAXV], dis[MAXV][MAXV];

int main() {
    ifstream ifs("in.txt");
    int n, m;
    ifs >> n >> m;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            A[i][j] = INF;
            dis[i][j] = INF;
        }
    }
    for (int t = 0; t < m; t++) {
        int a, b, c;
        ifs >> a >> b >> c;
        if (c < dis[a][b]) {
            A[a][b] = A[b][a] = dis[a][b] = dis[b][a] = c;
        }
    }
    int ans = INF;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                ans = min(ans, dis[i][j] + A[i][k] + A[k][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    if (ans == INF)
        cout << "It's impossible." << endl;
    else
        cout << ans << endl;
    return 0;
}