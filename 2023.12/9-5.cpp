#include<iostream>
#include<list>
using namespace std;
int main()
{

    list<int> a,b;
    for(int i=1;i<=5;i++)
    {
        int temp;
        cin>>temp;
        b.push_back(temp);
    }


    for(int i=1;i<=5;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }

    
    a.insert(a.end(),b.begin(),b.end());
    for(int n:a)
    {
        cout<<n<<" ";
    }
    return 0;
}