#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums,int left,int right)
    {
        int i=left;
        int p=nums[right];
        for(int j=left;j<right;j++)
        {
            if(nums[j]<p)
            {
                swap(nums[i],nums[j]);
                i++;
            } 
        }
        swap(nums[right],nums[i]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k)
    {
        int len=nums.size();
        int target=len-k;

        int left=0;
        int right=len-1;
        while(left<=right)
        {
            int pivotIndex=partition(nums,left,right);
            if(pivotIndex==target) return nums[pivotIndex];
            else if(pivotIndex<target) left=pivotIndex+1;
            else right=pivotIndex-1;
        }
    }
};