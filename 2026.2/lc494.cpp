#include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        if((sum+target)%2==1) return 0;
        else
        {
            if (abs(target)>sum) return 0;
            int left=(sum+target)/2;
            vector<int> dp(left+1,0);
            dp[0]=1;
            for(int i=0;i<n;i++)
            for(int j=left;j>=nums[i];j--)
            {
                dp[j]+=dp[j-nums[i]];
            }
            return dp[left];
        }
    }
};