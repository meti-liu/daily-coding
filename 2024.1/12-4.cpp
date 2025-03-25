#include<iostream>
#include<stdexcept>
using namespace std;
class Exception
{
public:
    virtual void handle()const=0;
};

class OutOfMemory:public Exception
{
public:
    void handle()const override
    {
        cerr<<"fail because out of memory"<<endl;
    }
};

class RangeError:public Exception
{
public:
    void handle() const override
    {
        cerr<<"fail because of range error"<<endl;
    }
};

int main()
{
    int *a=nullptr;
    cout<<"input a num from 0-99"<<endl;
    int n;
    cin>>n;
    //第一个try-catch块
    try
    {
        if(n<0||n>99) throw RangeError();
    }
    catch(const Exception& e)//也可以把exception改成oom或re
    {
        e.handle();//会根据实际的throw来调用不同的handle
    }


    //第二个try-catch块,内部还嵌套了一个try-catch块
    try
    {
        try
        {
            a=new int[10000000000000];
        }
        catch(const bad_alloc &e)
        {
            throw OutOfMemory();
        }
    }
    catch(const Exception& e)//也可以把exception改成oom或re
    {
        e.handle();//会根据实际的throw来调用不同的handle
    }
   return 0;
}