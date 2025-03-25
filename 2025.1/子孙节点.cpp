#include<iostream>
#include<vector>
using namespace std;
char a[30];
vector<char> children;
void dfs(int index,int n)
{
    if(index>=n||a[index]=='#') return;
    int left=2*index+1;
    if(left<n&&a[left]!='#')
    {
        dfs(left,n);
        children.push_back(a[left]);
    } 

    int right=2*index+2;
    if(right<n&&a[right]!='#')
    {
        dfs(right,n);
        children.push_back(a[right]);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    char k;
    cin>>k;
    int index;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
        {
           flag=1; 
           index=i;
        } 
    }
    if(flag==0)
    {
        cout<<"No such Node";
        return 0;
    } 

    dfs(index,n);
    
    if(children.empty())
    {
        cout<<"No children";
        return 0;
    }
    
    for(auto c:children)
    {
        if(c!='#') cout<<c<<" ";
    }
    return 0;
}