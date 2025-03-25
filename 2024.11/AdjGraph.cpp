#include<iostream>
using namespace std;
const int MAXV=1000;
struct ArcNode
{
    int adjvex;
    int weight;
    ArcNode* nextarc;
};
struct HNode
{
    string info;
    ArcNode* firstarc;
};

class AdjGragh
{
public:
    HNode adjlist[MAXV];
    int n,e;
    AdjGragh()
    {
        for(int i=0;i<MAXV;i++)
        {
            adjlist->firstarc=nullptr;
        }
    }
    void CreateAdjGragh(int a[][MAXV],int n,int e)
    {
        ArcNode* p;
        this->n=n;
        this->e=e;
        for(int i=0;i<n;i++)
        for(int j=n-1;j>=0;j--)//????
            if(a[i][j]!=0&&a[i][j]!=INF)
            {
                p=new ArcNode();
                p->adjvex=j;
                p->weight=a[i][j];
                p->nextarc=adjlist[i].firstarc;
                adjlist[i].firstarc=p;
            }
    }
}



int main()
{

}