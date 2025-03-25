#include <iostream>
using namespace std;
class Mammal 
{
public:
    virtual void speak() 
    {
        cout<< "Mammal speaks" <<endl;
    }
};

class Dog : public Mammal 
{
public:
    void speak() //override 覆盖
    {
        std::cout << "Dog barks" <<endl;
    }
};

int main()
{
    Dog myDog;
    myDog.speak();  // 通过Dog类对象调用speak函数

    return 0;
}
