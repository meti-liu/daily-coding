#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
const int INF=7000;
int e[105][105];
int dist[105];
int s[105];
//path
int main()
{
    ifstream ifs("in.txt");
    int n,k;
    ifs>>n>>k;
    int max=0;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        dist[i]=INF;
        e[i][j]=INF;
        s[i]=0;
        //path
    } 


    int u,v,w;
    while(ifs>>u>>v>>w) e[u][v]=w;



    for(int i=1;i<=n;i++) dist[i]=e[k][i];//无论是不是INF都一样



    dist[k]=0;
    s[k]=1;



    for(int i=1;i<=n-1;i++)//n-1轮操作中不再出现i
    {
        int u=-1;
        int min=INF;
        for(int j=1;j<=n;j++)
        {
            if(s[j]==0&&dist[j]<min)//找最小dist
            {
                min=dist[j];
                u=j;
            } 
        }

        if (u == -1) break;


        s[u]=1;


        for(int j=1;j<=n;j++)
        {
            if(s[j]==0&&e[u][j]!=INF)
            {
                if(dist[u]+e[u][j]<dist[j]) dist[j]=e[u][j]+dist[u];
                //path
            }
        }


    }


    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INF)
        {
            cout<<-1;
            return 0;
        }
        if(dist[i]>max) max=dist[i];
    }

    cout<<max;

    return 0;
}