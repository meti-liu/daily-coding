#include <iostream>
using namespace std;
template<typename T>
void Swap(T& a,T& b)
{
    T temp=a;
    a=b;
    b=temp;
}
int main()
{
    int x=2,y=3;
    double m=2.1,n=3.1;
    Swap(x,y);
    Swap(m,n);
    cout<<x<<y<<m<<n;
    return 0;
}