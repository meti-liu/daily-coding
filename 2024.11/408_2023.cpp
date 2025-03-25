#include<iostream>
#include<string>
using namespace std;
const int MAXV=100;
struct MGraph
{
    int numV,numE;
    char Verticles[MAXV];
    int edge[MAXV][MAXV];

    MGraph(string v,string e)
    {
        numV=0;
        numE=0;
        int i=0;
        while(i<v.length())
        {
            if(v[i]<='z'&&v[i]>='a')
            {
                Verticles[numV]=v[i];
                numV++;
            } 
            i++;
        }

        for(int i=0;i<numV;i++)
        for(int j=0;j<numV;j++) edge[i][j]=0;

        i=0;
        char u,w;
        while(i<e.length())
        {
            if(e[i]=='(')
            {
                u=e[i+1];
                w=e[i+3];

                edge[this->Index(u)][this->Index(w)]=1;
                numE++;
            }
            i++;
        }
        

    }


    int Index(char find)
    {
        for(int i=0;i<numV;i++)
        {
            if(find==Verticles[i]) return i;
        }
        return -1;
    }
};

int PrintV(MGraph G)
{
    int cnt=0;
    int out[MAXV],in[MAXV];
    for(int i=0;i<G.numV;i++) out[i]=in[i]=0;

    for(int i=0;i<G.numV;i++)
    for(int j=0;j<G.numV;j++)
    if(G.edge[i][j]==1)
    {
        out[i]++;
        in[j]++;
    }

    // for(int i=0;i<G.numV;i++) cout<<G.Verticles[i]<<" "<<G.Index(G.Verticles[i])<<endl;
    // for(int i=0;i<G.numV;i++) cout<<out[i]<<" "<<in[i]<<endl;


    cout<<"K vertices:";

    for(int i=0;i<G.numV;i++)
    {
        if(out[i]>in[i])
        {
            cnt++;
            cout<<G.Verticles[i]<<" ";
        } 
    }
    cout<<endl<<"Number of K vertices:"<<cnt;
    return cnt;
}

int main()
{
    string v,e;
    cin>>v>>e;
    MGraph G(v,e);
    PrintV(G);
    return 0;
}
