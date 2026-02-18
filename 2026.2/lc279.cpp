#include<vector>
#include<iostream>
using namespace std;

class Solution 
{
public:
    int numSquares(int n) 
    {
        vector<int> nums;
        for(int i=1;i*i<=n;i++) nums.push_back(i*i);
        vector<int> dp(n+1,n+1);
        dp[0]=0;
        int size=nums.size();
        for(int i=0;i<size;i++)
        for(int j=nums[i];j<=n;j++)
        {
            dp[j]=min(dp[j],dp[j-nums[i]]+1);
        }
        return dp[n];
    }
};