#include<iostream>
using namespace std;
void bubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        for(int k=0;k<n;k++) cout<<a[k]<<" ";
        cout<<endl;
    }

}
int main()
{
    int a[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
    int n=sizeof(a)/sizeof(a[0]);
    bubbleSort(a,n);
    return 0;
}