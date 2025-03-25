#include<iostream>
#include<cmath>
using namespace std;
bool d[105][105];
void fun_m(bool d[105][105],int x,int y,int n)
{
    for(int i=x-2;i<=x+2;i++)
    for(int j=y-2;j<=y+2;j++)
    {
        if(i<0||j<0||i>=n||j>=n) continue;
        if((abs(i-x)+abs(j-y))<=2) d[i][j]=1;
    }
}

void fun_k(bool d[105][105],int x,int y,int n)
{
    for(int i=x-2;i<=x+2;i++)
    for(int j=y-2;j<=y+2;j++)
    {
        if(i<0||j<0||i>=n||j>=n) continue;
        else d[i][j]=1;
    }
}
int main()
{
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        d[i][j]=0;
    }
    for(int i=0;i<m;i++)
    {
        int mx,my;
        cin>>mx>>my;
        fun_m(d,mx-1,my-1,n);
    }
    for(int i=0;i<k;i++)
    {
        int kx,ky;
        cin>>kx>>ky;
        fun_k(d,kx-1,ky-1,n);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(d[i][j]==0) ans++;
        }

    }

    cout<<ans;
    return 0;
}