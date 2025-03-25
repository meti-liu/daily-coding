#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n=temperatures.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(temperatures[j]>temperatures[i])
                {
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int>temperatures={73,74,75,71,69,72,76,73};
    Solution sol;
    vector<int>b=sol.dailyTemperatures(temperatures);
    for(int i:b) cout<<i<<" "<<endl;
    return 0;
}