#include<iostream>
using namespace std;
template<typename T>
void Sort(T a[],int n)
{
    for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
    {
        if(a[i]>=a[j]) swap(a[i],a[j]);
    }
}
void mergeArray(float a[],int lenA,float b[],int lenB,float c[])
{
    for(int i=0;i<lenA;i++) c[i]=a[i];
    for(int i=lenA;i<lenA+lenB;i++) c[i]=b[i-lenA];
    Sort(c,lenA+lenB);
}
int main()
{
    float a[5]={5.4,6.7,7.7,9.2,10};
    float b[4]={3.4,5.4,8.7,9.9};
    float c[9];
    mergeArray(a,5,b,4,c);
    for(int i=0;i<9;i++) cout<<c[i]<<" ";
}