#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:

    int maxProfit(vector<int>& prices) 
    {
        int buy=prices[0];
        int mp=0;

        for(int i=1;i<prices.size();i++)
        {
            int sell=prices[i];
            buy=min(buy,prices[i-1]);
            int profit=sell-buy;
            mp=max(mp,profit);
        }

        return mp;


    }
};

int main()
{

}