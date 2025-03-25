#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    float total=0;
    cin>>n;
    vector<float>a(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        total+=a[i];
    }
    float average=total/n;
    cout<<average<<endl;
    return 0;
}