#include<iostream>
using namespace std;
const int Max=100;
const int INF=1e8;


struct MGraph
{
    int edges[Max][Max];
    int n,e;
};


//Prim小结，一个初始化，然后一个大的for套两个小的for，其中一个用于寻找最小边并加入
//另一个用于更新lowcost数组
void Prim(MGraph g,int v0,int &sum)//自定义图，起始点v0，最小边和
{
    int lowcost[Max],vset[Max];
    int v=v0;//v为当前节点

    for(int i=0;i<g.n;i++)//初始化
    {
        lowcost[i]=g.edges[v0][i];
        vset[i]=0;
    }
    vset[v]=1;sum=0;

    for(int i=0;i<g.n-1;i++)//n-1轮更新，加入n-1个节点进入closet
    {//j为vset外部的点
        int min=INF;
        int k=-1;//临时记录
        for(int j=0;j<g.n;j++)
        {
            if(vset[j]==0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
        }
        vset[k]=1;
        v=k;//指向当前节点
        sum+=min;


        for(int j=0;j<g.n;j++)//更新lowcost
        {
            if(vset[j]==0&&g.edges[v][j]<lowcost[j])
            {
                lowcost[j]=g.edges[v][j];
            }
        }

    }

}
int main()
{

}