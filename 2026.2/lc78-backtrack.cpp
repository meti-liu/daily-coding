#include<vector>
#include<iostream>
using namespace std;

class Solution 
{
public:

    void backtrack(vector<int>& nums,int index,vector<int>& current,vector<vector<int>>& result)
    {
        if(index==nums.size())
        {
            result.push_back(current);
            return;
        } 
        current.push_back(nums[index]);
        backtrack(nums,index+1,current,result);
        current.pop_back();
        backtrack(nums,index+1,current,result);

    }


    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> current;
        vector<vector<int>> result;
        backtrack(nums,0,current,result);
        return result;
    }
};