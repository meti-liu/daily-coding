#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        stack<int> st;
        int water=0;

        for(int i=0;i<height.size();i++)
        {
            while(!st.empty()&&height[i]>height[st.top()])
            {
                int mid=st.top();
                st.pop();
                if(st.empty()) break;//no left

                int left=st.top();
                int right=i;
                
                int H=min(height[left],height[right])-height[mid];
                int W=right-left-1;
                water+=H*W;
            }
            st.push(i);
        }
        return water;
    }
};