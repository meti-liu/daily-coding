#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int i=0;
        int j=height.size()-1;
        int res=0;
        while(i<j)
        {
            int h=min(height[i],height[j]);
            int w=j-i;
            res=max(res,w*h);
            if(height[i]>height[j]) j--;
            else i++;
        }
        return res;
        
    }
};