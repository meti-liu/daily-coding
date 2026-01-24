#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public: 
    vector<vector<int>> result;

    void backtracking(const vector<int> &nums,vector<bool> &visited,vector<int> &path)
    {
        if(path.size()==nums.size())
        {
            result.push_back(path);
            return;//stop recuirting
        } 

        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]) continue;//decrease time complexity
            if(visited[i]==false)
            {
                path.push_back(nums[i]);
                visited[i]=true;

                backtracking(nums,visited,path);

                path.pop_back();
                visited[i]=false;
            }
             

        }


    }


    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool> visited(nums.size(),false);
        vector<int> path;
        backtracking(nums,visited,path);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums={1,2,3};
}