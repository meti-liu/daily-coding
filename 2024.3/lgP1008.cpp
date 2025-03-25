#include<iostream>
using namespace std;

bool f(int n,int a[])
{


    a[1]=n%10;
    a[2]=(n/10)%10;
    a[3]=n/100;
    a[4]=(2*n)%10;
    a[5]=((2*n)/10)%10;
    a[6]=(2*n)/100;
    a[7]=(3*n)%10;
    a[8]=((3*n)/10)%10;
    a[9]=(3*n)/100;
    int time=1;
    int sum=0;
    for(int i=1;i<=9;i++)
    {

        sum+=a[i];
        time*=a[i];
    }
    if(sum==45&&time==1*2*3*4*5*6*7*8*9) return true;
    else return false;
}
    int main()
    {
        int a[10];
        for(int i=100;i<=333;i++)
        {
            if(f(i,a)) cout<<a[3]<<a[2]<<a[1]<<" "<<a[6]<<a[5]
            <<a[4]<<" "<<a[9]<<a[8]<<a[7]<<endl;
        }
        return 0;
    }


