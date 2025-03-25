#include<iostream>
using namespace std;
void selectSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[j]<a[i]) swap(a[i],a[j]);
        }
        for(int k=0;k<n;k++) cout<<a[k]<<" ";
        cout<<endl;
    }
}
int main()
{
    int a[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
    int n=sizeof(a)/sizeof(a[0]);
    selectSort(a,n);
    return 0;
}