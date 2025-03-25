#include<iostream>
using namespace std;
char a[1005];
void sort(char a[],int n)
{
    for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
    {
        if(a[i]>a[j]) swap(a[i],a[j]);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";   
}