#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {

        int t=0;
        int n=nums.size();
        vector<int> a(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                a[t]=0;
                t++;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                a[t]=nums[i];
                t++;
            }
        }
        return;
    }
};