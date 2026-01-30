#include<iostream>
#include<string>
using namespace std;
class Solution 
{
public:
    int nextGreaterElement(int n) 
    {
        string a=to_string(n);
        int l=a.size();
        int i=l-1;
        int j=l-1;
        for(i=l-1;i>=1;i--)
        {
            if(a[i]<=a[i-1]) continue;
            else break;
        }
        if(i==0) return -1;

        for(j=l-1;j>=0;j--)
        {
            if(a[j]<=a[i-1]) continue;
            else break;
        }
        

        swap(a[i-1],a[j]);
        reverse(a.begin()+i,a.end());
        long long ans=stoll(a);
        if(ans>INT_MAX) return -1;
        return (int)ans;


        return -1;
    }
};