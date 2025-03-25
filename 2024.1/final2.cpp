#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Number
{
private:
    int Num;
    int *iBuf;
public:
    Number(int Num)
    {
        this->Num=Num;
        iBuf=new int[2*Num];
        for(int i=1;i<=Num;i++)
        {
            CreateNum(i);
            DispNum(i);
        }
    }
    void CreateNum(int iLine)
    {
        for(int i=0;i<iLine;i++)
        {
            int Num1=(i==0||i==iLine-1?1:iBuf[i-1]+iBuf[i]);
            *(iBuf+this->Num+i)=Num1;
        }
        memcpy(iBuf,iBuf+this->Num,this->Num*sizeof(int));

    }
    void DispNum(int iLine)
    {
        cout<<setw(40-iLine*2)<<" ";
        for(int i=0;i<iLine;i++)
        {
            cout<<setw(4)<<*(iBuf+i);
        }
        cout<<endl;
    }
    ~Number()
    {
        delete []iBuf;
    }
};
int main()
{
    Number *obj=new Number(6);
    delete obj;
    return 0;   
}