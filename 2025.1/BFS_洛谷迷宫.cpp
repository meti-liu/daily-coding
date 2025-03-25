#include<iostream>
#include<queue>
using namespace std;
const int Max=105;
int v[105][105]={0};
struct Node
{
    int x;
    int y;
    int n;
    Node(int x,int y,int n)
    {
        this->x=x;
        this->y=y;
        this->n=n;
    }
};

int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1};

int main()
{
    int n,m;
    cin>>n>>m;
    queue<Node> q;
    q.push(Node(1,1,0));
    while(!q.empty())
    {

        Node a=q.front();
        q.pop();

        if(a.x==m&&a.y==n)
        {
            cout<<a.n;
            return 0;
        }


        for(int i=0;i<4;i++)
        {
            int x=a.x+dx[i];
            int y=a.y+dy[i];
            if(v[x][y]==0&&x<=m&&x>=1&&y>=1&&y<=n)
            {
                q.push(Node(x,y,a.n+1));
                v[x][y]=1;
            }

        }
    }

    cout<<"No";
    return 0;
}