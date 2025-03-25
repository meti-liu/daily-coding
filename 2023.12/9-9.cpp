#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> stack1;//我们采用标准库中的stack时不需要进行大小限制
    stack<int> stack2;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack2.push(1);
    stack2.push(2);
    stack2.push(4);
    if(stack1==stack2) cout<<"stack1==stack2"<<endl;
    else cout<<"stack1!=stack2"<<endl;
    if(stack1>stack2) cout<<"stack1>stack2"<<endl;
    else cout<<"stack1<stack2"<<endl;
}