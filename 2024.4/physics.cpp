#include<iostream>
using namespace std;
double a[10],b[10];
int main()
{
    double sum=0;
    double l=37005;
    for(int i=1;i<=16;i++)
    {
        cin>>a[i];
        b[i]=(abs(a[i]-l))*(abs(a[i]-l));
        sum+=b[i];
    }
    sum=sum/15;
    cout<<sum<<endl;
}