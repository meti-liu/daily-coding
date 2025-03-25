#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void simplify(int &a,int &b)
{
    int g=gcd(a,b);
    a=a/g;
    b=b/g;
}

class fraction//两个重载，一个化简分式的函数
{
private:
    int z,m;//分子，分母
public:
    fraction(int a,int b):z(a),m(b){}
    fraction operator+(fraction k)
    {
        int z1=z*k.m+m*k.z;
        int m1=m*k.m;
        simplify(z1,m1);
        return fraction(z1,m1);
    }
    fraction operator*(fraction k)
    {
        int z1=z*k.z;
        int m1=m*k.m;
        simplify(z1,m1);
        return fraction(z1,m1);
    }
    void display()
    {
        cout<<z<<"/"<<m<<endl;
    }
};
int main()
{
    fraction f1(3,4);
    fraction f2(2,3);
    fraction f3=f1+f2;
    fraction f4=f1*f2;
    f3.display();
    f4.display();
    f1.display();
    f2.display();
    return 0;
}