#include<iostream>
#include<cmath>
using namespace std;
int a[50];
class Solution 
{
public:
    int bitwiseComplement(int n) 
    {
        if(n==0) return 1;
        else
        {
            int i=0;
            while(n>0)//=?0
            {
                int temp=n/2;
                a[i]=n-2*temp;
                n=temp;
                i++;
            }
            // for(int j=0;j<i;j++)
            // {
            //     swap(a[j],a[i-j-1]);
            // }
            for(int j=0;j<i;j++)
            {
                if(a[j]==0) a[j]=1;
                else a[j]=0;
            }
            int sum=0;
            for(int j=0;j<i;j++) sum+=a[j]*pow(2,j);
            return sum;
        }
    }
};

int main()
{
    Solution a;
    int n;
    cin>>n;
    cout<<a.bitwiseComplement(n);
    return 0;
}

