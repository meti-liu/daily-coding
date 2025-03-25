#include <iostream>
using namespace std;
class BaseClass {
public:
    virtual void fn1() {
        cout << "BaseClass::fn1()" << endl;
    }

    void fn2() {
        cout << "BaseClass::fn2()" << endl;
    }
};

class DerivedClass : public BaseClass {
public:
    void fn1() override {
        cout << "DerivedClass::fn1()" << endl;
    }

    void fn2() {
        cout << "DerivedClass::fn2()" << endl;
    }
};

int main() {
    DerivedClass derivedObj;

    // 用BaseClass的指针指向DerivedClass的对象
    BaseClass* basePtr = &derivedObj;
    basePtr->fn1();  // 调用虚函数，输出 "DerivedClass::fn1()"
    basePtr->fn2();  // 调用非虚函数，输出 "BaseClass::fn2()"

    // 用DerivedClass的指针指向DerivedClass的对象
    DerivedClass* derivedPtr = &derivedObj;
    derivedPtr->fn1();  // 调用重写的虚函数，输出 "DerivedClass::fn1()"
    derivedPtr->fn2();  // 调用非虚函数，输出 "DerivedClass::fn2()"

    return 0;
}
