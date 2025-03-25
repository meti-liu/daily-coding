#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int a[100000];
int b[100000000];
void Sort(int a[],int begin,int end)
{     
    for(int i=begin;i<=end;i++)
    for(int j=i;j<=end;j++)
    if(a[i]>a[j])
    {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
int main()
{
    ifstream ifs("in.txt");
    int n;
    ifs>>n;
    for(int i=1;i<=n;i++) ifs>>a[i];
    int index=1;
    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    {
        b[index]=abs(a[i]-a[j]);
        index++;
    }
    index--;
    Sort(b,1,index);
    //for(int i=1;i<=index;i++) cout<<b[i]<<" ";
    int t;
    if(index%2==0) t=index/2;
    else t=index/2+1;
    cout<<b[t];
    return 0;
}