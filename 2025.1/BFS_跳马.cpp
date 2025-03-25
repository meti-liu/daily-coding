#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int x;
    int y;
    int n;
    Node(int x,int y,int n):x(x),y(y),n(n){}
};
int visited[15][15]={0};
int dx[8]={1,2,1,2,-2,-1,-2,-1};
int dy[8]={2,1,-2,-1,-1,2,1,-2};
int main()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    queue<Node> q;
    q.push(Node(x1,y1,0));

    while(!q.empty())
    {
        Node a=q.front();
        if(a.x==x2&&a.y==y2)
        {
            cout<<a.n;
            return 0;
        }
        q.pop();
        for(int i=0;i<=7;i++)
        {
            int x=a.x+dx[i];
            int y=a.y+dy[i];
            if(visited[x][y]==0&&x>=0&&y>=0)
            {
                q.push(Node(x,y,a.n+1));
                visited[x][y]=1;
            }
        }
    }
    cout<<"No";

    return 0;
}