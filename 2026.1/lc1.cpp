#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution 
{
public:


    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> hashMap;
        vector<int> result;

        for(int i=0;i<nums.size();i++)
        {
            int next=target-nums[i];
            if(hashMap.find(next)!=hashMap.end())
            {
                result.push_back(hashMap[next]);
                result.push_back(i);
                return result;
            }
            else hashMap[nums[i]]=i;
        }
        return;
    }
};