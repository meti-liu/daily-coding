#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res=INT_MIN;
        int sum=0;
        int i=0;
        while(i<nums.size())
        {
            sum+=nums[i];
            res=max(sum,res);
            if(sum<0)
            {
                sum=0;
            }

            i++;
        }

        return res;
    }
};