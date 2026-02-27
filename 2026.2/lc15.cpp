#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int left;
        int right;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) break;
            else
            {
                if(i>0 && nums[i]==nums[i-1]) continue;
                else
                {
                    left=i+1;
                    right=nums.size()-1;
                    while(left<right)
                    {
                        int sum=nums[i]+nums[left]+nums[right];
                        if(sum==0)
                        {
                            result.push_back({nums[i],nums[left],nums[right]});
                            while(left<right&&nums[left]==nums[left+1]) left++;
                            while(left<right&&nums[right]==nums[right-1]) right--;
                            left++;
                            right--;
                        }
                        else if(sum>0) right--;
                        else left++;
                        
                    }
                }
            }
        }

        return result;
    }
};