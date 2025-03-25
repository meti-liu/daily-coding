#include<iostream>
#include<algorithm>
using namespace std;
int dp[101][1001];
int w[101];
int v[101];
int main()
{
    int n,ca;
    cin>>n>>ca;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];

    for(int i=1;i<=n;i++)
    for(int j=1;j<=ca;j++)//背包逐渐增大,初始容量要比新物体大
    {
        if(j<w[i]) dp[i][j]=dp[i-1][j];
        else   dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
    }

    cout<<dp[n][ca];
    return 0;
}