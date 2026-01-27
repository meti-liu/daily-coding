#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<int> line;
        vector<vector<int>> ans;
        int dp[32][32]={0};
        for(int i=1;i<=numRows;i++)
        {
            dp[i][1]=1;
            dp[i][i]=1;
        }

        for(int i=1;i<=numRows;i++)
        for(int j=1;j<=i-1;j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }

        for(int i=1;i<=numRows;i++)
        {
            for(int j=1;j<=i;j++) line.push_back(dp[i][j]);
            ans.push_back(line);
            line.clear();
        }

        return ans;
    }
};