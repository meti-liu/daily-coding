#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

const int INF=1E9;
int dist[105][105];
int main()
{
    ifstream ifs("in.txt");
    int n,m;
    ifs>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(i==j) dist[i][j]=0;
        else dist[i][j]=INF;
    }
    


    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        ifs>>a>>b>>c;
        dist[a][b]=c;
        dist[b][a]=c;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }

    int mincost=INF;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(i!=j&&j!=k&&i!=k&&dist[i][j]!=INF&&dist[j][k]!=INF&&dist[k][i]!=INF)
        mincost=min(mincost,dist[i][j]+dist[j][k]+dist[k][i]);
    }

    if(mincost==INF) cout<<"It's impossible.";
    else cout<<mincost<<endl;

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<dist[i][j];
    //     }
    //     cout<<endl;
    // }

}

