#include<iostream>
using namespace std;
const double PI=3.14159;
class Shape
{
    public:
        virtual double getArea()=0;
        virtual double getPerime()=0;
};
class Rectangle:public Shape
{
    public:
        Rectangle(const double &w,const double &h):width(w),height(h){};

        double getArea() {return width*height;}
        double getPerime() {return (width+height)*2;}
    private:
        double width;
        double height;

};
class Circle:public Shape
{
    public:
        Circle(double r):radius(r){};
        double getArea() {return radius*radius*PI;}
        double getPerime() {return radius*2*PI;}

    private:
        double radius;

};
int main()
{
    Shape *ptr;
    ptr=new Rectangle(3,4);//Rectangle a(3,4)
    cout<<ptr->getArea()<<endl;//cout<<a.getArea()<<endl;
    cout<<ptr->getPerime()<<endl;    //cout<<a.getPerime()<<endl;
    delete ptr;
    
    ptr=new Circle(2);    //Circle b(2);
    cout<<ptr->getArea()<<endl;    //cout<<b.getArea()<<endl;
    cout<<ptr->getPerime()<<endl;    //cout<<b.getPerime()<<endl;

    return 0;
}