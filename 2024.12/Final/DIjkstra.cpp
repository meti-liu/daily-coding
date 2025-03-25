#include<iostream>
#include<algorithm>
using namespace std;
const int Max=100;
const int INF=1e8;


struct MGraph
{
    int edges[Max][Max];
    int n,e;
};

void Dijkstra(MGraph g,int v0,int dist[],int path[],int set[])
{
    int min,i,j,u;

    for(int i=0;i<g.n;i++)//step1初始化
    {
        dist[i]=g.edges[v0][i];
        set[i]=0;
        if(g.edges[v0][i]<INF) path[i]=v0;
        else path[i]=-1;
    }

    set[v0]=1; path[v0]=-1;

    for(int i=0;i<g.n-1;i++)//加入剩下n-1个点进set
    {
        min=INF;
        u=-1;
        for(int j=0;j<g.n;j++)//一轮j循环加一个点
        {
            if(set[j]==0&&dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
            set[u]=1;
        }

        for(int j=0;j<g.n;j++)//每加入一个节点u后更新dist和path
        {
            if(set[j]==0&&g.edges[u][j]+dist[u]<dist[j])
            {
                dist[j]=dist[u]+g.edges[u][j];
                path[j]=u;
            }
        }
    }
}