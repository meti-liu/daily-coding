#include<vector>
#include<iostream>
using namespace std;
class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int n=nums.size();
        int target=0;
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2==1) return false;
        else target=sum/2;

        vector<int> dp(target+1,0);
        for(int i=0;i<n;i++)
        for(int j=target;j>=nums[i];j--)
        {
            dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
        }
        if(dp[target]==target) return true;
        else return false;
    }
};