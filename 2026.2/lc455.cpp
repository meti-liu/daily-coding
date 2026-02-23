#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child=g.size()-1;
        int cookie=s.size()-1;
        while(child>=0&&cookie>=0)
        {
            if(s[cookie]>=g[child])
            {
                ans++;
                child--;
                cookie--;
            }
            else
            {
                child--;
            }
        }
        return ans;

    }
};