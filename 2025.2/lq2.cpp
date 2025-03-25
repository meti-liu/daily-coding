#include<iostream>
#include<queue>
using namespace std;
int a[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool visited[100][100]={false};
struct Point
{
    int x,y,w;

    Point(int x,int y,int w)
    {
        this->x=x;
        this->y=y;
        this->w=w;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++) cin>>a[i][j];
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    visited[x1][y1]=true;
    queue<Point> q;
    q.push(Point(x1,y1,0));

    while(!q.empty())
    {

        Point cur=q.front();
        q.pop();

        if(cur.x==x2&&cur.y==y2)
        {
            cout<<cur.w;
            return 0;
        }

        for(int j=0;j<4;j++)
        {
            int x=cur.x+dx[j];
            int y=cur.y+dy[j];
            if(x<=n&&x>0&&y<=m&&y>0&&visited[x][y]==false)
            {
                if(a[x][y]==1) q.push(Point(x,y,cur.w+1));
                visited[x][y]=true;
            }
            
        }
    }


    cout<<-1;
    return 0;

}