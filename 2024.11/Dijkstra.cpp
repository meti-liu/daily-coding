#include<iostream>
using namespace std;
void Dijikstra(MatGraph& G,int v)
{
    int dist[MAXV];
    int path[MAXV];//前驱，用于回溯
    int S[MAXV];//最短集合
    for(int i=0;i<G.n;i++)//初始化
    {
        dist[i]=G.edges[v][i];
        S[i]=0;
        if(G.edges[v][i]!=0&&G.edges[v][i]<INF) path[i]=v;//i到v有边
        else path[i]=-1;//i到v没边
    }
    S[v]=1;//加入原点
    int minD,u=-1;
    for(int i=0;i<G.n-1;i++)//更新n-1轮
    {
        minD=INF;
        for(int j=0;j<G.n;j++)//找dist中谁最小
        {
            if(S[j]==0&&dist[j]<minD)
            {
                minD=dist[j];
                u=j;//记录最小dist的index
            }      
        }
        S[u]=1;
        for(int j=0;j<G.n;j++)
        {
            if(S[j]==0)//该点未被处理
                if(G.edges[u][j]<INF&&dist[u]+G.edges[u][j]<dist[j])//相邻节点判断距离并更新
                {
                    dist[j]=dist[u]+G.edges[u][j];
                    path[j]=u;
                }
        }
    }
}
int main()
{

}