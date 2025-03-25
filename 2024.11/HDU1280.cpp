#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

int a[3050];
int b[100000];


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
    int n,m;
    ifs>>n>>m;
    for(int i=1;i<=n;i++) ifs>>a[i];
    int index=1;
    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    {
        b[index]=a[i]+a[j];
        index++;
    }
    //index--;
    Sort(b,1,index);
    //sort(b+1,b+index+1);
    //for(int i=1;i<=index;i++) cout<<b[i]<<" ";
    //cout<<endl;
    for(int i=index;i>=index-m+1;i--) cout<<b[i]<<" ";
    return 0;
}