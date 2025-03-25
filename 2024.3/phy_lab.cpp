#include<iostream>
#include<cmath>
using namespace std;
double a[40];
double ans[40];
int main()
{
    for(int i=1;i<=37;i++)
    {
    cin>>a[i];
    ans[i]=sqrt((1.49*0.265)/(1.49+0.265-a[i]));

    }
    for(int i=1;i<=37;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}