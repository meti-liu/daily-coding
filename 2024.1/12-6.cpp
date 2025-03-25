#include<iostream>
#include<stdexcept>
using namespace std;
class CException
{
public:
    void Reason()
    {
        cout<<"CException happened"<<endl;
    }
};
void fn1()
{
    throw CException();
}
int main()
{
    try
    {
        if(true) fn1();//括号内可以换成实际报错条件 
    }
    catch(CException &a)
    {
        a.Reason();
    } 
    return 0;
}