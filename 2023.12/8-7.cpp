#include<iostream>
using namespace std;
class Point
{
    public: 
        Point(const double &x,const double &y):x(x),y(y){};
        Point operator+(Point c2);
        Point operator++();//前置++
        Point operator++(int);//后置++
        Point operator-(Point c2);
        Point operator--();//前置--
        Point operator--(int);//后置--
        void display();


    private:
        double x;
        double y;
};
Point Point::operator+(Point c2)
{
    //return Point(x+c2.x,y+c2.y);
    x+=c2.x;
    y+=c2.y;
    return *this;
}
Point Point::operator++()
{
    x++;
    y++;
    return *this;
}
Point Point::operator++(int)
{
    Point c=*this;
    ++(*this);
    return c;
}

Point Point::operator-(Point c2)
{
    //return Point(x+c2.x,y+c2.y);
    x-=c2.x;
    y-=c2.y;
    return *this;
}
Point Point::operator--()
{
    x--;
    y--;
    return *this;
}
Point Point::operator--(int)
{
    Point c=*this;
    --(*this);
    return c;
}
void Point::display()
{
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
}
int main()
{
    Point a(2,3);
    Point b(4,5);
    Point c=a+b;
    c.display();
    c++;
    c.display();
    ++c;
    c.display();
    c--;
    c.display();
    --c;
    c.display();
    return 0;
}