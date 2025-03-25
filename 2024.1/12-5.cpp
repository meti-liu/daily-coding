#include<iostream>
#include<new>//bad_alloc
using namespace std;
int main()
{
    int *a;
    try
    {
        a=new int[1000000000000];
    }
    catch(const bad_alloc& e)
    {
        cout<<"wrong:"<<e.what()<<endl;
    }
    
    
    return 0;
}