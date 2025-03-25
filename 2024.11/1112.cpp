#include <iostream>
#include <fstream>
using namespace std;


const int INF = 1E9;
int data[105][105], dist[105][105];

int main() {
    ifstream ifs("in.txt");
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            data[i][j] = INF;
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < dist[a][b]) data[a][b] = data[b][a] = dist[a][b] = dist[b][a] = c;
        
    }

    int ans = INF;
    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i < k; i++) 
        {
            for (int j = i + 1; j < k; j++) 
            {
                ans = min(ans, dist[i][j] + data[i][k] + data[k][j]);
            }
        }
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    if (ans == INF) 
        cout << "It's impossible." << endl;
    else 
        cout << ans << endl;

    return 0;
}
