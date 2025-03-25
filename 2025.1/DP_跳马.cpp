#include<iostream>
using namespace std;
int dp[10][10];
int dx[8]={1,2,1,2,-2,-1,-2,-1};
int dy[8]={2,1,-2,-1,-1,2,1,-2};
int main()
{
    for(int x=0;x<=9;x++)
    for(int y=0;y<=9;y++) dp[x][y]=100;


    dp[0][0]=0;
    
    for(int x=0;x<=7;x++)
    for(int y=0;y<=7;y++)
    {
        for(int i=0;i<=7;i++)
        {
            int x0=x-dx[i];
            int y0=y-dy[i];
            if(x0>=0&&y0>=0)
            dp[x][y]=min(dp[x][y],dp[x0][y0]+1);
        }
    }
    int m,n;
    cin>>m>>n;
    cout<<dp[m][n];
}