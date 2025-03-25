#include<iostream>
using namespace std;

void Proportion(int a[],int n,float &t9,float &t8,float &t7,float &t6,float &t5)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]<=59) t5++;
        else if(a[i]>=60&&a[i]<=69) t6++;
        else if(a[i]>=70&&a[i]<=79) t7++;
        else if(a[i]>=80&&a[i]<=89) t8++;
        else if(a[i]>=90&&a[i]<=100) t9++;
    }
        t6/=n;
        t5/=n;
        t7/=n;
        t8/=n;
        t9/=n;
}
int main()
{
    int score[10]={78,100,65,49,92,72,85,99,88,91};
    float t9,t8,t7,t6,t5;
    Proportion(score,10,t9,t8,t7,t6,t5);
    cout<<t5<<endl;
    cout<<t6<<endl;
    cout<<t7<<endl;
    cout<<t8<<endl;
    cout<<t9<<endl;

    return 0;
}