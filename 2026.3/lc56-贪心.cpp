#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> emerged;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        if(n==1) return intervals;
        emerged.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            int m=emerged.size();
            if(intervals[i][0]<=emerged[m-1][1]) emerged[m-1][1]=max(intervals[i][1],emerged[m-1][1]);
            else emerged.push_back(intervals[i]);
        }
        return emerged;
    }
};