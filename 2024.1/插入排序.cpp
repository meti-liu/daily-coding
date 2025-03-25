#include<iostream>
using namespace std;
void insertSort(int a[],int n)
{
    int i,j;
    int key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        for(int k=0;k<n;k++) cout<<a[k]<<" ";
        cout<<endl;
    }

 }
int main()
{
    int a[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
    int n=sizeof(a)/sizeof(a[0]);
    insertSort(a,n);
}