// #include<iostream>
// using namespace std;
// class teacher;
// class student
// {
//     char *name;
// public:
//     student(char *s){name=s;}
//     friend void print(student&a,teacher &b);
// };
// class teacher
// {
//     char *name;
// public:
//     teacher(char*s){name=s;}
//     friend void print(student&a,teacher &b);
// };
// void print(student &a,teacher &b)
// {
//     cout<<a.name<<endl;
//     cout<<b.name<<endl;
// }
// int main()
// {
//     student s("Bill Gates");
//     teacher t("Beckham");
//     print(s,t);
// }
#include<iostream>
using namespace std;

class teacher; // 前向声明

class student {
    char *name;
public:
    student(char *s) : name(s) {}
    friend void print(student &a, teacher &b); // print声明为友元函数
};

class teacher {
    char *name;
public:
    teacher(char *s) : name(s) {}
    friend void print(student &a, teacher &b); // print声明为友元函数
};

void print(student &a, teacher &b) {
    cout << a.name << endl;
    cout << b.name << endl;
}

int main() { // 修改为int返回类型
    student s("Bill Gates");
    teacher t("Beckham");
    print(s, t);
    return 0; // 返回0
}
