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

int v[Max];

struct Edge
{
    int u,v;
    int w;
};

Edge road[Max];

int getRoot(int n)
{
    while(n!=v[n]) n=v[n];//递归找root
    return n;
}

void Kruskal(MGraph g,int &sum,Edge road[])
{
    sum=0;
    for(int i=0;i<g.n;i++) v[i]=i;

    sort(road,road+g.e,[](const Edge &a,const Edge &b)
    {
        return a.w<b.w;
    });


    for(int i=0;i<g.e;i++)
    {
        int a=getRoot(road[i].u);
        int b=getRoot(road[i].v);
        if(a!=b)
        {
            v[a]=b;
            sum+=road[i].w;
        }
    }

}

int main() 
{
    MGraph g;
    g.n = 5; g.e = 7; // 5 个顶点，7 条边

    // 定义边
    Edge road[] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7},
        {3, 4, 9}
    };

    int sum = 0;
    Kruskal(g, sum, road);

    cout << "Minimum Spanning Tree Weight: " << sum << endl;

    return 0;
}