#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i=0;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) continue;
            else
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};

int main()
{

}